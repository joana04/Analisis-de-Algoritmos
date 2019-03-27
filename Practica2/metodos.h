#ifndef __METODOS_H__
#define __METODOS_H__

#include <stdio.h>
#include <stdlib.h>
//Funciones y Estructuras Auxiliares
struct Arbol {
	struct Arbol* izquierda;
	int numero;
	struct Arbol* derecha;
};
void insertarNodo(struct Arbol**,int);
int llenarArbol(struct Arbol**,int*, int);
void ordenamientoShell(int*,int);
int leerNumeros(int,int*);
int imprimir(int*,int);
int seleccionAlgortimo(int,int*,int);
//Metodos de busqueda
int busquedaLineal(int*, int,int);
int busquedaBinaria(int*, int, int);
int busquedaEnArbol(struct Arbol**,int);

#endif
