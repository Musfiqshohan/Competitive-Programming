#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<int,int>
#define inf 10000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
using namespace std;
vector<int>adj[109],edge[109];
int fuel_cost[109],dist[109][109],vis[109][109];
int n,m;
struct node
{
    int u,fuel,cost;

    bool operator <(const node &n)const
    {
        if(cost==n.cost)
            return fuel<n.fuel;
        return cost>n.cost;
    }
};


void clearr(int n)
{
    for(int i=0; i<=n; i++) adj[i].clear(), edge[i].clear();
    ms(fuel_cost,0);
    ms(dist,0);
    ms(vis,0);
}


int dijkstra(int src, int term, int cap)
{
    ms(vis,0);

    for(int i=0; i<=100; i++)
        for(int j=0; j<=100; j++)
            dist[i][j]=inf;


    dist[src][0]=0;
    priority_queue<node>pq;
    pq.push({src,0,0});

    while(!pq.empty())
    {
        node tp=pq.top();
        pq.pop();

        int u=tp.u;
        int fuel=tp.fuel;
        int cost=tp.cost;

        if(vis[u][fuel]==1) continue;
        vis[u][fuel]=1;

        if(u==term) return cost;

        for(int i=0; i<adj[u].size(); i++)
        {
            int v= adj[u][i];

            int lower_lim=edge[u][i];

            //  printf("%d->%d\n",u,v);

            for(int i=lower_lim; i<=cap; i++)
            {
                int dif=0;

                if(i>fuel)
                {
                    dif=i-fuel;



                    if(cost+ dif*fuel_cost[u] < dist[v][i-lower_lim])
                    {
                        // printf("%d->%d = %d <%d?\n",u,v,cost+ dif*fuel_cost[u],dist[v][i-lower_lim]);

                        dist[v][i-lower_lim]=cost+ dif* fuel_cost[u];
                        pq.push({v, i-lower_lim, dist[v][i-lower_lim]});
                    }

                }
                else
                {
                    if(cost+ dif* fuel_cost[u] < dist[v][fuel-lower_lim])
                    {
                        dist[v][fuel-lower_lim]= cost;
                        pq.push({v, fuel-lower_lim, dist[v][fuel-lower_lim]});
                    }
                }




            }

        }

    }


    return -1;

}


int main()
{
    int tt=0,test;
    cin>>test;

    while(tt<test)
    {

        printf("Case %d:\n",++tt);

        int u,v,w,start,term,cap,q;
        scanf("%d %d",&n,&m);

        for(int i=0; i<n; i++)
            scanf("%d",&fuel_cost[i]);

        for(int i=0; i<m; i++)
        {
            scanf("%d %d %d",&u,&v,&w);

            adj[u].push_back(v);
            edge[u].push_back(w);

            adj[v].push_back(u);
            edge[v].push_back(w);

        }

        scanf("%d",&q);

        //  puts("ans:");

        for(int i=0; i<q; i++)
        {
            scanf("%d %d %d",&cap,&start,&term);

            int ret=dijkstra(start,term,cap);

            if(ret==-1) printf("impossible\n");
            else printf("%d\n",ret);
        }

        clearr(n);

    }

    return 0;
}
