#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define inf 1000000000000
using namespace std;

ll ara[10009], dp[10009];

 ll  l1,l2,l3, c1,c2,c3, n,x,y;

ll f(ll pos)
{
    if(pos==y) return 0;

    if(dp[pos]!=-1) return dp[pos];

    ll mn=inf, cost=0;
    for(ll i=pos+1; i<=y;i++)
    {
        ll dist= ara[i]-ara[pos];

        if(dist<=l1)
            cost= c1+ f(i);
        else if(dist<=l2)
            cost= c2+ f(i);
        else if(dist<=l3)
            cost= c3+ f(i);
        //else cost=inf;

        mn= min(mn,cost);
    }

    return dp[pos]=mn;

}

int main()
{

    ms(dp,-1);
    scanf("%lld %lld %lld %lld %lld %lld", &l1,&l2,&l3,&c1,&c2,&c3);
    scanf("%lld",&n);
    scanf("%lld %lld",&x,&y);

    if(y<x) swap(x,y);

    for(ll i=2;i<=n;i++)
        scanf("%lld",&ara[i]);

    cout<<f(x)<<endl;





    return 0;
}
