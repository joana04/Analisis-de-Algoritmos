#include <stdio.h>
#include <stdlib.h>
long long int mergeSort(long long int inicio, long long final, long long int **arreglo, long long int *temp);
long long int merge(long long int inicio, long long int final, long long int med,long long int **arreglos, long long int *temp );
long long int*arreglos; 
long long int *soluciones;
long long int filas, columnas;

void main(int argc, char const *argv[])
{
	
	char espacio[10];
	char *p;	
	long long int lecturas=0;
	scanf("%lld" , &filas);
	soluciones=(long long int *)malloc(filas*sizeof(long long int));
	lecturas=0;
	while(lecturas<filas){
		fflush(stdin);
		p=gets(espacio);
		scanf("%lld" , &columnas);
		arreglos=(long long int*)malloc((columnas)*sizeof(long long int));
		//arreglos [lecturas][0]=columnas;
		for (int i = 0; i < columnas; i++)
		{
			scanf("%lld", &arreglos[i]);
		}
		long long int *temp=(long long int*)malloc((columnas)*sizeof(long long int));
		soluciones[lecturas]=mergeSort(0,columnas-1,arreglos, temp);
		free(temp);
		lecturas++;
	}

	for(int i=0; i<filas; i++){
		printf("%lld \n",soluciones[i]);
	}
	
	exit(0);
}

long long int mergeSort(long long int inicio, long long final, long long int **arreglo, long long int *temp){
	long long int med, inversiones = 0;
	  if (final> inicio)
	  {
	    med = (final + inicio)/2;
	    inversiones  = mergeSort(inicio, med,  arreglos, temp);
	    inversiones += mergeSort(med+1,final,  arreglos, temp);
	 
	    inversiones+= merge(inicio, final, med+1, arreglos, temp);
	  }
	  return inversiones;
	}


long long int merge(long long int inicio, long long int final, long long int med,long long int **arreglos, long long int *temp ){
	long long int aux1, aux2, aux3, inver=0;
	aux1 = inicio; 
	aux2= inicio;
	aux3= med;  
	while ((aux1 <= med ) && (aux3 <= final))
	  {
	    if (arreglos[aux1] <= arreglos[aux3])
	    {
	      temp[aux2++] = arreglos[aux1];
	      aux1++;
	     }
	    else{
	      temp[aux2++] = arreglos[aux3];
	      aux3++;
	 	  inver = inver + (med - aux1);
	    }
	  }
	 
	  while (aux1 <= med-1){
	    temp[aux2++] = arreglos[aux1];
		aux1++;
		}
	  while (aux3 <= final){
	    temp[aux2++] = arreglos[aux3];
	    aux3++;
		}
	  for (aux1=inicio; aux1 <= final; aux1++){
	    arreglos[aux1] = temp[aux1];
		}
	 
	  return inver;
	}



