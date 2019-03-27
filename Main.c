#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int minimo(int,int); 
int mifuncion(int**matriz, int, int, int, int, int);
int FILAS,COLUMNAS;
int** vistados;

void main(){
	
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
	int suma=miFuncion(matriz,0,0,FILAS, COLUMNAS, 0);
	printf("%d\n",suma);
}

int miFuncion(int** matriz, int x, int y, int filas, int columnas, int suma){
	if(x==filas-1 && y==columnas-1){
		//printf("1--%d %d, %d \n", x,y,matriz[x][y]);
		if(vistados[x][y]!=-1){
			return suma+vistados[x][y];
		}else{
			vistados[x][y]=matriz[x][y];
		}
		return suma+matriz[x][y];
	}
	if(x<filas-1 && y<columnas-1){
		//printf("1--%d %d, %d\n", x,y,matriz[x][y]);
		if(vistados[x][y]!=-1){
			return suma+vistados[x][y];
		}else{
			vistados[x][y]=matriz[x][y]+minimo(miFuncion(matriz,x+1,y, filas, columnas, suma),miFuncion(matriz,x,y+1, filas, columnas, suma));
		}
		return suma+vistados[x][y];
	}
	if(x<filas-1 && y==columnas-1){
		//printf("1--%d %d, %d\n", x,y,matriz[x][y]);
		if(vistados[x][y]!=-1){
			return suma+vistados[x][y];
		}else{
		vistados[x][y]=matriz[x][y]+miFuncion(matriz,x+1,y, filas, columnas, suma);
	}
		return suma+vistados[x][y];
	}
	if(x==filas-1 && y<columnas-1){
		//printf("1--%d %d, %d\n", x,y,matriz[x][y]);
		if(vistados[x][y]!=-1){
			return suma+vistados[x][y];
		}else{
		vistados[x][y]=suma+matriz[x][y]+miFuncion(matriz,x,y+1,filas, columnas, suma);
	}
		return suma+vistados[x][y];
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