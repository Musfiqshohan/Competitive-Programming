#include<stdio.h>
#include<bits/stdc++.h>
long long a[1100009],b[1000009];

int pow1(int i, int n)
{
    int total=1,j;
    for(j=1;j<=n;j++) total*=i;
    return total;
}
long long gcd(long long a,long long b)
{
   if(b==0) return a;
   else return gcd(b,a%b);
}
long long  f(long long n, long long i)
{
    long long cnt=0;
    while(n%i==0)
    {
        n=n/i;
        cnt++;
    }

    return cnt;
}
int main()
{
    long long i,j;


    for(i=0; i<1000009; i++) a[i]=1;
    for(i=0; i<1000009; i++) b[i]=1;

    for(i=2; i<=1009; i++)
    {
        if(a[i]==1)
        {

            for(j=2; i*j<=1000009; j++)
            {
                int num=f(i*j,i);
                b[i*j]*= pow1(i, num );
                a[i*j]*= ( num +1 );

            }
        }
    }


    //for(i=2;i<=100;i++) printf("%lld  %lld\n",i,b[i]);
    for(i=2;i<=1000009;i++)
    {
        if(i!=b[i])
        {
            b[i]= i;
            a[i]*=2;
        }
    }

    long long t,test;
    scanf("%lld",&test);

    for(t=0; t<test; t++)
    {
        long long n,m;
        scanf("%lld %lld",&n,&m);
        printf("%lld\n", a[gcd(n,m)]);
    }

    return 0;
}
