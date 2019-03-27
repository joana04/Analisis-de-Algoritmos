/* Metodos.c 
Incluye todas las funciones utilizadas en el main.c y para ordenar el arreglo de numeros, asi mismo contiene los algoritmos para el ordenamiento.
01-Septiembre-2017
version 1.0
Autores: Aburto Pérez Luis Mario y Osorio Rodríguez Eslí Joana*/
#include "metodos.h"

int indice=-1;
/*SeleccionAlgoritmo recibe dos parametros, el primero incica el algoritmo a utilizar y elsegundo la cantidad de numeros a ordenar.
Descricion de funcionamiento: se compara el primer parametro que se recibe para seleccionar el algoritmo a utilizar y una vez que se encuentra la opcion, se llama la funcion del algoritmo y se le pasa los parametros para comenzar a ordenar.
Error: Se produce un error cuando el numero para seleccionar el algortmo a utilizar es invalido.*/
int seleccionAlgortimo(int algoritmo,int* numeros, int n){
	if(algoritmo==1){
		burbujaSimple(numeros,n);
		//printf("Algoritmo: burbujaSimple\n	n=%d\n",n);
	}
	else if(algoritmo==2){
		burbujaOptimizada(numeros,n);
		//printf("Algoritmo: burbujaOptimizada\n	n=%d\n",n);
	}
	else if(algoritmo==3){
		insercion(numeros,n);
		//printf("Algoritmo: insercion\n	n=%d\n",n);
	}
	else if(algoritmo==4){
		seleccion(numeros,n);
		//printf("Algoritmo: seleccion\n	n=%d\n",n);
	}
	else if(algoritmo==5){
		shell(numeros,n);
		//printf("Algoritmo: shell\n	n=%d\n",n);
	}
	else if(algoritmo==6){
		struct Arbol* ptrRaiz=NULL;
		arbol(numeros,n,ptrRaiz);
		//printf("Algoritmo: arbol\n	n=%d\n",n);
	}
	else{
		printf("Algoritmo invalido\n");
		exit(0);
	}
	return 0;
}

/* leerNumeros recibe dos parametros, n que es la cantidad de numeros a ordenar y un apuntador a un arreglo en el cual se van a almacenar los numeros leidos
Descipcion de funcionamiento: con un for se leen los numero contenidos en el archivo y asi se les asigna un lugar en el arreglo.
*/

int leerNumeros(int n,int* numeros){
	int i;
	for(i=0;i<n;i++){
		scanf("%d",&numeros[i]);
	}
	return 0;
}

/*imprimir recibe dos parametros un apuntador al arreglo que contiene los numeros y la cantidad de numeros que contiene este arreglo, asi impime el contenido del arreglo
Descripcion de funcionamiento: Con ayuda de un for se van imprimiento todos los numeros que cotiene el arreglo.*/
int imprimir(int* numeros,int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d \n",numeros[i]);	
	}
	return 0;
}
/*burbujaSimple recibe dos parametros, un apuntador al arreglo de numeros a ordenar y n que es la cantidad de numeros, asi obtenemos el arreglo ordenado al concluir la funcion.
Descipcion de funcionamiento: Se van comparndo numero con numero y se van camiando de posicion si es el numero es mayor al numero con el cual se esta comparando, se compara numero por numero en el arreglo*/

int burbujaSimple(int* numeros,int n){
	int i,j,temp;
	for(i=1;i<n;i++){
		for(j=0;j<n-1;j++){
			if(numeros[j]>numeros[j+1]){
				temp=numeros[j];
				numeros[j]=numeros[j+1];
				numeros[j+1]=temp;
			}
		}
	}
	return 0;
}
/*burbujaOptimizada recibe dos parametros, un apuntador al arreglo de numeros a ordenar y n que es la cantidad de numeros, asi obtenemos el arreglo ordenado al concluir la funcion.
Descipcion de funcionamiento: Se van comparndo numero con numero y se van camiando de posicion si es el numero es mayor al numero con el cual se esta comparando, se compara numero por numero en el arreglo, pero se van omitiendo los numeros que anteriormente ya se compararon con anterioridad por que esos ya estan ordenados*/
int burbujaOptimizada(int* numeros,int n){
	int cambios=1,i,j,temp=0;
	for(i=1;(i<n)&&(cambios==1);i++){
		cambios=0;
		for(j=0;j<n-i;j++){
			if(numeros[j]>numeros[j+1]){
				temp=numeros[j];
				numeros[j]=numeros[j+1];
				numeros[j+1]=temp;
				cambios=1;
			}
		}
	}
	return 0;
}
/* insercion recibe dos parametros, un apuntador al arreglo de numeros a ordenar y n que es la cantidad de numeros, asi obtenemos el arreglo ordenado al concluir la funcion.
Descipcion de funcionamiento:se toma un elemento de el arreglo y se compara contra los demas, cuando de encuentra un menor o cuando ya no se encuentan numeros se inserta el elemento comparado y asi se van desplazando los elementos a la derecha y acomodandose ya en orden  */

int insercion(int* numeros, int n){
	int i,j,temp;
	for(i=1;i<n;i++){
		temp=numeros[i];
		j=i-1;
		while((numeros[j]>temp)&&(j>=0)){
			numeros[j+1]=numeros[j];
			j--;
		}
		numeros[j+1]=temp;
	}
	return 0;
}

/*seleccion recibe dos parametros, un apuntador al arreglo de numeros a ordenar y n que es la cantidad de numeros, asi obtenemos el arreglo ordenado al concluir la funcion.
Descipcion de funcionamiento:Busca el minimo elemento  entre una posicion del arreglo y el final del mismo, asi al ncontrar el mismo intercamia las posiciones, esto lo realiza consecutivamente hasta termnar cone l arrelgo ordenado*/
int seleccion(int* numeros,int n){
	int i,k,p,temp;
	for(k=0;k<n-1;k++){
		p=k;
		for(i=k+1;i<=n-1;i++){
			if(numeros[i]<numeros[p]){
				p=i;
			}
		}
		if(p!=k){
			temp=numeros[p];
			numeros[p]=numeros[k];
			numeros[k]=temp;
		}
	}
	return 0;
}
/*shell recibe dos parametros, un apuntador al arreglo de numeros a ordenar y n que es la cantidad de numeros, asi obtenemos el arreglo ordenado al concluir la funcion.
Descipcion de funcionamiento: Es basicamente la generealizacion del algoritmo de incersion, basicamente aplica insercion en elementos separados por un espacio en el arreglo, asi se hacen cambios mas grande esntre el arreglo y los espacios cada vez van disminuyendo de modo que se asegura que el arreglo este casi ordenado, el su ultimo paso se hace de nuevo el ordenamiendo por insercion pero ya se asegura que el arreglo esta casi ordenado*/
int shell(int* numeros,int n){
	int i=0,temp,b;
	int k=n/2;
	while(k>=1){
		b=1;
			while(b!=0){
				b=0;
				for(i=k; i<=n-1; i++){
					if (numeros[i-k]>numeros[i]){
						temp=numeros[i];
						numeros[i]=numeros[i-k];
						numeros[i-k]=temp;
						b++;
					}
				}
			}
		k=(k/2);			
	}
	return 0;
}
/*arbol recibe  tres parametros, el primero es un apuntador al arreglo de numeros que se quiere ordenar, el segundo es el la cantidad de numeros a ordenar y el tercero es un apuntador a la estructura arbol, que sera nuestra raiz, con esta funcion obtenemos nuestro albol ya lleno,
Descripcion de funcionamiento: dentro de la funcion llamamos insertar nodo y la lectura del arbol inOrden, al final de esta funcion obtenemos nuestro arreglo ya ordenado */
void arbol(int* numeros,int n, struct Arbol* raiz){
	int i;
	for(i=0;i<n;i++){
		insertarNodo(&raiz,numeros[i]);
	}
	inOrden(raiz,numeros);
}
/*insertarNodo recibe un doble apuntador a la estructura arbol y el numero que se desea insertar al arbol, asi obtenemos el arbol con el nuevo noso insertado.
Descripcion de funcionamiento: El numero que se recibe se compara con las hojas que ya se encuesntran el en el arbol, así si el numero es major se inserta a la derecha y si es menor a la izquieray si ya existen nosodos en esa posicion se cuelven a comparar hasta que llegue a un espacio vacio en donde insertarse.
Error: en el arbol no se pueden insertar numeros iguales, si se intenta insertar un numero igual a uno que ya esta en el arbol arroja error la funcion y no se inserta.
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

/* inOrden recibe dos parametros, la estructura arbol que vamos a leer y el arreglo en el cual vamos a almacenar los numeros ya ordenados, al final obtenemos nuetsro arreglo ya ordenado
Descripcion de funcionamiento: Se recorren las hojas del arbol de izquierda a raiz y a derecha para obtener nuestros numeros ya ordenados, los apuntadores se van manejando y cambiando ara hacer la lectura del arbol de modo qu el arbol es recorriedo de izquiera a raiz y a la derecha, siendo el numero mas chico el que se encuentr mas a la izquierda y abajo y el mas grande el de la derecha del nivel mas bajo.*/
int inOrden(struct Arbol* arbol,int* numeros){
	if (arbol != NULL) {
		inOrden(arbol->izquierda,numeros);
		numeros[indice]=arbol->numero;
		inOrden(arbol->derecha,numeros);
		return 0;
	}else{
		indice++;
		return 0;
	}	
}
