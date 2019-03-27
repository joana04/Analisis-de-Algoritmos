#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main(){
	int n=0,s=0;
	
	scanf("%d",&s);
	char A[s], B[s];
	int ss=s*2;
	char C2[ss];
	scanf("%s",&A);
  	scanf("%s",&B);
  	int i, j, max = 0, cambio = -1;
    int sig[s];
    i=0;
    j=-1;
    do{
    	sig[i]=j;
    	while(j>=0 && A[i] != A[j]){
    		j=sig[i];
    	}
    	i++;
    	j++;
    }while(i<s);
	printf("GUARDEE\n");
    strcat(C2,B);
    strcat(C2,B);

		printf("GUARDEE\n");

	for (i = 0, j = 0; j < s && i < 2 * s; i++, j++){
                while (j >= 0 && C2[i] != C2[j]){
                    if (j > max){
                        max = j;
                        cambio = (i-j);
                    }
                    j = sig[j];
                }
            }
           
	printf("%d\n",cambio);
	
	return 0;
}

