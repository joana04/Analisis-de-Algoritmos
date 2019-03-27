/*----------------------------------------- Metodos.c-------------------------------------------*/
/*
	Incluye todas las funciones utilizadas en el main.c y para ordenar el arreglo de 
	numeros, asi mismo contiene los algoritmos para el ordenamiento.
						25-Septiembre-2017
	version 1.0
	Autores: Aburto Perez Luis Mario y Osorio Rodriguez Esli Joana				
*/
	
#include "metodos.h"

/*-----------------------------------------Busqueda Binaria--------------------------------------*/
/*	
	La funcion de busqueda binaria recibe el arreglo que contiene los números ordenados donde se 
	buscara el valor indicado. La busqueda la realiza tomando un valor medio y comparar el numero
	buscado, cada vez que el valor medio sea diferente, la busqueda se realizara con la mitad en
	de los numeros seleccionados en la iteracion anterior.
	Parametros: 
		Tipo	Nombre de Variable						Descripcion
		int*		numeros 			arreglo en donde se encuentran los numeros ordenados
		int			numero 				numero que se desea buscar en el arreglo numeros
		int			total				tamaño del arreglo de numeros
	Return:
		Tipo	Nombre de la Variable					Descripcion
		int			control				Regresa un 1 en caso de encontrar el valor y un -1 
										cuando no lo encontro.
*/
int busquedaBinaria(int* numeros, int numero, int total){
	int inicio=0;
	int final=total-1;
	int medio;
	int control=-1;
	while(inicio<=final && control==-1){
		medio=(inicio+final)/2;
		if(numero==numeros[medio]){
			control=1;
		}else if(numeros[medio]>numero){
			final=medio-1;
		}else{
			inicio=medio+1;
		}
	}
	return control;
}

/*-----------------------------------------Busqueda Lineal--------------------------------------*/
/*	
	La funcion de busqueda lineal realiza la comparacion de el numero buscado con cada uno de los
	elementos del arreglo en donde tenemos nuestros numeros ordenados.
	Parametros: 
		Tipo	Nombre de Variable						Descripcion
		int*		numeros 			arreglo en donde se encuentran los numeros ordenados
		int			numero 				numero que se desea buscar en el arreglo numeros
		int			total				tamaño del arreglo de numeros
	Return:
		Tipo	Nombre de la Variable					Descripcion
		int			control				Regresa un 1 en caso de encontrar el valor y un -1 
										cuando no lo encontro.
*/
int busquedaLineal(int* numeros, int numero,int total){
	int control=-1, i=0;
	while(control==-1 && i<total){
		if(numeros[i]==numero){
			control=1;
		}
		i++;
	}
	return control;
}

/*-----------------------------------------Busqueda en Arbol--------------------------------------*/
/*	
	La funcion de busqueda en Arbol hace uso de un arbol binario de busqueda en donde almacena los
	numeros sin ordenar. Una vez almacenados el valor buscado escomparado con el valor que tiene 
	cada nodo en el arbol. En caso de no encontrar el valor en el primero nodo realiza una 
	comparacion si es mayor o menor para buscar en los nodos hijos correspondientes y asi dividir
	la busqueda.
	Parametros: 
			Tipo			Nombre de Variable						Descripcion
		struct Arbol**			arbol 				estructura arbol en donde estan almacenados los numeros
			int					numero 				numero que se desea buscar en el arbol
	Return:
		Tipo	Nombre de la Variable					Descripcion
		int			control				Regresa un 1 en caso de encontrar el valor y un -1 
										cuando no lo encontro.
*/
int busquedaEnArbol(struct Arbol** arbol,int numero){
	int control=0;
	printf("Entra");
	if(*arbol==NULL){
		control=-1;
	}else{
		while(control==0){
			printf("%d %d \n",(*arbol)->numero,numero);
			if((*arbol)->numero==numero){
				control=1;
			}else if(numero>(*arbol)->numero){
				if((*arbol)->derecha==NULL){
					control=-1;
				}else{
					(*arbol)=(*arbol)->derecha;	
				}
			}else{
				if((*arbol)->izquierda==NULL){
					control=-1;
				}else{
					(*arbol)=(*arbol)->izquierda;	
				}
			}
		}
	}
	return control;
}

/*-----------------------------------------Insertar Nodo--------------------------------------*/
/*	
	La funcion insertarNodo crea un nuevo nodo en el arbol en donde almacenara un valor y creara
	dos nuevos nodos nulos por el momento.
	Parametros:  
			Tipo			Nombre de Variable						Descripcion
		struct Arbol**			arbol 				estructura arbol en donde se almacenaran los numeros
			int					numero 				numero que se almacenara en el nodo creado

*/
void insertarNodo(struct Arbol** arbol, int numero){
	if (*arbol == NULL) {
		*arbol = malloc(sizeof(struct Arbol));
		if (*arbol != NULL) {
			(*arbol)->numero = numero;
			(*arbol)->izquierda = NULL;
			(*arbol)->derecha = NULL;
		} else {
			printf("No se inserto %d. No hay memoria disponible.n", numero);
		}
	} else {
		if (numero < (*arbol)->numero){ //SI es menor se inserta a la izquierda
			insertarNodo(&((*arbol)->izquierda), numero);
		} else if (numero > (*arbol)->numero){ //Si es mayor se inserta a la derecha
			insertarNodo(&((*arbol)->derecha), numero);
		} else {
			printf("Error");
		}
	}
}

/*-----------------------------------------Ordenamiento Shell----------------------------------------*/
/*	
	Realiza el ordenamiento de un arreglo de numeros de forma ascendente utilizando el algoritmo shell.
	Parametros: 
		Tipo	Nombre de Variable						Descripcion
		int*		numeros 			arreglo en donde se encuentran los numeros a ordenar
		int			  n					tamaño del arreglo de numeros
*/
void ordenamientoShell(int *numeros,int n){
	int j,i,v;
	int k=n/2;
	while(k>=1){
		for(i=k;i<n;i++){
			v=numeros[i];
			j=i-k;
			while((j>=0)&&(numeros[j]>v)){
				numeros[j+k]=numeros[j];
				j-=k;
			}
			numeros[j+k]=v;
		}
		k/=2;
	}
}

/*-----------------------------------------Llenar Arbol--------------------------------------*/
/*	
	La funcion llenarArbol llena el arbol guardando los valores de un arreglo de numeros generando
	los nodos necesarios para almacenarlos.
	Parametros:  
			Tipo			Nombre de Variable						Descripcion
		struct Arbol**			arbol 				estructura arbol en donde se almacenaran los numeros
			int*				numeros 			arreglo de numeros con los que se llenara el arbol
			int					  n					tamaño del arreglo de numeros

*/
int llenarArbol(struct Arbol** nodo,int* numeros, int n){
	int i=0;
	for(i=0;i<n;i++){
		insertarNodo(nodo,numeros[i]);	
	}
	return 0;
}

int leerNumeros(int n,int* numeros){
	int i;
	for(i=0;i<n;i++){
		scanf("%d",&numeros[i]);
	}
	//ordenamientoShell(numeros,n);
	//imprimir(numeros,n);
	return 0;
}

/*-----------------------------------------imprimir--------------------------------------*/
/*	
	Imprime en pantalla los numeros de un arreglo de numeros.
	Parametros:  
		Tipo		Nombre de Variable				Descripcion
		int*			numeros 			arreglo de numeros a imprimie
		int				  n					tamaño del arreglo de numeros

*/
int imprimir(int* numeros,int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d \n",numeros[i]);	
	}
	return 0;
}

