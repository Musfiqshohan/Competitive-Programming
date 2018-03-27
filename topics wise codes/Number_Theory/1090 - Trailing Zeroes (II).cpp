#include<bits/stdc++.h>
using namespace std;

long long f(long long n, long long i)
{
   long long total=0,k=i;

    while(n/i>0)
    {
        total+= n/i;
        i*=k;
    }
    return total;
}
long long g(long long p, long long q,long long i)
{
    long long cnt=0;
    while(p%i==0)
    {   p=p/i;
        cnt++;
    }


    return cnt*q;
}
int main()
{
    int t,test;
    scanf("%d",&test);
    for(t=0;t<test;t++){
    long long n,r,p,q,total=0,total2=0;
    scanf("%lld %lld %lld %lld",&n,&r,&p,&q);

    total= f(n,5) - f(n-r,5) - f(r,5);

    total2= f(n,2) - f(n-r,2) - f(r,2);

    total+= g(p,q,5);
    total2+= g(p,q,2);

   // printf("%lld\n", total2);

    printf("Case %d: %lld\n",t+1,min(total,total2));

    }

    return 0;
}
