#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int maximo1(int,int);
int maximo(int,int,int); 
int miFuncion(int**matriz, int, int, int, int, int);
int FILAS,COLUMNAS;
int** vistados;
int* resultados;

int main(){
	int casos=0,z=0;
	scanf("%d",&casos);
	resultados=malloc(casos*sizeof(int));
	while(z<casos){
	scanf("%d",&FILAS);
	scanf("%d",&COLUMNAS);
	vistados=(int**)malloc(FILAS*sizeof(int*));
	int** matriz=(int**)malloc(FILAS*sizeof(int*));
	for(int i=0;i<FILAS;i++){
			matriz[i]=(int*)malloc(COLUMNAS*sizeof(int));
			vistados[i]=(int*)malloc(COLUMNAS*sizeof(int));
	}
	for(int i=0;i<FILAS;i++){
		//printf("Guardar\n");
		for(int j=0;j<COLUMNAS;j++){
			scanf("%d", &matriz[i][j]);
			vistados[i][j]=-1;
		}
		//printf("\n");
	}
	int sumaFinal=0;
	int l=0;
	while(l<COLUMNAS){
		int suma=miFuncion(matriz,0,l,FILAS, COLUMNAS, 0);
		l++;
		sumaFinal=maximo1(sumaFinal,suma);

	}
	printf("%d\n",sumaFinal);
	z++;
	}
	return 0;
	
}

int miFuncion(int** matriz, int x, int y, int filas, int columnas, int suma){
	if(x<filas-1 && y==0){
		//printf("1--%d %d, %d\n", x,y,matriz[x][y]);
		if(vistados[x][y]!=-1){
			return suma+vistados[x][y];
		}else{
			vistados[x][y]=suma+matriz[x][y]+maximo1(miFuncion(matriz,x+1,y,filas, columnas, suma),miFuncion(matriz,x+1,y+1,filas, columnas, suma));
		}
		return suma+vistados[x][y];
	}
	if(x<filas-1 && y==columnas-1){
		//printf("1--%d %d, %d\n", x,y,matriz[x][y]);
		if(vistados[x][y]!=-1){
			return suma+vistados[x][y];
		}else{
			vistados[x][y]=suma+matriz[x][y]+maximo1(miFuncion(matriz,x+1,y,filas, columnas, suma),miFuncion(matriz,x+1,y-1,filas, columnas, suma));
		}
		return suma+vistados[x][y];
	}
	if(x<filas-1 && y<columnas-1){
		//printf("1--%d %d, %d\n", x,y,matriz[x][y]);
		if(vistados[x][y]!=-1){
			return suma+vistados[x][y];
		}else{
			vistados[x][y]=matriz[x][y]+maximo(miFuncion(matriz,x+1,y-1, filas, columnas, suma),miFuncion(matriz,x+1,y, filas, columnas, suma),miFuncion(matriz,x+1,y+1, filas, columnas, suma));
		}
		return suma+vistados[x][y];
	}
	if(x==filas-1){
		return suma+matriz[x][y];
	}
}


int maximo1(int x,int y){
	if(x==y){
		return x;
	}else if(x>y){
		return x;
	}else{
		return y;
	}
}

int maximo(int x,int y, int z){
	int max1=maximo1(x,y);
	int max2=maximo1(y,z);
	int maximo=maximo1(max1,max2);
	return maximo;
}