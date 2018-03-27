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

vector<int>adj[100009];

int times=0, vis[100009], dis[100009], disc[100009], low[100009], par[100009], cnt=0;
set<pii>bridge;

void clearr(int n)
{
    ms(vis,0);
    ms(dis,0);
    ms(disc,0);
    ms(low,0);
    ms(par,0);
    cnt=0;
    times=0;
    bridge.clear();

    for(int i=1;i<=n;i++)
        adj[i].clear();

}

void bfs(int src)
{
    queue<int>q;
    q.push(src);
    vis[src]=1;
    dis[src]=0;

    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<adj[u].size();i++)
        {
            int node= adj[u][i];

            if(vis[node]==0 && node!= par[u])
            {

                par[node]=u;
                //printf("%d->%d\n",u,node);
              //  printf("is %d %d a bridge\n",u,node);
                if(bridge.find({ min(u,node), max(u,node) }) != bridge.end())
                    dis[node]= dis[u]+1;
                else dis[node]=dis[u];

                vis[node]=1;
                q.push(node);
            }
        }
    }

}

void dfs1(int src)
{
    disc[src]=low[src]=++times;

    for(int i=0;i<adj[src].size();i++)
    {
        int node= adj[src][i];

        if(vis[node]==0 && node!= par[src])
        {
            par[node]=src;
            vis[node]=1;

            dfs1(node);

            low[src]= min(low[src], low[node]);

            if(low[node]> disc[src])
            {
                bridge.insert({ min(src,node), max(src,node) });
               // printf("%d -> %d\n",src, node);
            }
        }
        else if(node!= par[src])
        {
            low[src]= min(low[src], disc[node]);
        }
    }
}

int main()
{
    int test;
    cin>>test;

    while(test--) {

    int n,m,u,v;
    scanf("%d %d",&n,&m);

    for(int i=0;i<m;i++)
    {
        scanf("%d %d",&u,&v);

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs1(1);

    ms(vis,0);
    ms(par,0);
    bfs(1);



//    for(int i=1;i<=n;i++)
//        printf("i=%d %d\n",i,dis[i]);

    int mx=0,mxi=0;
    for(int i=1;i<=n;i++)
    {
        if(dis[i]>=mx)
        {
            mx= dis[i];
            mxi=i;
        }
    }

    int start=mxi;
    ms(vis,0);
    ms(dis,0);
    ms(par,0);
    bfs(start);


    //cout<<start<<endl;

    mx=0,mxi=0;
    for(int i=1;i<=n;i++)
    {
        if(dis[i]>=mx)
        {
            mx= dis[i];
            mxi=i;
        }
    }

    bridge.clear();
    int endd=mxi;
    //cout<<endd<<endl;

    adj[start].push_back(endd);
    adj[endd].push_back(start);

    ms(vis,0);
    ms(dis,0);
    ms(par,0);
    dfs1(1);

    printf("%d\n",bridge.size());


    clearr(n);

    }

    return 0;
}
