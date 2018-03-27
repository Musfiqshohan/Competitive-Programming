#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<ll,ll>
#define inf 100000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
#define rep(i,n) for(ll i=0;i<n;i++)
using namespace std;
ll n;
ll ara[100009];
ll f(ll ergy)
{
    ll init=0;
    rep(i,n)
    {
        ll dif=ara[i]-init;

      //  printf("%lld %lld\n",dif,ergy);

        if(dif==ergy)
            ergy--;
        else if(dif>ergy) return -1;

        init=ara[i];

    }

    return 1;
}

int main()
{
    int test,t=0;
    cin>>test;

    while(t<test) {

    scanf("%lld",&n);
    rep(i,n)
    scanf("%lld",&ara[i]);

    ll low=1,high=1000000000000,mid;

    ll cnt=64;
    while(cnt--)
    {
        mid= low+ (high-low)/2;

        if(f(mid)==1)
            high=mid;
        else
            low=mid;

    }

    if(f(mid)==-1) mid++;

    printf("Case %d: %lld\n",++t,mid);

    }
    return 0;
}
