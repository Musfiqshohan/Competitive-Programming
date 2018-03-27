#include<bits/stdc++.h>
using namespace std;

long long dp[55][55][55];
long long f(long long n, long long m, long long k)
{

    if(n==0 && m==0)
        return 1;
    else if(n<=0 || m<=0) return 0;


    if(dp[n][m][k]!=-1) return dp[n][m][k];
    long long tot=0;
    for(long long i=1;i<=k;i++)
    {
        tot+= f(n-i, m-1, k);

    }


    return dp[n][m][k]=tot;

}

int main()
{
    memset(dp,-1,sizeof dp);

    long long tt=0,test;
    cin>>test;

    while(tt<test) {
    long long n,k,m;
    scanf("%lld %lld %lld",&n,&m,&k);

     printf("Case %lld: %lld\n",++tt, f(n,m,k));

    }
}
