#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
#define pari pair<int,int>
#define ll long long
#define inf 100000000000009
using namespace std;

vector<int>adj[109];
vector<int>edge[109];

pair<int,int>par[109];
ll dist[109];
bool vis[109];
int n;

void clearr()
{
    ms(dist,0);
    ms(par,0);

    ms(vis,0);
}

void dijkstra()
{
    dist[1]=0;
    multiset<pair<int,int> >s;
    s.insert({0,1});
    par[1]= {1,0};

    while(!s.empty())
    {
        pair<int,int> temp= *s.begin();
        s.erase(s.begin());


        int u=temp.second;
        if(vis[u]==true) continue;
        vis[u]=true;

        for(int i=0; i<adj[u].size(); i++)
        {
            int node= adj[u][i];

            if(dist[u]+edge[u][i]< dist[node])
            {
                dist[node]=dist[u]+edge[u][i];
                s.insert({dist[node],node});

                 // printf("%d %d ->%d\n",u,node,edge[u][i]);
                par[node]= {u,edge[u][i]};
            }


        }



    }


}

int main()
{
    int t=0,test;
    cin>>test;

    while(t<test)
    {
        int m,u,v,w,total=0;

        getchar();
        scanf("%d %d",&n,&m);

        for(int i=0; i<m; i++)
        {
            scanf("%d %d %d",&u,&v,&w);
            adj[u].pb(v);
            adj[v].pb(u);

            edge[u].pb(w);
            edge[v].pb(w);
        }

        for(int i=1; i<=n; i++) dist[i]=inf;

        dijkstra();

        int x=n;

        printf("Case %d: ",++t);
        if(dist[n]==inf) printf("Impossible\n");
        else
        {
            while(par[x].first!=x)
            {
                //printf("%d\n",par[n].first);
                total+=par[x].second;
                x=par[x].first;
            }

            cout<<total<<endl;
        }
        for(int i=0;i<=n;i++){ edge[i].clear(); adj[i].clear(); }

        clearr();

    }
    return 0;
}

