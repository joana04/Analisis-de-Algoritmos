#ifndef __METODOS_H__
#define __METODOS_H__

#include <stdio.h>
#include <stdlib.h>
//Funciones y estructura arbol
struct Arbol {
	struct Arbol* izquierda;
	int numero;
	struct Arbol* derecha;
};
void arbol(int*,int,struct Arbol*);
int inOrden(struct Arbol*,int*);
void insertarNodo(struct Arbol**,int);
//Funciones del programa
int burbujaSimple(int*,int);
int leerNumeros(int,int*);
int imprimir(int*,int);
int burbujaSimple(int*,int);
int burbujaOptimizada(int*,int);
int insercion(int*,int);
int seleccion(int*,int);
int shell(int*,int);
int seleccionAlgortimo(int,int*,int);

#endif