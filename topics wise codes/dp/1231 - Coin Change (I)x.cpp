#include<stdio.h>
#include<bits/stdc++.h>
long long n,m=100000007;
long long rem[55], coin[55];
long long a[55][1000];
long long f( long long i, long long k)
{

    long long total=0,j,x;
    if(k==0) return 1;
    if(i==n) return 0;
    if(k<0) return -1;

    if(a[i][k]!=-1) return a[i][k];

    for(j=0;j<=rem[i];j++)
    {

        x=f( i+1 , k-(coin[i]*j));
        if(x==-1) break;


        total= total+ x%m;  //   total= total%m + x%m;
        total= total%m;

        //if(x==1) break;

    }


    a[i][k] =total;

    return a[i][k];
}
int main()
{
    long long t,test;
    scanf("%lld",&test);
    for(t=0;t<test;t++){
    long long k,i;
    scanf("%lld %lld",&n,&k);

    memset(a,-1,sizeof(a));
    for(i=0;i<n;i++) scanf("%lld",&coin[i]);
    for(i=0;i<n;i++) scanf("%lld",&rem[i]);

    printf("Case %lld: %lld\n",t+1,f(0,k));
    }

    return 0;
}
