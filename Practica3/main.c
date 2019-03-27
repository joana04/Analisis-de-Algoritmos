/* fread example: read an entire file */
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h> // open
#include <unistd.h> // read, write
#define PESOBIT(bpos) 1<<bpos
#define CONSULTARBIT(var,bpos) (*(unsigned*)&var & PESOBIT(bpos))?1:0
#define PONE_1(var,bpos) *(unsigned*)&var |= PESOBIT(bpos)
#define PONE_0(var,bpos) *(unsigned*)&var &= ~(PESOBIT(bpos))
#define CAMBIA(var,bpos) *(unsigned*)&var ^= PESOBIT(bpos)


struct Arbol {
  struct Arbol* izquierda;
  int numero;
  char simbolo;
  struct Arbol* derecha;
};

struct Lista{
	struct Arbol* elemento;
	struct Lista* siguiente;
	struct Lista* anterior;
	int inicio;
};


int inOrden(struct Arbol*);
struct Lista* eliminarElemento(struct Lista* lista);
int busquedaBinaria(char* numeros, char numero, int total);
int shell(char*,int*,int);
struct Lista* crearLista(struct Lista* lista,char* simbolos, int* numeros, int total);
struct Lista* agregarElemento(struct Lista* lista,struct Arbol* arbol);
//Funciones y estructura arbol
struct Arbol* crearArbol(struct Lista*);

int main () {
  char buffer=0;
  size_t result;
  int leidos=0;
  int total=0;
  //ABrir y crear archivos
  int pFile = open ( "uno.txt" , O_RDONLY );
  FILE* fp=fopen("dos.txt","w");
  fclose(fp);
  int salida = open ( "dos.txt" , O_WRONLY );
  if (pFile==-1) {fputs ("File error",stderr); exit (1);}
  //Lectura de los bytes leidos
  while((leidos = read (pFile,&buffer,1))>0){
  	total+=leidos;
  }
  //Reservamos memoria para almacenar los caracteres y su frecuencia
  char* bytes = (char*)malloc(sizeof(char)*total);
  char* bufferTotal = (char*)malloc(sizeof(char)*total);
  int* frecuencia = (int*)malloc(sizeof(int)*total);
  int i=0;
  int repetidos=0;
  pFile = open ( "uno.txt" , O_RDONLY );
  if (pFile==-1) {fputs ("File error",stderr); exit (1);}
  while((leidos = read (pFile,&buffer,1))>0){
    //Condicionamos para el almacenamientos y el calculo de la frecuencia
    if(i==0){
      bytes[i]=buffer;
      bufferTotal[i]=buffer;
      frecuencia[i]=1;
      i++;
    }
    else{
      int pos=busquedaBinaria(bytes,buffer,i);
      if(pos==-1){
        bytes[i]=buffer;
        bufferTotal[i]=buffer;
        frecuencia[i]=1;
        i++;
      }
      else{
        frecuencia[pos]++;
        repetidos++;
      }
    }
  }
  //imprimirFrecuencia(bytes,frecuencia);
  shell(bytes,frecuencia,total-repetidos);
  int j=0;
  for(j=0;j<total-repetidos;j++){
    printf("%d %d\n",bytes[j],frecuencia[j]);
  }
  printf("%d\n",total);
  struct Lista* lista=malloc(sizeof(struct Lista));
  lista=crearLista(lista,bytes,frecuencia,total-repetidos);
  /*
  struct Arbol* arbol=malloc(sizeof(struct Arbol));
  arbol=crearArbol(lista);
  if(arbol==NULL)
    printf("arbol nulo\n");
  //inOrden(arbol);
  */close(pFile);
  close(salida);
  return 0;
}

int busquedaBinaria(char* numeros, char numero, int total){
  int inicio=0;
  int final=total-1;
  int medio;
  int control=-1;
  while(inicio<=final && control==-1){
    medio=(inicio+final)/2;
    //printf("%d %d\n",numeros[medio],numero);
    if(numero==numeros[medio]){
      control=medio;
    }else if(numeros[medio]>numero){
      final=medio-1;
    }else{
      inicio=medio+1;
    }
  }
  return control;
}

int shell(char* numeros,int* frecuencia,int n){
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
            temp=frecuencia[i];
            frecuencia[i]=frecuencia[i-k];
            frecuencia[i-k]=temp;
            b++;
          }
        }
      }
    k=(k/2);      
  }
  return 0;
}

struct Lista* crearLista(struct Lista* listaG,char* simbolos, int* numeros, int total){
	int i=0;
  struct Lista* listaFinal=malloc(sizeof(struct Lista));
  listaFinal->elemento=NULL;
  listaFinal->siguiente=NULL;
  listaFinal->anterior=NULL;
  struct Lista* lista=listaG;
	while(i<total){
    struct Arbol* arbol=malloc(sizeof(struct Arbol));
    arbol->numero=numeros[i];
    arbol->simbolo=simbolos[i];
    arbol->derecha=NULL;
    arbol->izquierda=NULL;
    lista->elemento=arbol;
		lista->anterior=malloc(sizeof(struct Lista));
		if(i==0){
			lista->inicio=1;
			lista->anterior=NULL;
      lista->siguiente=malloc(sizeof(struct Lista));
			lista->siguiente->anterior=lista;
		}else{
			lista->inicio=0;
			lista->siguiente=malloc(sizeof(struct Lista));
      lista->siguiente->anterior=lista;	
		}
		printf("%d %d\n",lista->elemento->simbolo,lista->elemento->numero);
		lista=lista->siguiente;
		i++;
	}
  while(lista->anterior!=NULL){
    lista=lista->anterior;
  }
  listaFinal=lista;
  while(listaFinal!=NULL){
    printf("Entra while\n");
    if(listaFinal->elemento==NULL)
      printf("elemento nulo\n");
    printf("%d %d\n",lista->elemento->simbolo,lista->elemento->numero);
    lista=lista->siguiente;
  }
	return lista;
}

struct Lista* eliminarElemento(struct Lista* lista){
  if(lista->anterior==NULL){
		lista->siguiente->inicio=1;
		lista->siguiente->anterior=NULL;
		return lista->siguiente;
	}else{
		lista->siguiente->anterior=lista->anterior;
		lista=lista->siguiente;
    while(lista->anterior!=NULL)
      lista=lista->anterior;
		return lista;
	}
}

struct Lista* agregarElemento(struct Lista* lista,struct Arbol* arbol){
  while(lista->elemento->numero<arbol->numero)
		lista=lista->siguiente;
		struct Lista* aux=malloc(sizeof(struct Lista));
		aux->elemento=arbol;
		aux->inicio=lista->inicio;
		aux->anterior=lista->anterior;
		aux->siguiente=lista;
		lista->anterior->siguiente=aux;
	return lista;
}

struct Arbol* crearArbol(struct Lista* lista){
  struct Arbol* padre=malloc(sizeof(struct Arbol));
  /*if(lista==NULL)
    printf("NO hay nada\n");
  while(lista!=NULL){
    printf("%d \n",lista->elemento->numero);
    lista=lista->siguiente;
  }
  /*
  padre->numero=lista->elemento->numero+lista->siguiente->elemento->numero;
  padre->izquierda=lista->elemento;
  padre->derecha=lista->siguiente->elemento;
  lista=eliminarElemento(lista);
  if(lista==NULL)
    printf("lista en crear nula\n");
  lista=eliminarElemento(lista->siguiente);
  lista=agregarElemento(lista,padre);
  padre=crearArbol(lista);
  return padre;
  */
}

int inOrden(struct Arbol* arbol){
  if (arbol != NULL) {
    inOrden(arbol->izquierda);
    printf("%d %d \n",arbol->numero,arbol->simbolo);
    inOrden(arbol->derecha);
  }else
    printf("NO imprimirFrecuencia\n");
}
