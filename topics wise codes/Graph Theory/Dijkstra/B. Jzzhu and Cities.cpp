#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<ll,ll>
#define inf 100000000000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
using namespace std;

vector<ll>adj1[100009],road[100009], adj2[100009], railway[100009];
map< pii, ll> mp;

vector<ll>vec;
ll dis[100009],vis[100009], inQ[100009];

ll n,m,k;
struct node
{
    ll city, dist;

    bool operator < (const node &n)const
    {

        return dist>n.dist;
    }
};


void dijkstra(ll src)
{
    for(ll i=1; i<=n; i++)
        dis[i]=inf;

    dis[src]=0;
    vis[src]=1;

    priority_queue<node>pq;
    pq.push({src,0});

    while(!pq.empty())
    {
        node u=pq.top();
        pq.pop();

        inQ[u.city]=0;
        for(ll i=0; i<adj1[u.city].size(); i++)
        {
            node v;
            v.city= adj1[u.city][i];
            v.dist= dis[u.city] + road[u.city][i];

            if(v.dist < dis[v.city])
            {
                if( mp[ {1, v.city}]==1 )
                    mp[ {1,v.city}]=0;

                dis[v.city]=v.dist;

                if(inQ[v.city]==0)
                {
                    pq.push(v);
                    inQ[v.city]=1;
                }
            }

            if(v.dist== dis[v.city])
            {
                if( mp[ {1, v.city}]==1 )
                    mp[ {1,v.city}]=0;

            }


        }




        for(ll i=0; i<adj2[u.city].size(); i++)
        {
            node v;
            v.city=adj2[u.city][i];
            v.dist= dis[u.city]+ railway[u.city][i];

            if(v.dist<dis[v.city])
            {

                mp[ { min(u.city,v.city), max(u.city,v.city)}]=1;

                dis[v.city]=v.dist;

                if(inQ[v.city]==0)
                {
                    pq.push(v);
                    inQ[v.city]=1;
                }
            }
        }

    }


}


int main()
{

    ll u,v,w;

    scanf("%lld %lld %lld",&n,&m,&k);
    for(ll i=0; i<m; i++)
    {
        scanf("%lld %lld %lld",&u,&v,&w);

        adj1[u].push_back(v);
        road[u].push_back(w);

        adj1[v].push_back(u);
        road[v].push_back(w);
    }

    for(ll i=0; i<k; i++)
    {
        scanf("%lld %lld",&v,&w);
        vec.push_back(v);

        adj2[1].push_back(v);
        railway[1].push_back(w);

        adj2[v].push_back(1);
        railway[v].push_back(w);

    }

    dijkstra(1);

    ll cnt=0;
    for(ll i=0; i<vec.size(); i++)
    {
        ll v=vec[i];

        if(mp[ {1,v}]==1)
            cnt++;
        mp[ {1,v}]=0;
    }


    printf("%lld\n", vec.size()-cnt);




    return 0;
}
