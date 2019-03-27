#include <stdio.h>
#include <stdlib.h>
int valorMaximo(int* pesos,int* valores,int tam,int n);
int maximo(int x,int y);
int ** visitados;
int main(){
	int n=0,s=0;
	scanf("%d",&s);
	scanf("%d",&n);
	int* valores=(int*) malloc(n*sizeof(int));
	int* pesos=(int*) malloc(n*sizeof(int));
	visitados=(int**)malloc((n+1)*sizeof(int*));
	for(int i=0; i<=n;i++){
		visitados[i]=(int*)malloc((s+1)*sizeof(int));
		for(int k=0; k<=s;k++){
			visitados[i][k]=-1;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &pesos[i]);
		scanf("%d", &valores[i]);
	}
	//shell(valores,pesos,n);
	printf("%d\n",valorMaximo1(pesos,valores,s,n));
	
	return 0;
}


int valorMaximo1(int* pesos,int* valores,int tam,int n){
	int peso=0 , art=0;
	//for(int i=0; i<=n;i++){
	while(art<=n){
	//for (int t=0; t<=tam;t++){
		peso=0;
		while(peso<=tam){
			if(art==0||peso==0) {
				visitados[art][peso]=0;
				printf("AQUI 1------- art %d peso %d \n", art, peso);
			}else if (pesos[art-1]<=peso) {
				visitados[art][peso]=maximo(valores[art-1]+visitados[art-1][peso-pesos[art-1]], visitados[art-1][peso]);
				printf("AQUI 2------- art %d peso %d -----visitados %d\n", art, peso, visitados[art][peso]);
			}else{
			 	visitados[art][peso]=visitados[art-1][peso];
			 	printf("AQUI 3------- visitados %d -----visitados %d ====\n",  visitados[art][peso],visitados[art-1][peso]);
			}
			peso++;
		}
		printf("------------------Incremento---------");
		art++;
	}
	
	return visitados[n][tam];
}

int maximo(int x,int y){
	if(x==y){
		return x;
	}else if(x>y){
		return x;
	}else{
		return y;
	}
}

