#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[1100][1100] , comb[1100][1100], factorial[1100];
ll mod=1000000007;

ll fact(ll n)
{
    if(n==1 || n==0 ) return 1;
    if(factorial[n]!=-1) return factorial[n];

    return factorial[n]= (n* fact(n-1)%mod )%mod;
}
ll f(ll n, ll m)
{
    ll total1,total2;
    if(m==0) return fact(n);
    if(m==1) return (fact(n-1) * (n-1)%mod)%mod;

    if(dp[n][m]!=-1)  return dp[n][m];
    total1= ((m-1)%mod * f(n-1, m-2)%mod)%mod;
    total2= ((n-m)%mod * f(n-1,m-1)%mod)%mod;

    return dp[n][m]=(total1+total2)%mod;
}
ll nCr( ll n , ll r)
{
    ll total;
    if(r==0)return 1;
    if(n==r) return 1;
    if(r==1) return n;

    if(comb[n][r]!=-1) return  comb[n][r];
    total= (nCr(n-1, r)%mod + nCr( n-1, r-1 )%mod)%mod;

    return comb[n][r]=total;
}

int main()
{
    int t,test;
    scanf("%d",&test);
    memset(dp,-1,sizeof(dp));
    memset(comb, -1, sizeof(comb));
    memset(factorial, -1,sizeof(factorial));

    for(t=0 ; t<test; t++)
    {
        ll n,m,k,total,r;
        scanf("%lld %lld %lld",&n,&m,&k);

        if(m-k<k) r=m-k;
        else r=k;

        total= (nCr(m,r)%mod * f(n-k, m-k)%mod)%mod ;
        printf("Case %d: %lld\n",t+1,total);

    }

    return 0;
}
