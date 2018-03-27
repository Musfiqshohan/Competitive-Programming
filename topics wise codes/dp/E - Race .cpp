#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long

ll mod=10056;

ll ara[1009][1009];
ll dp[1009];
using namespace std;

ll nCr(ll n, ll r)
{
    if(r<=0) return 1;

    if(n==r) return 1;

    if(ara[n][r]!=-1) return ara[n][r];

    return ara[n][r]=(nCr(n-1,r)%mod + nCr(n-1,r-1)%mod)%mod;

}


ll f(ll n)
{
    //printf("%lld %lld\n",n,m);
    if(n<=0) return 1;

    if(dp[n]!=-1) return dp[n];

    ll total=0;

    for(ll i=0; i<n; i++)
    {
        total+= (ara[n][n-i] * f(i))%mod;
        total%=mod;

        // printf("%d %d\n",n-i,  i, m-i, )
    }

    return dp[n]=total;  //[m]=
}

int main()
{
    ms(ara,-1);
    ms(dp,-1);

    for(ll i=1; i<=1000; i++)
    {
        for(ll j=1; j<=i; j++)
        {
            ara[i][j]=nCr(i,j);
        }
    }

   // cout<<f(3)<<endl;

    int t=0,test;

    cin>>test;

    while(t<test)
    {

        ll n;
        cin>>n;

        // cout<<f(n,n)<<endl;

        printf("Case %d: %lld\n",++t,f(n)%mod);
//
    }
    return 0;
}
