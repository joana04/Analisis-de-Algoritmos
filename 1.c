#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
long long  sumaMax(int inicio, int fin, int *numeros);
long long Maximo(long long derecha, long long izquierda, long long centro);

int *numeros;
int n;
void main(int argc, char const *argv[])
{
	scanf("%d",&n);
	numeros=(int*) malloc(n*sizeof(int));
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &numeros[i]);
	}
	printf("%lld\n",sumaMax(0,n-1,numeros));
	exit(0);
}

long long sumaMax (int inicio, int fin,int  *numeros){
	long long prefijo=LLONG_MIN, sufijo=LLONG_MIN;
	int  i=0;
	if(inicio==fin)return numeros[inicio];
	int mitad=(inicio+fin)/2;
	long long izquierda=sumaMax(inicio, mitad, numeros);
	long long derecha=sumaMax(mitad+1, fin, numeros);
	long long suma=0;
	for(i=mitad; i>=inicio; i--){
		suma+=numeros[i];
		if(suma>sufijo)sufijo=suma;
	}
	suma=0;
	for(i=mitad+1; i<=fin;i++){
		suma+=numeros[i];
		if(suma>prefijo)prefijo=suma;
	}
	long long centro=sufijo+prefijo;
	return Maximo(derecha, izquierda, centro);
}

long long Maximo(long long derecha, long long izquierda, long long centro){
	if (derecha>=izquierda && derecha >=centro){
		return derecha;
	}else if (izquierda>=derecha && izquierda>= centro){
	return izquierda;
	}else {
		return centro;
	}
}