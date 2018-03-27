#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<ll,ll>
#define inf 100000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
using namespace std;
ll deg[20];

ll Set(ll N,ll pos)
{
    return N=N | (1<<pos);
}
ll reset(ll N,ll pos)
{
    return N= N & ~(1<<pos);
}
bool check(ll N,ll pos)
{
    return (bool)(N & (1<<pos));
}

struct poll
{
    ll x,y;
} ara[20];
ll sz, dp[1<<16], opt[20][20];



vector<ll>iso;
ll dis (ll i, ll j)
{
    ll x1=ara[i].x, y1= ara[i].y;
    ll x2=ara[j].x, y2=ara[j].y;

    return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}

ll f(ll mask)
{
    ll x= __builtin_popcount(mask);

    if(sz-x<=2)
        return 0;

    if(dp[mask]!=-1) return dp[mask];
    ll mn=inf;
    for(ll i=0; i<sz-1; i++)
    {

        for(ll j=i+1; j<sz ; j++)
        {
            if(check(mask,i)==0 && check(mask,j)==0)
            {
                ll par=mask;

                par= Set(par,i);
                par= Set(par,j);
                //mn= min(mn, dis(iso[i],iso[j])+ f(par) );
                mn= min(mn, opt[iso[i]][iso[j]]+ f(par) );
            }

        }

    }

    return dp[mask]=mn;

}

int main()
{
    int t=0,test;
    scanf("%d",&test);


    while(t<test)
    {

        ms(dp,-1);
        ll n;
        scanf("%lld",&n);

        for(ll i=0; i<n; i++)
        {
            scanf("%lld %lld",&ara[i].x, &ara[i].y);
        }

        for(ll i=0; i<n; i++)
            for(ll j=0; j<n; j++)
            {
                opt[i][j]= dis(i,j);
            }

        for(ll k=0; k<n; k++)
            for(ll i=0; i<n; i++)
                for(ll j=0; j<n; j++)
                {
                    if(opt[i][k]+ opt[k][j] < opt[i][j])
                        opt[i][j]= opt[i][k] + opt[k][j];
                }


        ll m,u,v;
        scanf("%lld",&m);

        for(ll i=0; i<m; i++)
        {
            scanf("%lld %lld",&u,&v);

            deg[u]++;
            deg[v]++;
        }

        for(ll i=0; i<n; i++)
        {
            if(deg[i]%2==1)
                iso.push_back(i);
        }


        sz= iso.size();

        printf("Case %d: %lld\n",++t,f(0));

        iso.clear();
        ms(ara,0);
        ms(deg,0);


    }
    return 0;
}
