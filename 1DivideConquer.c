#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int n;
int *A;


long long medio( int medio , int inicio , int fin )
{
    long long  izq=LLONG_MIN , der=LLONG_MIN , suma;
    int i;

    for( i = medio , suma=0 ; i>=inicio ; i-- )
    {
        suma = suma + A[i];

        if(suma > izq)
        {
            izq = suma;
        }
    }

    for( i = medio+1, suma=0 ; i<=fin ; i++ )
    {
        suma = suma + A[i];

        if(suma > der)
        {
            der = suma;
        }
    }

    return izq+der;
}

long long DyV( int inicio , int fin )
{

    if( inicio == fin )
    {
        return A[inicio];
    }

    long long izq , der , medi;
    int med;
    med = (inicio+fin)/2;

    izq = DyV(inicio,med);
    der = DyV(med+1,fin);
    medi = medio(med,inicio,fin);


    if(izq > der)
    {
        if(izq > medi)
        {
            return izq;
        }
        else
        {
            return medi;
        }
    }
    else
    {
        if(der > medi)
        {
            return der;
        }
        else
        {
            return medi;
        }

    }

}

int main()
{
    int i;
    long long res;

    scanf("%d",&n);
    A = (int *)malloc(sizeof(int)*n);

    for( i=0 ; i<n ; i++)
    {
        scanf("%d",&A[i]);
    }

    res = DyV(0,n-1);

    printf("%lld",res);

    return 0;
}
