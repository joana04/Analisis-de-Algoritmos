#include <stdio.h>
#include <stdlib.h>

struct arreglo
{
    int a;
};

void ordena(struct arreglo *puntos,int n)
{
	int k = n/2;
	int i,j;
	int v ;

	while(k>=1)
    {
		for( i=k ; i<n ;i++)
		{
			v = puntos[i].a;
			j = i - k;

			while(j>=0 && puntos[j].a > v)
            {
				puntos[j+k].a = puntos[j].a;
				j-=k;
			}
			puntos[j+k].a=v;
		}
		k/=2;
	}
}


int Loading( struct arreglo *W , int N )
{
    int i = 0;
    int j = N;
    int res = 0 , t , obj;

    while( i != j )
    {
        j--;
        //printf("j - %d \n",W[j].a);
        t = W[j].a;
        obj = 1;

        while( i != j && (obj*t < 50) )
        {
            //printf("i - %d \n",W[i].a);
            obj++;
            i++;
        }

        if( obj*t >= 50)
        {
            res++;
        }
    }


    return res;
}

int main()
{
    int T , N ;
    int i , j;
    struct arreglo W[110];

    scanf("%d",&T);

    int res[T];

    for( i=0 ; i<T ; i++ )
    {
        scanf("%d",&N);

        for( j=0 ; j<N ; j++ )
        {
            scanf("%d",&W[j].a);
        }

        ordena( W , N );

        res[i] = Loading( W , N );
    }

    for( i=0 ; i<T ; i++ )
    {
        printf("Case #%d: %d \n",i+1,res[i]);
    }

    return 0;
}
