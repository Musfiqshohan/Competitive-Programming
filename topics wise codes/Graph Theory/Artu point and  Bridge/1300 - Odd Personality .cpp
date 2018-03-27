#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<int,int>
#define inf 100000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
using namespace std;


vector<int>adj[10009];
int vis[10009],  low[10009], disc[10009], par[10009], dis[10009], times,tot=0,flag=0;

set<pii>bridge;

void dfs(int src)
{
    disc[src]= low[src]= ++times;

    for(int i=0; i<adj[src].size(); i++)
    {
        int node= adj[src][i];

        if(vis[node]==0)
        {
            vis[node]=1;
            par[node]=src;

            dfs(node);

            low[src]= min(low[src], low[node]);

            if(low[node]>disc[src])
            {

                bridge.insert({ src,node});

            }
        }
        else if(node!= par[src])
        {
            low[src]= min (low[src], disc[node]);
        }
    }

}

int bfs(int src)
{

    queue<int>q;

    vis[src]=1;
    dis[src]=0;
    q.push(src);

    int tot_nodes=0;

    while(!q.empty())
    {
        int u= q.front();
        q.pop();

        tot_nodes++;

      //      puts("Hi");



        for(int i=0; i<adj[u].size(); i++)
        {
            int node= adj[u][i];


            if( bridge.find({u,node}) == bridge.end()  && bridge.find({node,u})== bridge.end() )
            {


                if(vis[node]==0)
                {
                    par[node]=src;
                    vis[node]=1;
                    dis[node]=dis[u]+1;

                  //  printf("%d-> %d\n",u, node);
                    q.push(node);
                }
                else if(node != par[u])
                {
                    if(dis[u]%2==dis[node]%2)
                    {
                        flag=1;
                    }
                }

            }
        }
    }

    return tot_nodes;

}



int main()
{
    int tt=0,test;
    cin>>test;

    while(tt<test)
    {

        int n,m,u,v;
        scanf("%d %d",&n,&m);

        for(int i=0; i<m; i++)
        {
            scanf("%d %d",&u,&v);


            adj[u].pb(v);
            adj[v].pb(u);
        }



        for(int i=0; i<n; i++)
        {
            if(vis[i]==0)
            {
                dfs(i);
            }
        }

        ms(vis,0);
        ms(par,0);

        tot=0;



        for(int i=0; i<n; i++)
        {
            if(vis[i]==0)
            {
                flag=0;


                int res= bfs(i);
                if(flag==1)
                    tot+=res;

            }


        }

        printf("Case %d: %d\n",++tt,tot);

        //puts("To");

        times=0;

        for(int i=0; i<=n; i++)
            adj[i].clear();

        bridge.clear();
        ms(par,0);
        ms(vis,0);

    }
    return 0;
}
