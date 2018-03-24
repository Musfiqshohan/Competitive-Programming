#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<ll,ll>
#define inf 100000000000
#define  mod 1000000007
using namespace std;
ll k,n;
ll dp[100009][11];
ll f(ll n)
{
    if(n<0) return 0;

    if(n==0) return 1;

    if(dp[n][k]!=-1) return dp[n][k];

    ll t1= f(n-k);

    ll t2= f(n-1);

    return dp[n][k]=(t1%mod+t2%mod)%mod;
}

int main()
{
        ms(dp,-1);
    ll t=0,test;

    scanf("%lld",&test);

    while(t<test)
    {

        scanf("%lld %lld",&k,&n);
        for(int i=3;i<=100;i++){}
        printf("Case %lld: %lld\n",++t,f(n));

    }

    return 0;
}
