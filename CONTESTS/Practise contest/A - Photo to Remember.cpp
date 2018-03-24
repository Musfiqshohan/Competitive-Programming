#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define pii pair<ll,ll>
#define ll long long
using namespace std;
ll mx1,mx2;
pii p[200009];

void store(ll num)
{
    if(num>=mx1)
    {
        mx2=mx1;
        mx1=num;
    }
    else if(num>=mx2)
        mx2=num;

    return;
}

int main()
{
    ll n,sum=0;
    scanf("%lld",&n);

    for(ll i=0;i<n;i++)
    {
        scanf("%lld %lld",&p[i].first, &p[i].second);

        sum+=p[i].first;
        store(p[i].second);
    }


    for(ll i=0;i<n;i++)
    {
        ll w=sum- p[i].first;
        ll h;
        if(p[i].second==mx1)
            h=mx2;
        else h=mx1;

        printf("%lld ",w*h);
    }

    puts("");


    return 0;
}
