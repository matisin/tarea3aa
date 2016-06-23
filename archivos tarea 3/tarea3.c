#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <time.h>

#define L 100000
#define N 10000
#define V 200

int main(){
  int i,in,n,im;
  //reloj para medir el tiempo con distintos tamaño de n
  clock_t begin, end;
	double time_spent;//para medir el tiempo
  //semilla para generar numeros random

  FILE *resultados;
	resultados = fopen("resultados.txt", "w+");//archivo de salida de resutlados
  for(n = 1 ; n <= N ; n++){
    srand (time(NULL));
    //se define un arreglo de posiciones iniciales para las hormigas.
		int *S = (int *)malloc((n)*sizeof(int));
    //algoritmo para generar n numeros al azar en order creciente sin repetirse
    //llamado algoritmo de Knuth.
    im = 0;
    for (in = 0; in < L && im < n; ++in) {
      int rn = L - in;
      int rm = n - im;
      if (rand() % rn < rm)
      /* Take it */
      S[im++] = in + 1; /* +1 since your range begins from 1 */
    }
    begin = clock();//tiempo antes de el algoritmo
    int i=0,j=n-1,k;
    double t;
    int medio = L/2;
    while(i != j){
      k = (i+j)/2;
      if (abs(medio - S[k]) <= abs(medio - S[k+1])){
        j=k;
      }else{
        i=k+1;
      }
    }
    if(L-S[i] <= S[i]){
      t = (L-S[i])/(double)V;
    }else {
      t = S[i]/(double)V;
    }
    end = clock();
		time_spent = (double)(end - begin) / CLOCKS_PER_SEC;//tiempo despues del algoritmo
		fprintf(resultados,"%d	%lf\n",n,time_spent);
    free(S);
  }




}
