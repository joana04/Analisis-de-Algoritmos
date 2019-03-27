#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int max(int algo1, int algo2){
  if (algo1<algo2) {
    return algo2;
  }
  else{
    return algo1;
  }
}

int longitudMax(char cad1[],char cad2[], int indice1, int indice2,int tam1, int tam2,int mat[tam1][tam2]){
  if (indice1==tam1 || indice2==tam2) {
    return 0;
  }
  if (cad1[indice1]==cad2[indice2]) {
    if (mat[indice1][indice2] == -1) {
      mat[indice1][indice2]=1+longitudMax(cad1,cad2,indice1+1,indice2+1,tam1,tam2,mat);
    }
    return mat[indice1][indice2];
  }else{
    if (mat[indice1][indice2] == -1) {
      mat[indice1][indice2]=max(longitudMax(cad1,cad2,indice1,indice2+1,tam1,tam2,mat),longitudMax(cad1,cad2,indice1+1,indice2,tam1,tam2,mat));
    }
    return mat[indice1][indice2];
  }
}

int main(int argc, char const *argv[]) {
  char cad1[1000], cad2[1000];
  int i,j;
  scanf("%s",&cad1);
  scanf("%s",&cad2);
  int tam1 = strlen(cad1);
  int tam2 = strlen(cad2);
  int mat[tam1][tam2];

  for (i = 0; i < tam1; i++) {
    for (j = 0; j < tam2; j++) {
      mat[i][j]=-1;
    }
  }
  printf("%i",longitudMax(cad1,cad2,0,0,tam1,tam2,mat));
  return 0;
}
