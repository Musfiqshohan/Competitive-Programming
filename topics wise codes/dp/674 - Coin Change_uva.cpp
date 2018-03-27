#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
long long a[5][8000];
long long coin[]={1,5,10,25,50};
long long f(long long i, long long n)
{

    long long total1=0, total2=0;

    if(n==0) return 1;
    if(i==5) return 0;

    if(a[i][n]!=-1) return a[i][n];

    if( n -  coin[i] >=0)
    {
        total1= f(i , n - coin[i]);
    }
    else total1=0;

    total2= f(i+1, n);

    a[i][n]= total1+total2;

    return a[i][n];
}
int main()
{

    long long n;
    memset(a,-1,sizeof(a));

    while(scanf("%lld",&n)==1){


    printf("%lld\n",f(0,n));
    }
    return 0;
}
