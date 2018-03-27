#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
#define ll long long
using namespace std;

struct tripple
{
    int u,v,w;
} tra[16009];

int n;
int vis[550],par[550], maxim[550];
vector<int>adj[550];
vector<int>edge[550];

void clearr()
{
    ms(vis,0);
    ms(par,0);

    for(int i=0;i<n;i++){ adj[i].clear(); edge[i].clear(); }


}
bool compare(tripple a, tripple b)
{

    return a.w<b.w;
}

void bfs(int src)
{
    queue<int>q;
    q.push(src);
    vis[src]=1;

    maxim[src]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();

        for(int i=0; i<adj[u].size(); i++)
        {
            int node=adj[u][i];

            if(vis[node]==0)
            {
                vis[node]=1;
                q.push(node);
                // printf("%d %d\n",)
                maxim[node]= max(maxim[u], edge[u][i]);
            }
        }
    }
}

int findd(int r)
{
    if(par[r]==r) return r;
    return par[r]=findd(par[r]);
}
void unionn(tripple temp)
{
    int u= findd(temp.u);
    int v= findd(temp.v);
    //printf("%d -> %d=%d\n",temp.u,temp.v,temp.w);

    if(u!=v)
    {
        par[u]=v;

        adj[temp.u].push_back(temp.v);
        adj[temp.v].push_back(temp.u);

        edge[temp.u].push_back(temp.w);
        edge[temp.v].push_back(temp.w);


    }
}

int main()
{
    int t=0,test;
    cin>>test;

    while(t<test)
    {

        int m,src;
        scanf("%d %d",&n,&m);
        ms(maxim,-1);

        for(int i=0; i<m; i++)
        {
            scanf("%d %d %d",&tra[i].u, &tra[i].v, &tra[i].w);
        }

        for(int i=0; i<n; i++) par[i]=i;

        sort(tra,tra+m, compare);
        for(int i=0; i<m; i++)
        {
            unionn(tra[i]);
        }


        cin>>src;

        bfs(src);

        printf("Case %d:\n",++t);
        for(int i=0; i<n; i++)
        {
            if(maxim[i]==-1) printf("Impossible\n");
            else printf("%d\n",maxim[i]);
        }

        clearr();

    }

    return 0;
}

