#include<iostream>
#include<string.h>
#include<stdio.h>

long long a[11][11], mul[11][11];

long long mod = 1000000007;
int d;

void multiply(long long a[11][11], long long b[11][11])  // d = dimension
{

    for (int i = 1; i <= d; i++)
    {
        for (int j = 1; j <= d; j++)
        {
            mul[i][j] = 0;

            for (int k = 1; k <= d; k++)
            {
                long long temp = a[i][k] * b[k][j];
                mul[i][j] += temp;
                mul[i][j] %= mod;
            }
        }
    }

    for (int i=1; i<=d; i++)
        for (int j=1; j<=d; j++)
            a[i][j] = mul[i][j];
}

void power(long long int F[11][11], int n)
{
    if( n == 0 || n == 1)
        return;

    power(F, n/2);

    multiply(F, F);

    if (n%2 != 0)
        multiply(F, a);
}



int main()
{

    int test, cs = 0;

    scanf("%d", &test);

    while(test--)
    {
        int n, k;

        scanf("%d %d", &k, &n);

        d = k;

        //memset(a, 0, sizeof(a));

        a[k][k] = 1;
        a[k][1] = 1;

        int j = 2;

        for(int i = 1; i<=k; i++)   a[i][j++] = 1;



        long long F[11][11];

        for(int i =1; i<=k; i++)
            for(int j =1; j<=k; j++)
                F[i][j] = a[i][j];

       power(F, n);

       printf("Case %d: %lld\n", ++cs, F[k][k]);

    }

    return 0;


}
