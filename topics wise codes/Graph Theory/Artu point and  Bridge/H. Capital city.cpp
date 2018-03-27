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

vector<ll>adj[100009], edgex[100009], adjx[100009];
set<pii>bridge;
ll low[100009],disc[100009],par[100009],vis[100009], belongs[100009], times;
ll dis1[100009], dis2[100009];
ll n,m;
map<pii, ll>mp;


void clearr(ll n, ll m)
{
    for(ll i=1;i<=n+15;i++) adj[i].clear();
    for(ll i=1;i<=m+15;i++) { adjx[i].clear();  edgex[i].clear();  }

    ms(vis,0);
    ms(low,0);
    ms(par,0);
    ms(disc,0);
    ms(belongs,0);
    bridge.clear();
    ms(dis1,0);
    ms(dis2,0);
    mp.clear();

    times=0;

}

struct node
{
    ll city;
    ll dist;

    bool operator<(const node &n) const
    {
        if(dist==n.dist)
            return city>n.city;
        return dist>n.dist;
    }

};



void dijkstra(ll src, ll dis[])
{
    for(ll i=1; i<=n; i++) dis[i]=inf;
    dis[src]=0;

    node u;
    u.city=src;
    u.dist=0;
    priority_queue<node>pq;
    pq.push(u);

    while(!pq.empty())
    {
        node u= pq.top();
        pq.pop();

        for(ll i=0; i<adjx[u.city].size(); i++)
        {
            node v;
            v.city=adjx[u.city][i];
            v.dist= u.dist + edgex[u.city][i];

            if(v.dist< dis[v.city])
            {
                dis[v.city]=v.dist;
                pq.push(v);
            }
        }
    }
}


void dfs1(ll src)
{
    disc[src]=low[src]=++times;

    for(ll i=0; i<adj[src].size(); i++)
    {
        ll node= adj[src][i];

        if(vis[node]==0 && node!= par[src])
        {
            par[node]=src;
            vis[node]=1;

            dfs1(node);

            low[src]= min(low[src], low[node]);

            if(low[node]> disc[src])
            {
                bridge.insert({ min(src,node), max(src,node) });
                // prllf("%d -> %d\n",src, node);
            }
        }
        else if(node!= par[src])
        {
            low[src]= min(low[src], disc[node]);
        }
    }
}

void dfs2(ll src, ll p)
{
    belongs[src]=p;

    // prllf("%d belong to %d\n",src,p);

    for(ll i=0; i< adj[src].size(); i++)
    {
        ll node= adj[src][i];

        //   prllf("%d->%d in %d\n",src,node, p);
        if(bridge.find({src,node})== bridge.end()  &&  bridge.find({src,node})== bridge.end())
        {
            // prllf("But then %d->%d in %d\n",src,node, p);
            if(node!= par[src] && vis[node]==0)
            {
                par[node]=src;
                vis[node]=1;

                dfs2(node,p);

            }
        }

    }

}

int main()
{
    ll test;
    cin>>test;

    while(test--) {

    ll u,v,w;
    scanf("%lld %lld",&n,&m);


    for(ll i=1; i<=m; i++)
    {
        scanf("%lld %lld %lld",&u,&v,&w);

        adj[u].push_back(v);
        adj[v].push_back(u);
   // puts("Fuck");

        if( mp.find({min(u,v), max(u,v)})== mp.end())
            mp[{min(u,v), max(u,v)}]=w;
        else
            mp[{min(u,v), max(u,v)}]= min( mp[{min(u,v), max(u,v)}],  w )   ;
    }

    dfs1(1);

    ms(par,0);
    ms(vis,0);


    ll scc=0;
    for(ll i=1; i<=n; i++)
    {
        if(vis[i]==0)
        {
          //  prllf("scc= %d\n",i);
            vis[i]=1;
            dfs2(i,++scc);
        }
    }



    for( set<pii>:: iterator it= bridge. begin(); it!=bridge.end(); it++)
    {
         pii tp= (*it);

         ll u= tp.first;
         ll v= tp.second;

      //  printf("%d connects %d\n",u,v);

         ll len= mp[{min(u,v), max(u,v)}];
         u= belongs[u];
         v= belongs[v];

       //  printf("%d->%d %d\n",u,v,len);
         adjx[u].push_back(v);
         adjx[v].push_back(u);

         edgex[u].push_back(len);
         edgex[v].push_back(len);

    }

    dijkstra(1,dis1);

    ll mx=0,mxi=1;
    for(ll i=1; i<=scc; i++)
    {
        if(dis1[i]>mx)
        {
            mx=dis1[i];
            mxi=i;
        }
    }

    ll start=mxi;


    ms(dis1,0);
    dijkstra(start,dis1);


    mx=0,mxi=1;
    for(ll i=1; i<=scc; i++)
    {
        if(dis1[i]>mx)
        {
            mx=dis1[i];
            mxi=i;
        }
    }

    ll endd= mxi;


   // printf("start endd %d %d\n",start,endd);

    dijkstra(endd, dis2);

    mx=0;
    ll mn=inf,mni=1;


    for(ll i=1;i<=scc;i++)
    {
        mx=max(dis1[i], dis2[i]);

        if(mx<mn)
        {
            mn=mx;
            mni=i;
        }
    }

    for(int i=1;i<=n;i++)
    {
        if(belongs[i]==mni)
        {
            mni=i;
            break;
        }
    }

    printf("%lld %lld\n",mni, mn);


    clearr(n,scc);

    }

    return 0;
}
