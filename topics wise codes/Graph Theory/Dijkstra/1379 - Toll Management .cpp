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
vector<ll>edge1[10009], edge2[10009];

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
        {adj1[i].clear(), adj2[i].clear();  edge1[i].clear(); edge2[i].clear(); }




}


void bfs(ll src, ll dis[], vector<ll>adj[], vector<ll>edge[])
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
            v.dist= edge[u.city][i] + u.dist;

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

        adj1[u].push_back(v);
        edge1[u].push_back(w);

        adj2[v].push_back(u);
        edge2[v].push_back(w);

    }


    bfs(s,dis1,adj1,edge1);
    bfs(t,dis2,adj2,edge2);


    ll mx =-1;
    for(ll i=1; i<=n; i++)
    {
        for(ll j=0;j<adj1[i].size();j++){


        u=i;
        v=adj1[i][j];

        w= edge1[i][j];

        if(dis1[u]+w+dis2[v] <=p )
        {
           //  prllf("(%d=)%d  + %d  + (%d=)%d\n",u,dis1[u],w,v,dis2[v]);
            mx= max(mx, w);

        }

        }

    }

  //  if(s==t) mx=-1;
//
    printf("Case %lld: %lld\n",++tt,mx);

    clearr();

    }

    return 0;
}

