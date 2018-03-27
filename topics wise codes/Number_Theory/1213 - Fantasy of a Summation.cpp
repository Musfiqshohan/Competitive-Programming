#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll mod;
ll pow1(ll x, ll n)
{

    if(n==0) return 1%mod;

    else if( n %2 ==0 )
    {
        ll num= pow1(x,n/2)%mod;
        return (num%mod*num%mod)%mod;
    }

    return ( x%mod * pow1(x,n-1)%mod)%mod;

}
int main()
{
    int t,test;
    scanf("%d",&test);
    for(t=0;t<test;t++){

    ll n,k,total,x,sum=0,i;
    scanf("%lld %lld %lld",&n,&k,&mod);

    for(i=0;i<n;i++)
    {
        scanf("%lld",&x);
        sum+=x;
    }


    total =((( (sum%mod) * (k%mod) )%mod )* (pow1(n,k-1)%mod)%mod)%mod;
    printf("Case %d: %lld\n",t+1,total);

    }
    return 0;
}
