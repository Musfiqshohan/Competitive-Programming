#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<ll,ll>
#define inf 100000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
using namespace std;

vector<int>adj1[1009], adj2[1009];
vector<int>comp_src, inCycle;
stack<int>stk;
int n,vis[1009],dis[1009];

struct info{
    int u,v,w;
};
vector<info>vec;
void dfs(int src, vector<int>adj[], int turn)
{
    for(int i=0;i<adj[src].size();i++)
    {
        int node= adj[src][i];

        if(vis[node]==0)
        {
            vis[node]=1;
            dfs(node,adj,turn);
        }
    }

    if(turn==1)
    stk.push(src);

}

void Bellman_ford()
{
    for(int i=1;i<=n;i++)
        dis[i]=inf;

    for(int i=0;i<comp_src.size();i++)
        dis[comp_src[i]]=0;

    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<vec.size();j++)
        {
            info t=vec[j];

            int u= t.u;
            int v=t.v;
            int w=t.w;

            if( dis[u]!=inf && dis[u]+w < dis[v])
            {
                dis[v]=dis[u]+w;
            }
        }
    }


    for(int i=0;i<vec.size();i++)
    {
            info t=vec[i];

            int u= t.u;
            int v=t.v;
            int w=t.w;

            if( dis[u]!=inf && dis[u]+w < dis[v])
            {

                printf("%d -> %d\n",u,v);
                inCycle.push_back(u);
                inCycle.push_back(v);
            }

    }

}

int main()
{
    int m,u,v,w;
    scanf("%d %d",&n,&m);

    for(int i=0;i<m;i++)
    {
        scanf("%d %d %d",&u,&v,&w);

        vec.push_back({u,v,w});
        adj1[u].push_back(v);
        adj2[v].push_back(u);

    }

    for(int i=0;i<n;i++)
    {
        if(vis[i]==0)
        {
            vis[i]=1;

            dfs(i,adj1,1);
        }
    }

    ms(vis,0);

    while(!stk.empty())
    {
        int src=stk.top();
        stk.pop();

        if(vis[src]==0)
        {
            vis[src]=1;
            comp_src.push_back(src);
            dfs(src,adj1,2);
        }
    }

    Bellman_ford();

    sort(inCycle.begin(), inCycle.end());

    if(inCycle.size()==0) printf("impossible\n");
    else {

        ms(vis,0);

        for(int i=0;i<inCycle.size();i++)
        {
            int src=inCycle[i];

            if(vis[src]==0)
            {
                vis[src]=1;
                dfs(src,adj2,2);
            }
        }

        inCycle.clear();
        for(int i=0;i<n;i++)
        {
            if(vis[i]==1)
            {
                inCycle.push_back(i);
            }
        }

        for(int i=0;i<inCycle.size();i++)
        {
            if(i) printf(" ");
            printf("%d",inCycle[i]);
        }
        puts("");

    }


    return 0;
}
