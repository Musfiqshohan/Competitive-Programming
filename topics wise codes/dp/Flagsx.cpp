#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
long long  a[50];
long long f(long long i, long long j, long long n)
{
    //printf("%d %d %d\n",i,j,n);
    long long total=0;
    if(n==0)
    {
        if(j==2) return 0;
        else return 1;
    }

    if(a[n]!=-1) return a[n];
    n--;

    if(j==1)
    {
        total= f(1,2,n) + f(1,3,n);
    }
    else if(j==3)
    {
        total= f(3,2,n) + f(3,1,n);
    }
    else if(j==2)
    {
        if(i==1) total=f(2,3,n);
        else if(i==3) total= f(2,1,n);
    }

    n++;
    a[n]= total;

    return a[n];
}

int main()
{
    long long n,total=0;
    scanf("%lld",&n);
    memset(a,-1,sizeof(a));
    total= f(1,2,n-2) + f(1,3,n-2) + f(3,1,n-2) + f(3,2,n-2);
    printf("%lld\n",total);
    return 0;
}
