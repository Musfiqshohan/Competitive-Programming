#include <iostream>
#include <vector>
#include <algorithm>
#include<stdio.h>
#include <cstdio>
#include <cstring>
#include<stdio.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<ll,ll>
#define inf 100000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
using namespace std;
ll mod=1000000000;
//ll dp[10000005][33];
ll pow1(ll x, ll n)
{
    if(n==0)return 1;
    if(n%2==0)
    {
        ll res= pow1(x,n/2);
        return res*res;
    }

    return x*pow1(x,n-1);
}

ll f(ll n,ll cnt)
{
    printf("%d\n",n);
    if(n==0)
    {
        return 1;
    }

    if(n<0) return 0;

   // if(dp[n][cnt]!=-1) return dp[n][cnt];

    ll twos=pow1(2,cnt),tot=0, incr=cnt;

    ll t1= f(n-pow1(2,cnt+1), cnt+1);
    ll t2= f(n, cnt+1)

    //return dp[n][cnt]=tot%mod;
    return tot%mod;
}


int main()
{
//    ms(dp,-1);

    f(1000000,0);
//    ll n;
//    scanf("%lld",&n);
//
//    printf("%lld\n",f(n,0));
}
