#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(int argc, char const *argv[])
{
	int n, k, pos;
	scanf("%d",&n);
	scanf("%d",&k);
	int arreglo[n];

	if(n<=k) printf("-1");
	else if(k==n-1){
		pos=0;
		while(pos<n){
			arreglo[pos]=pos+1;
			pos++;
		}
		for(int i=0; i<n;i++){
			printf("%d ", arreglo[i]);
		}

	}
	else {
		arreglo[0]=k+2;
		pos=1;
		while(pos<k+1){
			arreglo[pos]=pos+1;
			pos++;
		}
		while(pos<n-1){
			arreglo[pos]=pos+2;
			pos++;
		}
		arreglo[pos]=1;
		for(int i=0; i<n;i++){
			printf("%d ", arreglo[i]);
		}
	}
	
	exit(0);
}