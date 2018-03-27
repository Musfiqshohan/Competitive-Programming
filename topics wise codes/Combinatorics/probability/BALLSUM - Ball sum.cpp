#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll f(ll k)
{
    ll n;
    if(k%2==0)
        n=k/2 -1;
    else n=k/2;

    ll sum1= k*(n);

    ll sum2=  n*(n+1);

    return sum1-sum2;

}

int main()
{
    while(1){
    ll n,k;
    scanf("%lld %lld",&n,&k);

    if(n==-1 && k==-1) break;

    ll deno= n*(n-1);
    deno/=2;

    ll numo= f(k);

    ll gcd= __gcd(numo, deno);

    numo/=gcd;
    deno/=gcd;

    //cout<<numo<<" "<<deno<<endl;
    if(numo==0) printf("0\n");
    else if(numo==deno) printf("1\n");
    else
    printf("%lld/%lld\n",numo,deno);

    }

}
