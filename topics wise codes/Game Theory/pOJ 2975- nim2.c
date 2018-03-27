#include<stdio.h>

long long mx;
long long ara[70];
void f(long long n)
{
    long long cnt=0;
    while(n)
    {
        if(n%2==1) ara[cnt]++;
        cnt++;
        n/=2;
    }

    if(cnt>mx)
        mx=cnt;

}

int main()
{
    long long x,n;
    while(1)
    {
        memset(ara,0,sizeof ara);
        mx=0;

        scanf("%lld",&n);
        if(n==0) break;

        long long xor=0;



        for(long long i=0; i<n; i++)
        {
            scanf("%lld",&x);
            xor^=x;
            f(x);
        }


//        for(long long i=0;i<mx;i++)
//            printf("%lld -> %lld\n",i,ara[i]);

        long long i;
        for( i=mx-1; i>=0; i--)
        {
            if(ara[i]%2==1)
                break;
        }



        if(xor==0)
            printf("0\n");
        else
            printf("%lld\n",ara[i]);



    }



}

