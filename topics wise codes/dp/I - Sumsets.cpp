#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
long long  a[1000009];
long long m=1000000000;
long long pow1(long long n)
{
    if(n==0) return 1;
    if(n%2==0)
    {
        long long num= pow1(n/2)%m;
        return (num*num)%m;
    }
    else
    {
        return (2* pow1(n-1)%m)%m;
    }

}
long long f(long long i, long long n)
{
    long long total1=0, total2=0;
    if(n==0) return 1;

    if(n-pow1(i)<0) return 0;

    if(n<0) return 0;

    if(a[n]!=-1) return a[n];


    for(j=i; ;j++)
    {
        total+= f(j, n-)
    }

    return a[n];
}

int main()
{
    long long n;
    scanf("%lld",&n);

    memset(a,-1,sizeof(a));
    printf("%lld\n", f(0,n));
}
