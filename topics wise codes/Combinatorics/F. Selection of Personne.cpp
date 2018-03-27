#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[1000][1000];
ll nCr(ll n, ll r)
{
    if(n==r || r==0) return 1;

    if(dp[n][r]!=-1) return dp[n][r];
    return dp[n][r]= nCr(n-1,r-1) + nCr(n-1,r);

}

int main()
{
    memset(dp,-1,sizeof dp);
    ll n;
    scanf("%lld",&n);

    printf("%lld\n", nCr(n,5)+nCr(n,6)+ nCr(n,7) );
}
