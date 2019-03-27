#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

float *MaximoMinimo;
int z = 0, TamPoblacion = 0;

int ObtenerEcuaciones(char restricciones[][30],char variables[],int Numrestricciones, char res[]);
int ComprobacionResultado(float Sist[][10],float ValoresResultantes[],int TipoIgualdad[],int Numrestricciones,int NumeroVariables,float res[]);
 
int MaximoMinimoFuncionObjetivo()
{
	float mayor, menor;
	int i=0;
	mayor = MaximoMinimo[0]; 
	menor = MaximoMinimo[0]; 
 
	for (i=0; i<z; i++)
	{
		if (MaximoMinimo[i]> mayor)
		{
			mayor=MaximoMinimo[i];
		}
		if (MaximoMinimo[i]< menor)
		{
			menor=MaximoMinimo[i];
		}
	}

	printf("El maximo es %f\n", mayor);
	printf("El minimo es %f\n", menor);

	return 0;
}

int extraernum(const char *s)
{
	const char *p=s;
	int n=0;

	while(*p)
	{
		if(isdigit(*p)) n=10*n+((*p)-'0');
		p++;
	}

	return n;
}

char *InvertirCadena(char *cadena)
{
	int len = strlen(cadena);
	int m=0, n=len;
	char tem;

	while(n>m)
	{
		tem = cadena[m];
		cadena[m++] = cadena[--n];
		cadena[n] = tem;
	}
	return cadena;
}

int main()
{
	char restricciones[20][30];
	char funcionObjetivo[30], variables[10];
	int Numrestricciones, i=0, j=0;

	srand(time(NULL));	

	printf("Introduzca Funcion Objetivo: Z = ");
	scanf("%s", funcionObjetivo);

	printf("\nIntroduzca Numero de restricciones: ");
	scanf("%d", &Numrestricciones);

	printf("\nIntroduzca restricciones:\n");
	while(Numrestricciones!=0)
	{
		scanf("%s", restricciones[i]);
		i++;
		Numrestricciones--;
	}
	Numrestricciones = i;

	for(j=0, i=0; j<strlen(funcionObjetivo); j++)
	{
		if ((funcionObjetivo[j] >='a' && funcionObjetivo[j] <= 'z'))
		{
			variables[i] = funcionObjetivo[j];
			i++;
		}
	}
	variables[i] = '\0';
	
	printf("Tamaño de la Poblacion: ");
	scanf("%d", &TamPoblacion);

	MaximoMinimo = malloc(TamPoblacion*sizeof(int));

	printf("\nFuncion Objetivo: Z = %s\n", funcionObjetivo);
	printf("Restricciones: \n");
	for(i=0; i<Numrestricciones; i++)
	{
		printf("%s\n", restricciones[i]);	
	}

	ObtenerEcuaciones(restricciones, variables, Numrestricciones, funcionObjetivo);		
	
	return 0;
}

int ObtenerEcuaciones(char restricciones[][30],char variables[],int Numrestricciones,char res[])
{
	char Digitos[20];
	int i = 0, j = 0, k = 0, m = 0, aux=0, n = 0;
	float Sistema[9][10], FuncionObjetivo[10], ValoresAleatorios[15], VariableDelimitadora = 0;
	int TipoIgualdad[15];

	for(i=0; i<strlen(res); i++)
	{
		if(isalpha(res[i]))
		{
			if(!isdigit(res[i-1]))
			{
				if(res[i-1]=='-')
				{
					FuncionObjetivo[j] = -1;
					j++;	
				}
				else if(res[i-1]=='+')
				{
					FuncionObjetivo[j] = 1;
					j++;
				}
				else
				{
					FuncionObjetivo[j] = 1;
					j++;
				}	
			}
			else
			{
				aux = 0;
				memset(Digitos, '\0', 10);
				while(isdigit(res[(i-1)-aux]))
				{
					Digitos[aux] = res[(i-1)-aux]; 
					aux++;
				}
				InvertirCadena(Digitos);
				if(res[i-1-aux]=='-')
				{
					FuncionObjetivo[j] = -1*extraernum(Digitos);
					j++;	
				}
				else if(res[i-1-aux]=='+')
				{
					FuncionObjetivo[j] = 1*extraernum(Digitos);
					j++;
				}
				else
				{
					FuncionObjetivo[j] = 1*extraernum(Digitos);
					j++;
				}
			}	
		}
	}

	for(i=0; i<Numrestricciones; i++)
	{
		if(strstr(restricciones[i],"<=")!=NULL)
		{
			TipoIgualdad[i] = 0;	
		}
		else if(strstr(restricciones[i],">=")!=NULL)
		{
			TipoIgualdad[i]	= 1;
		}
		else if(strstr(restricciones[i],"=")!=NULL)
		{
			TipoIgualdad[i]	= 2;
		}
		
		for(j=0; j<strlen(variables); j++)
		{
			if(strchr(restricciones[i],variables[j])!=NULL)
			{
				for(k=0; k<strlen(restricciones[i]); k++)
				{
					if(restricciones[i][k]==variables[j])
					{
						if(!isdigit(restricciones[i][k-1]))
						{
							if(restricciones[i][k-1]=='-')
							{
								Sistema[i][m] = -1;
								m++;	
							}
							else if(restricciones[i][k-1]=='+')
							{
								Sistema[i][m] = 1;
								m++;
							}
							else
							{
								Sistema[i][m] = 1;
								m++;
							}	
						}
						else
						{
							aux = 0;
							memset(Digitos, '\0', 10);
							while(isdigit(restricciones[i][(k-1)-aux]))
							{
								Digitos[aux] = restricciones[i][(k-1)-aux]; 
								aux++;
							}
							InvertirCadena(Digitos);

							if(restricciones[i][(k-1)-aux]=='-')
							{
								Sistema[i][m] = -1*extraernum(Digitos);
								m++;	
							}
							else if(restricciones[i][(k-1)-aux]=='+')
							{
								Sistema[i][m] = 1*extraernum(Digitos);
								m++;
							}
							else
							{
								Sistema[i][m] = 1*extraernum(Digitos);
								m++;
							}
							
						}
						break;
					}
				}	
			}
			else
			{
				Sistema[i][m] = 0;
				m++;
			}
			if(j==(strlen(variables)-1))
			{
				aux = 0;
				memset(Digitos, '\0', 10);
				while(isdigit(restricciones[i][strlen(restricciones[i])-1-aux]))
				{
					Digitos[aux] = restricciones[i][strlen(restricciones[i])-1-aux]; 
					aux++;
				}
				InvertirCadena(Digitos);
				
				if(restricciones[i][strlen(restricciones[i])-1-aux]=='-')
				{
					Sistema[i][m] = -1*extraernum(Digitos);
					m++;
				}
				else if(restricciones[i][strlen(restricciones[i])-1-aux]=='=')
				{
					Sistema[i][m] = extraernum(Digitos);
					m++;
				}	
			}	
		}
		m=0;
	}

	printf("\n");
	m=0, aux=0;

	VariableDelimitadora = Sistema[0][strlen(variables)];
	for(i=0; i<Numrestricciones; i++)
	{
		if (Sistema[i][strlen(variables)]> VariableDelimitadora)
		{
			VariableDelimitadora=Sistema[i][strlen(variables)];
		}	
	}

	for(i=0; i<TamPoblacion; i++)
	{
		while(m<strlen(variables))
		{
			ValoresAleatorios[m] = VariablesAleatorias((int)VariableDelimitadora);
			m++;
		}
		n = ComprobacionResultado(Sistema, ValoresAleatorios, TipoIgualdad, Numrestricciones, strlen(variables), FuncionObjetivo);
			
		if(n==0)
		{
			i--;
			m=0;
		}
		else
		{
			m=0;
		}
	}		

	printf("\n");

	MaximoMinimoFuncionObjetivo();
	
	return 0;
}

int VariablesAleatorias(int rango)
{	
	return rand()%rango;
}

int ComprobacionResultado(float Sist[][10],float ValoresResultantes[],int TipoIgualdad[],int Numrestricciones,int NumeroVariables,float res[])
{
	int i=0, j=0, aux = 0, n = 0;
	float auxResultado[15];

	for(i=0; i<Numrestricciones; i++)
	{
		auxResultado[i] = 0;
		for(j=0; j<NumeroVariables; j++)
		{  
			auxResultado[i] = auxResultado[i] + Sist[i][j]*ValoresResultantes[j];
		}
	}

	for(i=0; i<Numrestricciones; i++)
	{
		if(TipoIgualdad[i]==0)
		{
			if(auxResultado[i]<=Sist[i][NumeroVariables])
			{
				aux++;	
			}	
		}
		else if(TipoIgualdad[i]==1)
		{
			if(auxResultado[i]>=Sist[i][NumeroVariables])
			{
				aux++;		
			}
		}
		else
		{
			if(auxResultado[i]==Sist[i][NumeroVariables])
			{
				aux++;		
			}
		}
	}

	if(aux ==  Numrestricciones)
	{
		printf("Valores validos para la funcion Objetivo\n");

		MaximoMinimo[z] = 0;
		for(i=0; i<NumeroVariables; i++)
		{
			MaximoMinimo[z] = MaximoMinimo[z] + res[i]*ValoresResultantes[i];
			printf("Variable X%d %f\n", (i+1), ValoresResultantes[i]);
		}
		printf("Z: %f\n", MaximoMinimo[z]);
		z++;  
		n = 1;
	}
	else
	{
		n = 0;
	}	

	return n;
}

