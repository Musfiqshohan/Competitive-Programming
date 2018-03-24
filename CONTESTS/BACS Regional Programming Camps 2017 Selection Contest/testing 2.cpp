#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<ll,ll>
#define inf 100000000000
#define  mod 1000000007
using namespace std;

ll ara[40009];
ll f(ll l, ll r,ll d)
{
    ll cnt=0,t=0;

    for(ll i=l ;i<=r;i++)
    {
        t+=   ((1+ (cnt%mod*d%mod)%mod)* (ara[i]%mod)) %mod;
        cnt++;
    }
    return t;
}


int main()
{
    ll test,t=0;

    scanf("%lld",&test);

    while(t<test) {

    printf("Case %lld:\n",++t);

    ll n,q,x,y,d,cs;

    scanf("%lld %lld",&n,&q);


    for(ll i=1;i<=n;i++)
        scanf("%lld",&ara[i]);

    for(ll i=1;i<=q;i++)
    {
        scanf("%lld %lld %lld %lld",&cs,&x,&y,&d);
        if(cs==2)
        printf("%lld\n", f(x,y,d));
    }
    }

   // return 0;
}
