#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define inf 1000000000000000
#define pii pair<ll,ll>
using namespace std;
pii ara[400][400];
vector<string>name;
int main()
{
    freopen("trip.in","r",stdin);
    freopen("trip.out","w",stdout);

    ll n,m,u,v;
    ll w;
    scanf("%lld %lld",&n,&m);



    for(ll i=1; i<=n; i++)
        for(ll j=1; j<=n; j++)
        {
            if(i==j)
                ara[i][j]= {0,0};
            else ara[i][j]= {inf,inf};
        }


    for(ll i=0; i<m; i++)
    {
        scanf("%lld %lld %lld",&u,&v,&w);
        ara[u][v]= {min(ara[u][v].first,w),1};
        ara[v][u]= {min(ara[v][u].first,w),1};
    }

    for(ll k=1; k<=n; k++)
        for(ll i=1; i<=n; i++)
            for(ll j=1; j<=n; j++)
            {
                if(ara[i][k].first+ara[k][j].first<ara[i][j].first)
                {
                    ara[i][j].first=ara[i][k].first+ara[k][j].first;
                    ara[i][j].second=ara[i][k].second+ara[k][j].second;
                }
                else if(ara[i][k].first+ara[k][j].first==ara[i][j].first)
                {
                    if(ara[i][k].second+ara[k][j].second<ara[i][j].second)
                        ara[i][j].second=ara[i][k].second+ara[k][j].second;
                }
            }


    double tot=0, cnt=0;

    for(ll i=1; i<=n; i++)
    {
        for(ll j=i+1; j<=n; j++)
        {
            tot+=ara[i][j].second;
            cnt++;
        }
    }


    cout<<fixed<<setprecision(10)<<tot/cnt<<endl;

    return 0;
}
