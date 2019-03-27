#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	int n=10000000;
	int j,i,v;
	int k=n/2;
	int* numeros;
		numeros=malloc(10000000*sizeof(int));
	for(i=0;i<n;i++){
		scanf("%d",&numeros[i]);
	}
	
	while(k>=1){
		for(i=k;i<n;i++){
			v=numeros[i];
			j=i-k;
			while((j>=0)&&(numeros[j]>v)){
				numeros[j+k]=numeros[j];
				j-=k;
			}
			numeros[j+k]=v;
		}
		k/=2;
	}
	for(i=0;i<n;i++){
		printf("%d \n",numeros[i]);	
	}
	return 0;

}

