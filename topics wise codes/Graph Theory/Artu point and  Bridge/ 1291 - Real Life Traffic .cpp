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
set<pii>bridge;
int low[10009],disc[10009],par[10009],vis[10009], belongs[10009],scc[10009];
int times=0;

void  clearr(int n)
{
    ms(low,0);
    ms(par,0);
    ms(disc,0);
    ms(scc,0);
    ms(belongs,0);
    bridge.clear();
    times=0;

    for(int i=0;i<=n;i++ ) adj[i].clear();
}

void dfs(int src)
{
    low[src]= disc[src]=++times;
    for(int i=0; i< adj[src].size(); i++)
    {
        int node= adj[src][i];

        if(node!= par[src] && vis[node]==0)
        {
            vis[node]=1;
            par[node]=src;

            dfs(node);

            low[src]= min(low[src], low[node]);

            if(low[node]>disc[src])
            {
                bridge.insert({src,node});
             //   printf("bridge %d ->%d\n",src,node);

            }


        }

        else if(node!=par[src])
        {
            low[src]= min(low[src], disc[node]);

        }
    }

}

void dfs2(int src, int p)
{
    belongs[src]=p;

   // printf("%d belong to %d\n",src,p);

    for(int i=0; i< adj[src].size(); i++)
    {
        int node= adj[src][i];

     //   printf("%d->%d in %d\n",src,node, p);
        if(bridge.find({src,node})== bridge.end()  &&  bridge.find({src,node})== bridge.end())
        {
           // printf("But then %d->%d in %d\n",src,node, p);
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

     int tt=0,test;
    cin>>test;

    while(tt<test)
    {

    int n,m,u,v;
    scanf("%d %d",&n,&m);

    for(int i=0; i<m; i++)
    {
        scanf("%d %d",&u,&v);

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ms(vis,0);
    dfs(1);

    ms(vis,0);

    df

    int scc_id=0;
    for(int i=0; i<n; i++)
    {
        if(vis[i]==0) {
        vis[i]=1;
        dfs2(i, ++scc_id);

        }
    }


    for( set<pii> :: iterator it= bridge.begin(); it!= bridge.end(); it++)
    {
        pii tp= (*it);

        scc[ belongs[tp.first] ]++;
        scc[ belongs[tp.second] ]++;
    }



    int tot=0;
    for(int i=1;i<=scc_id;i++)
    {
       if(scc[i]==1)
        tot++;
    }

    printf("Case %d: %d\n",++tt,(tot+1)/2);

    clearr(n);

    }
    return 0;
}



