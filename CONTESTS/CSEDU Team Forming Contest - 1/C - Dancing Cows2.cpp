#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define inf 100000000000099
using namespace std;

ll a1[5009], a2[5009], dp[5009][5009];
ll n,m;
ll f(ll i, ll j)
{
    if(i>=n) return 0;
    if(j>=m) return inf;

    if(dp[i][j]!=-1) return dp[i][j];
    ll t1=0,t2=0;

    t1= abs(a2[j]-a1[i]) + f(i+1,j+1);

    t2= f(i,j+1);

    return dp[i][j]=min(t1,t2);

}

int main()
{

    ms(dp,-1);

    scanf("%lld %lld",&n,&m);

    for(ll i=0;i<n;i++)
        scanf("%lld",&a1[i]);

    sort(a1,a1+n, greater<ll>());

    for(ll i=0;i<m;i++)
        scanf("%lld",&a2[i]);
    sort(a2,a2+m, greater<ll>());

    printf("%lld\n",f(0,0));


    return 0;
}
