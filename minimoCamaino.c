#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int minimo(int,int); 
int FILAS=3,COLUMNAS=3;

void main(){
	int* matriz=malloc(sizeof(int)*FILAS*COLUMNAS);
	int* dp=malloc(sizeof(int)*FILAS*COLUMNAS);
	int x=0;
	for(int i=0;i<FILAS*COLUMNAS;i++){
			matriz[x]=i*7+1;
			dp[x]=-1;
			x++;
	}
	x=0;
	for(int i=0;i<FILAS;i++){
		for(int j=1;j<COLUMNAS+1;j++){
			printf("%d ",matriz[x] );
			x++;
		}
		printf("\n");
	}
	int suma=miFuncion(dp,matriz,FILAS,COLUMNAS,0,0,0,0);
	printf("%d\n",suma);
}

int miFuncion(int* dp,int* matriz, int filas, int columnas, int suma,int x,int y,int pos){
	if(x==filas-1 && y==columnas-1){
		dp[pos]=matriz[pos];
		return suma+dp[pos];
	}
	if(x<filas-1 && y<columnas-1){
		if(dp[pos]==-1){
			dp[pos]=matriz[pos]+minimo(miFuncion(dp,matriz,filas,columnas,suma,x+1,y,pos+1),miFuncion(dp,matriz,filas,columnas,suma,x,y+1,pos+columnas));
		}else{
			return suma+dp[pos];
		}
		return suma+dp[pos];
	}
	if(x<filas-1 && y==columnas-1){
		if(dp[pos]==-1){
			dp[pos]=matriz[pos]+miFuncion(dp,matriz,filas,columnas,suma,x+1,y,pos+1);
		}else{
			return suma+dp[pos];
		}
		return suma+dp[pos];
	}
	if(x==filas-1 && y<columnas-1){
		if(dp[pos]==-1){
			dp[pos]=matriz[pos]+miFuncion(dp,matriz,filas,columnas,suma,x,y+1,pos+columnas);
		}else{
			return suma+dp[pos];
		}
		return suma+dp[pos];
	}
}

int minimo(int x,int y){
	if(x==y){
		return x;
	}else if(x<y){
		return x;
	}else{
		return y;
	}
}
