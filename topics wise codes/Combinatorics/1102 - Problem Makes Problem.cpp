#include<bits/stdc++.h>
#define ll long long
using namespace std;


ll fact[3001109];
ll mod=1000000007;


ll pow1(ll x, ll n)
{
    if(n==0) return 1;
    if(n==1) return x%mod;

    if(n%2==0)
    {
        ll rem= pow1(x,n/2)%mod;
        return (rem*rem)%mod;
    }
    return ( x%mod * pow1(x,n-1)%mod )%mod;
}
int main()
{

    int i;

    fact[0]=1;
    for(i=1;i<=2000109; i++)
    {
        fact[i]=(fact[i-1]%mod* i%mod)%mod;
    }

    int t,test;
    cin>>test;
   for(t=0;t<test;t++){
    ll n,k,total1,total2, total;
    scanf("%lld %lld",&n,&k);

    total1= fact[n+k-1]%mod;

    total2= (fact[n]%mod * fact[k-1]%mod)%mod;

    total = (total1 %mod * pow1(total2, mod-2)%mod)%mod;

    printf("Case %d: %lld\n",t+1,total%mod );
    }

    return 0;

}
