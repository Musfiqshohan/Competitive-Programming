#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll fact[50];

ll gcd(ll a, ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
ll nCr(ll n, ll r)
{
    if(n<r) return 0;
    if(r==0) return 1;

    ll total=0;

    total = fact[n] / ( fact[n-r] * fact[r] );

    ll a[40],b[40],i,j;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));

    for(i=0; i<r ;i++) a[i]=n--;

    for(i=0; r ; i++) b[i]=r--;

    for(i=0; b[i] ; i++)
    {
        for(j=0; a[j] ; j++)
        {
            ll x= gcd(a[j], b[i]);
            a[j]/=x;
            b[i]/= x;
            if(b[i]==1) break;
        }
    }

    ll sum=1;
    for(i=0; a[i] ; i++) sum*=a[i];

    return sum;

}
int main()
{
    ll i;

    fact[0]=1;
    for(i=1;i<35; i++) fact[i]= i* fact[i-1];


    ll n,m,t,total=0;
    scanf("%lld %lld %lld",&n,&m,&t);


    t-=5;




    for(i=0;i<=t ; i++)
    {
        total+= nCr(n, 4+i) * nCr(m, t-i+1);

    }

    printf("%lld \n", total);


    return 0;
}
