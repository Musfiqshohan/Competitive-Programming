#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define inf 30000000999
#define pii pair<ll,ll>

using namespace std;

ll n,m, vis[10009],dis1[10009], dis2[10009];

vector<ll>adj1[10009], adj2[10009];
map<pii,ll>mp1,mp2;

struct info
{
    ll u,v,w;
};

vector<info>vec;

struct node
{
    ll city,dist;

    bool operator < (const node &n) const
    {

        if(dist==n.dist)
            return city>n.city;
        return dist>n.dist;
    }

};


void clearr()
{
    ms(vis,0);
    ms(dis1,0);
    ms(dis2,0);

    for(ll i=0;i<=n;i++)
        adj1[i].clear(), adj2[i].clear();

    vec.clear();
    mp1.clear();
    mp2.clear();

}


void bfs(ll src, ll dis[], vector<ll>adj[], map<pii,ll>mp)
{
    for(ll i=1; i<=n; i++)
        dis[i]=inf;

    ms(vis,0);
    vis[src]=1;
    dis[src]=0;


    node u= {src,0};
    priority_queue<node>pq;
    pq.push(u);

    while(!pq.empty())
    {
        node u=pq.top();
        pq.pop();
        for(ll i=0; i<adj[u.city].size(); i++)
        {
            node v;
            v.city= adj[u.city][i];
            v.dist= mp[ {u.city,v.city}] + u.dist;
            if(dis[v.city] > v.dist)
            {
                dis[v.city]=v.dist;
                pq.push(v);
            }
        }
    }

}



int main()
{

    ll tt=0,test;
    cin>>test;

    while(tt<test) {
    ll s,t,p,u,v,w;
    scanf("%lld %lld %lld %lld %lld",&n,&m,&s,&t,&p);

    for(ll i=1; i<=m; i++)
    {
        scanf("%lld %lld %lld",&u,&v,&w);

        vec.push_back({u,v,w});

        adj1[u].push_back(v);
        adj2[v].push_back(u);

        if(mp1[{u,v}]!=0)
        mp1[{u,v}]= min(mp1[{u,v}],w);
        else mp1[{u,v}]=w;


        if(mp2[{v,u}]!=0)
            mp2[{v,u}]= min( mp2[{v,u}], w);
        else mp2[{v,u}]=w;

    }


    bfs(s,dis1,adj1,mp1);
    bfs(t,dis2,adj2,mp2);


    ll mx =-1;
    for(ll i=0; i<vec.size(); i++)
    {
        u=vec[i].u;
        v=vec[i].v;
        w=vec[i].w;

        if(dis1[u]+w+dis2[v] <=p )
        {
           //  prllf("(%d=)%d  + %d  + (%d=)%d\n",u,dis1[u],w,v,dis2[v]);
            mx= max(mx, w);

        }

    }

   // if(s==t) mx=-1;
//
    printf("Case %lld: %lld\n",++tt,mx);

    clearr();

    }

    return 0;
}

