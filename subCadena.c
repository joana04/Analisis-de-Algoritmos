#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int max(int uno, int dos);
int longitudMax(char A[],char B[], int i, int j,int an, int bn,int visitados[an][bn]);

int main(int argc, char const *argv[]) {
  char A[1000], B[1000];
  int i,j;
  scanf("%s",&A);
  scanf("%s",&B);
  int an = strlen(A);
  int bn = strlen(B);
  int visitados[an][bn];

  for (i = 0; i < an; i++) {
    for (j = 0; j < bn; j++) {
      visitados[i][j]=-1;
    }
  }
  printf("%i",longitudMax(A,B,0,0,an,bn,visitados));
  return 0;
}
int longitudMax(char A[],char B[], int i, int j,int an, int bn,int visitados[an][bn]){
  if (i==an || j==bn) {
    return 0;
  }
  if (visitados[i][j] != -1)
  		return visitados[i][j];
  if (A[i]==B[j]) {
      visitados[i][j]=1+longitudMax(A,B,i+1,j+1,an,bn,visitados);
  }else{    
      visitados[i][j]=max(longitudMax(A,B,i,j+1,an,bn,visitados),longitudMax(A,B,i+1,j,an,bn,visitados));
    }
  return visitados[i][j];
  }

int max(int uno, int dos){
  if (uno<dos) {
    return dos;
  }
  else{
    return uno;
  }
}
