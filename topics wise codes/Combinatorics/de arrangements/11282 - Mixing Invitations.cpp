#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[30][30];
ll b[30];
ll nCr(ll n, ll r)
{
    ll total=0;
    if(r==0) return 1;
    if(n==r) return 1;

    if(a[n][r]!=0) return a[n][r];
    a[n][r]=nCr(n-1,r-1) + nCr(n-1,r);

    return a[n][r];
}

ll d(ll n)
{
    if(n==1) return 0;
    if(n==0) return 1;
    if(n==2) return 1;

    if(b[n]!=-1) return b[n];
    b[n]=(n-1)*(d(n-1) + d(n-2));

    return b[n];
}
int main()
{
    ll n,m;
    while(scanf("%lld %lld",&n,&m)==2){
    ll i,total=0;
    memset(b,-1,sizeof(b));
    for(i=0; i<=m; i++)
    {
        total+= nCr(n,i) *  d(n-i);
    }
    printf("%lld\n",total);
    }

    return 0;
}
