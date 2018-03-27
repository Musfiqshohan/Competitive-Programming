#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll fact[2017];
ll mod=1000000007;
ll pow2(ll i)
{
    if(i%2==0) return 1;
    else return -1;
}

ll pow1(ll x, ll n)
{
    if(n==0) return 1;
    if(n%2==0)
    {
        ll rem= pow1(x,n/2);
        return (rem * rem)%mod;
    }

    return (x%mod * pow1( x, n-1))%mod;
}
ll nCr(ll n, ll r)
{
    ll total1,total2,total;

    total1 = fact[n];
    total2= (fact[n-r] * fact[r])%mod;



    total = (total1  * pow1( total2 , mod-2) )%mod;


    return total;

}
int main()
{

    ll i;
    fact[0]=1;

    for( i=1;i<=2017;i++)
       {
           fact[i]=(i*fact[i-1])%mod;

       }

    int t,test;
    scanf("%d",&test);
    for(t=0;t<test;t++) {

    ll n,m,k,r,total=0,num1;
    scanf("%lld %lld %lld",&n,&m,&k);

    ll p= n-m;
     r=m-k;


    num1= nCr(m,k);

    total =  fact[p+r];



    for(i=1;i<=r; i++)
    {
        total=(total +   pow2(i) * (nCr(r,i) * fact[p + r - i] )%mod + mod ) %mod;

    }


    printf("Case %d: %lld\n",t+1,(total*num1)%mod);

    }


    return 0;
}
