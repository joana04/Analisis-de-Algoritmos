#include <stdio.h>
#include <stdlib.h>
long long double *x;
long long double* y;

 void main(int argc, char const *argv[])
 {
 	long long double estrellas;

 	scanf("%lld", &estrellas);

 	x=(long long double *)malloc(estrellas*sizeof(long long double));
 	y=(long long double *)malloc(estrellas*sizeof(long long double));

 	
 	for(int i=0; i< estrellas; i++){
 		scanf("%lld", &x[i]);
 		scanf("%lld", &y[i]);
 	}
 	
 	
 	for(int i=0; i< estrellas; i++){
 		printf ("%lld,", &x[i]);
 		printf ("%lld\n", &y[i]);
 	}



 	return 0;
 }

