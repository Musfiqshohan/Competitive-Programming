#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<ll,ll>
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
#define rep(i,n) for(ll i=0;i<n;i++)
#define inf 10000000000
using namespace std;
ll n,m;

ll adj[105][105];
ll Graph[105][105], rGraph[105][105], parent[105],  d[105];

void clearr()
{
    ms(adj,0);
    ms(Graph,0);
    ms(rGraph,0);
    ms(parent,0);
    ms(d,0);
}
struct node
{
    ll city,dist;

    bool operator < (const node &n) const
    {
        return dist>n.dist;
    }
};


bool dijkstra(ll s, ll t)
{

    for(ll i=s; i<=t; i++) d[i]=inf;
    d[s]=0;

    node u= {s,0};

    priority_queue<node>pq;
    pq.push(u);

    while(!pq.empty())
    {
        node u= pq.top();
        pq.pop();

        for(ll v=0; v<=t; v++)
        {
            if(adj[u.city][v]>0 && rGraph[u.city][v]>0)
            {
                if(d[v]>d[u.city]+adj[u.city][v])
                {
                    d[v]=d[u.city]+adj[u.city][v];
                    parent[v]=u.city;
                    pq.push({v,d[v]});
                }
            }

        }
    }

    return (d[t]<inf);

}


ll fordfulkerson(ll s, ll t)
{

    for(ll i=1; i<=n; i++)
        for(ll j=1; j<=n; j++)
            rGraph[i][j]=Graph[i][j];

    ll total=0;

    //dijkstra(s,t);
    for(ll turn=0; turn<2; turn++)
    {
        if(dijkstra(s,t)==false)
            return -1;

        ll path_flow=INT_MAX;

        for(ll v=t; v!=s; v= parent[v])
        {
            ll u= parent[v];
            path_flow= min(path_flow,  rGraph[u][v]);
        }

        for(ll v=t; v!=s; v= parent[v])
        {
            ll u= parent[v];

          //  printf("%d-> %d = %d\n",u,v,adj[u][v]);
            total+= adj[u][v];

            rGraph[u][v]-=path_flow;
            rGraph[v][u]+=path_flow;
        }

      //  puts("");

       // cout<<path_flow<<endl;
    }

    total=0;
    for(ll i=1; i<=n; i++)
        for(ll j=1; j<=n; j++)
        {
            if(rGraph[i][j]==0)
                total+=adj[i][j];
        }


    return total;

}

int main()
{

    ll u,v,w;

    while(1)
    {

        scanf("%lld",&n);
        if(n==0) break;
        scanf("%lld",&m);

        for(ll i=0; i<m; i++)
        {
            scanf("%lld %lld %lld",&u,&v,&w);
            adj[u][v]=w;
            adj[v][u]=w;

            Graph[u][v]=1;
            Graph[v][u]=1;

        }


        ll res= fordfulkerson(1,n);
        if(res==-1)
            printf("Back to jail\n");
        else printf("%lld\n",res);

        clearr();

    }
    return 0;
}
