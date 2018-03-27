#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll mod=1000000007;
ll pow1(ll x, ll n)
{
    if(n==0) return 1;
    if(n%2==0)
    {
        ll rem= pow1(x,n/2);
        return (rem%mod * rem %mod)%mod;
    }

    return (x%mod * pow1(x, n-1))%mod;
}
int main()
{
    ll n;
    scanf("%lld",&n);

    printf("%lld\n", (pow1(3,3*n)%mod - pow1(7, n)%mod  +mod)%mod );
}
