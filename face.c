#include <stdio.h>
#include <stdlib.h>
int miFuncion( int *W , int N );
void Ordenar(int *pesos,int N);

/*
T--> dias de trabajo
N--> elementos que puede tomar
W--> peso de los elementos 
*/

int main(){
    int T , N ;
    int i , j;
    int W[100];
    scanf("%d",&T);
    int cargados[T];
    for( i=0 ; i<T ; i++ ){
        scanf("%d",&N);
        for( j=0 ; j<N ; j++ ){
            scanf("%d",&W[j]);
        }
        Ordenar( W , N );
        cargados[i] = miFuncion( W , N );
    }
    for( i=0 ; i<T ; i++ ){
        printf("Case #%d: %d \n",i+1,cargados[i]);
    }
    return 0;
}

int miFuncion( int *W , int N ){
    int i = 0;
    int articulos = N;
    int cargados = 0 , peso , articulo;
    while( i != articulos ){
        articulos--;
        peso = W[articulos];
        articulo = 1;
        while( i != articulos && (articulo*peso< 50)){
            articulo++;
            i++;
        }
        if( articulo*peso >= 50)cargados++;
    }
    return cargados;
}
void Ordenar(int *pesos,int N){
    int k = N/2;
    int i,j;
    int v ;
    while(k>=1){
        for( i=k ; i<N ;i++){
            v = pesos[i];
            j = i - k;
            while(j>=0 && pesos[j]> v){
                pesos[j+k] = pesos[j];
                j-=k;
            }
            pesos[j+k]=v;
        }
        k/=2;
    }
}
