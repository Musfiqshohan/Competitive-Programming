#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[5019],sum[5019],dp[5019][5019];
ll n,m,k;


ll f(ll i, ll k)
{
    ll total1=0,total2=0,t;
    if(i+m-1>=n || k==0) return 0;

    if(dp[i][k]!=-1) return dp[i][k];
//    if(k%2==1)
//    {
//
//        total1= sum[i]+ f(i+1, k-1);
//    }
//
//    if(k%2==0)
//    {
//
//        total1= - sum[i] + a[i] + f(i+m-1,k-1);
//
//        total2= f(i+1,k);
//    }


    if(i+m-1<n)
    {
        total1= sum[i+m-1] - sum[i] + a[i] +  f(i+m,k-1);

    }

    total2= f(i+1,k);

    return dp[i][k] = max(total1,total2);

}

int main()
{
    memset(dp,-1,sizeof dp);
    ll x,i,sm=0;
    scanf("%lld %lld %lld",&n,&m,&k);

//    if(n<2*k)
//    {
//        printf("0\n");
//        return 0;
//    }
    for(i=0; i<n; i++)  scanf("%lld",&a[i]);


    for(i=0; i<n; i++)
    {
        sm+=a[i];
        sum[i]=sm;
    }



    cout<<f(0,k);

    return 0;
}
