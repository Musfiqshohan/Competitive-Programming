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

vector<int> adj2[1009];
vector<int>comp_src, inCycle,result;

stack<int>stk;
int n,vis[1009],dis[1009];

struct info
{
    int u,v,w;
};
vector<info>vec;


void clearr()
{
    vec.clear();
    comp_src.clear();
    inCycle.clear();
    result.clear();
    for(int i=0;i<=n;i++) adj2[i].clear();
    ms(vis,0);
    ms(dis,0);
}

void dfs(int src, vector<int>adj[], int turn)
{
    for(int i=0; i<adj[src].size(); i++)
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
    if(turn==3)
        result.push_back(src);

}

void Bellman_ford()
{
    for(int i=0; i<n; i++)
        dis[i]=inf;

    for(int i=0; i<comp_src.size(); i++)
    {
        dis[comp_src[i]]=0;
        //  printf("Compsrc= %d\n",comp_src[i]);
    }

    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<vec.size(); j++)
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


    for(int i=0; i<vec.size(); i++)
    {
        info t=vec[i];

        int u= t.u;
        int v=t.v;
        int w=t.w;



    //   printf("%d to %d =%d + %d < %d ?\n",u,v,dis[u],w,dis[v]);
        if( dis[u]!=inf && dis[u]+w < dis[v])
        {
            dis[v]=dis[u]+w;
            //printf("%d -> %d\n",u,v);

            inCycle.push_back(u);
            inCycle.push_back(v);
        }

    }

}

int main()
{
    int tt=0,test;
    cin>>test;

    while(tt<test) {

    int m,u,v,w;
    scanf("%d %d",&n,&m);

    for(int i=0; i<m; i++)
    {
        scanf("%d %d %d",&u,&v,&w);

        vec.push_back({v,u,w});
        // adj1[u].push_back(v);
        adj2[v].push_back(u);

    }

    for(int i=0; i<n; i++)
    {
        if(vis[i]==0)
        {
            vis[i]=1;

            dfs(i,adj2,1);
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
           // printf("src= %d\n",src);
            dfs(src,adj2,2);
        }
    }

    Bellman_ford();

    ms(vis,0);

    for(int i=0;i<inCycle.size();i++)
    {
        int src= inCycle[i];
        if(vis[src]==0)
        {
            vis[src]=1;
            dfs(src,adj2,3);
        }
    }

    sort(result.begin(), result.end());

    printf("Case %d: ",++tt);

    if(result.size()==0)
        printf("impossible");

    for(int i=0;i<result.size();i++)
    {
        if(i>0)
            printf(" ");
        printf("%d",result[i]);
    }

    puts("");

    clearr();

    }

    return 0;
}
