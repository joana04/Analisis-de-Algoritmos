/* Main.c 
Funcion principal, en la cual se mandan a llamar a todas las funciones necesarias para que se ordene una rreglo
01-Septiembre-2017
version 1.0
Autores: Aburto Pérez Luis Mario y Osorio Rodríguez Eslí Joana*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "metodos.h"
#include "tiempo.h"
/*main recibe dos argumentos, con el primero se selecciona el algoritmo que se desea usar para 
ordenar los números y el segundo indica la cantidad de numeros a ordenar.
Descipcion de funcionamiento: primero se reciben estos argumentos y se llaman a las funciones llenar el arreglo con los numeros que se leen de el archivo y la seleccion del algoritmo de ordenamiento, tambien se calculan los tiempos de ejecucion.
Errores:Puede causar error que no se reciban los parametros necesarios o si en alguna de las funciones que se utilizan ocurre un error.*/
int main(int argc, char* argv[]){
	int n,algoritmo;
	double utime0, stime0, wtime0,utime1, stime1, wtime1; //Variables para medición de tiempos
	if(argc!=3){
		printf("NO se recibieron los parametros necesarios\n");
		exit(0);
	}
	else{
		n=atoi(argv[1]);
		algoritmo=atoi(argv[2]);
	}
	int* numeros;
		numeros=malloc(n*sizeof(int));
	leerNumeros(n,numeros);
	imprimir(numeros,n);
	uswtime(&utime0, &stime0, &wtime0);
	seleccionAlgortimo(algoritmo,numeros,n);
	uswtime(&utime1, &stime1, &wtime1);
	imprimir(numeros,n);
	//Cálculo del tiempo de ejecución del programa
	printf("\n");
	//printf("%.10f s, ",  wtime1 - wtime0);// primero que se corrio
	//printf(" %.10f s,",  utime1 - utime0);
	
	//printf("\n");
	//Mostrar los tiempos en formato exponecial
	//printf("\n");
	//printf("real (Tiempo total)  %.10e s\n",  wtime1 - wtime0);
	//printf("user (Tiempo de procesamiento en CPU) %.10e s\n",  utime1 - utime0);
	
	//printf("\n");
	//printf("////////////////////////////////////////////////////////////////////////////////////////////\n");
	exit(0);
}
