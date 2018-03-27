#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
long long a[55][1009][22];
long long coin[100], rem[100];
long long mod=100000007;
long long f(long long i, long long k,long long n)
{

    long long total1=0, total2=0;

    if(k==0) return 1;
    if(i==n) return 0;

    if(a[i][k][rem[i]]!=-1) return a[i][k][rem[i]];

    if( k -  coin[i] >=0 && rem[i]>0)
    {

        rem[i]--;
        total1= f(i , k - coin[i],n) %mod;
        rem[i]++;
    }
    else total1=0;

    total2= f(i+1, k,n)%mod;



    a[i][k][rem[i]]= ((total1%mod)+(total2%mod))%mod;
    return a[i][k][rem[i]];  //total1+total2;

}
int main()
{
    int t,test;
    scanf("%d",&test);
    for(t=0;t<test;t++){
    long long n,k,i;

    memset(a,-1,sizeof(a));
    memset(coin,0,sizeof(coin));
    memset(rem,0,sizeof(rem));

    scanf("%lld %lld",&n,&k);
    for(i=0;i<n;i++) scanf("%d",&coin[i]);
    for(i=0;i<n;i++) scanf("%d",&rem[i]);


    printf("Case %d: %lld\n",t+1,f(0,k,n));


    }

    return 0;
}
