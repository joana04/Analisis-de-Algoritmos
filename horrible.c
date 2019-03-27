#include <stdio.h>
#include <stdlib.h>
struct funcion{
	long long int a;
	long long int b;
	long long int c;
};
void Ordenar(long long int *valores,long long int*pos, long long int N);

int main(){
	long long int n=0,m=0, k=0, necesito=0;
	scanf("%lld",&n);
	scanf("%lld",&m);
	scanf("%lld",&k);
	struct funcion* ecu= ( struct funcion*) malloc(n*sizeof(struct funcion));
	long long int* valores=(long long int*) malloc(m*sizeof(long long int));
	long long int* pos=(long long int*) malloc(m*sizeof(long long int));
	for(long long int j=0; j<n;j++){
		scanf("%lld", &ecu[j].a);
		scanf("%lld", &ecu[j].b);
		scanf("%lld", &ecu[j].c);
	}
	for(long long int i=0; i<m ;i++){
		scanf("%lld", &valores[i]);
		pos[i]=i+1;	
	}
	Ordenar(valores, pos, m);
	necesito=m-k;
	for(long long int l=necesito;l<m ;l++){
		printf("%lld ",pos[l]);
	}
	return 0;
}
void Ordenar(long long int *valores,long long int* pos, long long int N){
    long long int k = N/2;
    long long int i,j;
    long long int v, vv ;
    while(k>=1){
        for( i=k ; i<N ;i++){
            v = valores[i];
            vv=pos[i];
            j = i - k;
            while(j>=0 && valores[j]> v){
                valores[j+k] = valores[j];
                pos[j+k]=pos[j];
                j-=k;
            }
            valores[j+k]=v;
            pos[j+k]=vv;
        }
        k/=2;
    }
}
