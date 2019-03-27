#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float dis_Min(float*x, float*y, long int inicio, long int fin);
float distancia(float x1, float y1, float x2, float y2);
float min(float derecha, float izquierda, float centro);
float* x;
float* y;


 int main(int argc, char const *argv[])
 {
 	long int estrellas=0;
 	scanf("%ld", &estrellas);
 	x=(float *)malloc(estrellas*sizeof( float));
 	y=(float *)malloc(estrellas*sizeof( float));
 	for(int i=0; i< estrellas; i++){
 		scanf("%f", &x[i]);
 		scanf("%f", &y[i]);
 	}
	printf("%.3f",dis_Min(x,y,0,estrellas-1));
 	return 0;
 }

 float dis_Min(float*x, float*y, long int inicio, long int fin){
 	if(inicio<fin){
 		long int medio=0;
 		medio=(inicio+fin)/2;
 		float derecha=dis_Min(x,y,inicio, medio);
 		float izquierda=dis_Min(x,y, medio+1,fin);
 		float dis=0, centro=0;
 		for (long int i=medio;i>=inicio; i--){
 			for(long int j=medio+1; j<=fin;j++){
 				dis=distancia(x[i],y[i],x[j],y[j]);
 				if(((dis<=centro) | (centro==0))){
 					centro=dis;
 				}
 			}
 		}
 		return(min(derecha, izquierda, centro));
 	}
 	else {
 		return 0;
 	}
 }

float min(float derecha, float izquierda, float centro){
	if(derecha!=0 && izquierda!=0){
		if (derecha<=izquierda && derecha<=centro){
			 return derecha;
		}else if (izquierda<=derecha && izquierda<= centro){
			return izquierda;
		}else{
			return centro;
		}
	}else if(derecha!=0){
		if(derecha<=centro){
			return derecha;
		}else{
			return centro;
		}	
	}else if(izquierda!=0){
		if(izquierda<=centro){
			return izquierda;
		}else{
			return centro;
		}
	}else
		return centro;
}


float distancia(float x1, float y1, float x2, float y2){
	float distancia=0, a=0, b=0, a2=0, b2=0;
	a=x1-x2;
	b=y1-y2;
	a2=pow(a,2);
	b2=pow(b,2);
	distancia=sqrt(a2+b2);
	return distancia;
}