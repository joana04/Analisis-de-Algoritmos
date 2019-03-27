/*----------------------------------------- main.c-------------------------------------------*/
/*
	Incluye la funcion principal para realizar las busquedas mediante los algortimos implementados.
									25-Septiembre-2017
	version 1.0
	Autores: Aburto Perez Luis Mario y Osorio Rodriguez Esli Joana				
*/

/*Librerias incluidas*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "metodos.h"
#include "tiempo.h"

/*----------------------------------------- main --------------------------------------*/
/*	
	La funcion principal se encarga de la seleccion de el algoritmo que se utilizara 
	asi como utilizar la libreia tiempo.h para conocer el tiempo que le toma al
	algoritmo de busqueda encontrar el valor deseado.
	Parametros: 
		Tipo	Nombre de Variable						Descripcion
		int			argc 				Numero de argumentos que se mandaron en la ejecucion
		char*		argv[] 				cadenas recibidas en el comando de ejecucion, parametros
										que se utilizaran para lectura de numeros, seleccion de 
										algoritmo y numeros buscado.
*/
int main(int argc, char* argv[]){
	int n,algoritmo,valor;
	double utime0, stime0, wtime0,utime1, stime1, wtime1; //Variables para medición de tiempos
	if(argc!=4){
		printf("NO se recibieron los parametros necesarios\n");
		exit(0);
	}
	else{
		n=atoi(argv[1]);
		valor=atoi(argv[2]);
		algoritmo=atoi(argv[3]);
	}
	int* numeros;
	numeros=malloc(n*sizeof(int));
	leerNumeros(n,numeros);
	int encontrado;
	if(algoritmo==1){
		uswtime(&utime0, &stime0, &wtime0);
		encontrado=busquedaLineal(numeros,valor,n);
		uswtime(&utime1, &stime1, &wtime1);
		//printf("Busqueda Lineal\n	valor=%d\n	n=%d\n" ,valor,n);
	}
	else if(algoritmo==2){
		uswtime(&utime0, &stime0, &wtime0);
		encontrado=busquedaBinaria(numeros,valor,n);
		uswtime(&utime1, &stime1, &wtime1);
		//printf("Busqueda Binaria\n	valor=%d\n	n=%d\n" ,valor,n);
	}
	else if(algoritmo==3){
		struct Arbol* miArbol=NULL;
		llenarArbol(&miArbol,numeros,n);
		uswtime(&utime0, &stime0, &wtime0);
//printf("Llama ak arbol");
		encontrado=busquedaEnArbol(&miArbol,valor);
		uswtime(&utime1, &stime1, &wtime1);
		//printf("Busqueda Arbol Binario de Busqueda\n	valor=%d\n	n=%d\n" ,valor,n);
	}
	else{
		//printf("Algoritmo invalido");
		exit(0);
	}
	if(encontrado==1){
		//printf("Se encontro el valor= %d\n",valor);
		printf("SI\n");
	}
	else{
		printf("NO \n");
		//printf("NO se encontro el valor= %d\n",valor);
	}
	//Cálculo del tiempo de ejecución del programa
	//printf("\n");
//	printf(" %.10f \n",  wtime1 - wtime0);
	//printf("user (Tiempo de procesamiento en CPU) %.10f s\n",  utime1 - utime0);
	//printf("sys (Tiempo en acciónes de E/S)  %.10f s\n",  stime1 - stime0);
	//printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	//printf("\n");
	//Mostrar los tiempos en formato exponecial
	//printf("\n");
	//printf("real (Tiempo total)  %.10e s\n",  wtime1 - wtime0);
	//printf("user (Tiempo de procesamiento en CPU) %.10e s\n",  utime1 - utime0);
	//printf("sys (Tiempo en acciónes de E/S)  %.10e s\n",  stime1 - stime0);
	//printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	//printf("\n");
	//printf("////////////////////////////////////////////////////////////////////////////////////////////\n");
	exit(0);

}
