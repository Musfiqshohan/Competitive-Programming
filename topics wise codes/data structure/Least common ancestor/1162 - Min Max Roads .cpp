///http://lightoj.com/volume_showproblem.php?problem=1162
#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define i64 long long
#define pii pair<i64,i64>
#define INF 100000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
#define rep(i,n) for(i64 i=0;i<n;i++)
using namespace std;
const int MAXN=100009, maxL=20;
int Level[MAXN+5];
vector<int>adj[MAXN+5],edge[MAXN+5];

struct info
{
    int pr,mn,mx;
} par[MAXN+5][maxL+10];
int vis[MAXN+5];

void clearr(int n)
{
    for(int i=0; i<=n; i++)
        adj[i].clear(),edge[i].clear();
    ms(Level,0);
    ms(par,0);
    ms(vis,0);
}

void dfs(int src)
{
    vis[src]=1;
    for(int i=0; i<adj[src].size(); i++)
    {
        int node=adj[src][i];

        if(vis[node]==0)
        {
            // printf("%d->%d\n",src,node);
            Level[node]=Level[src]+1;
            par[node][0]= {src, edge[src][i], edge[src][i]};
            dfs(node);
        }
    }
}

void precomputeSparse(int n)
{
    for(int i=1; i<=maxL; i++)
    {
        for(int u=1; u<=n; u++)
        {
            if(par[u][i-1].pr!=-1)
            {
                int tempr= par[par[u][i-1].pr][i-1].pr;

                if(tempr==-1)
                {
                    par[u][i].mn=INT_MAX;
                    par[u][i].mx=INT_MIN;
                    par[u][i].pr=tempr;
                    continue;
                }
                par[u][i].mn= min(par[u][i- 1].mn, par[par[u][i-1].pr][i-1].mn);
                par[u][i].mx= max(par[u][i-1].mx, par[par[u][i-1].pr][i-1].mx);
                par[u][i].pr= par[par[u][i-1].pr][i-1].pr;

                // printf("%d %d %d,%d,%d\n",u,i,par[u][i].pr,par[u][i].mn,par[u][i].mx);
            }
        }
    }
}


pii getLca(int u, int v)
{
    if(Level[u]<Level[v])
        swap(u,v);

    int dif=Level[u]-Level[v];
    int mn1,mn2,mx1,mx2;
    mn1=mn2=INT_MAX;
    mx1=mx2=INT_MIN;

    //printf("-|%d %d\n",Level[u], Level[v]);

    for(int i=maxL; i>=0; i--)
    {
        int d=1<<i;
        if(dif>=d)
        {
            // printf("%d %d %d\n",dif,d,u);
            dif-=d;
            mn1=min(mn1,par[u][i].mn);
            mx1=max(mx1,par[u][i].mx);
            u=par[u][i].pr;
        }
    }

    // cout<<u<<endl;

    if(u==v)
        return{mn1,mx1};

    //printf("->%d %d\n",u,v);

    for(int i=maxL; i>=0; i--)
    {
        if(par[u][i].pr!=par[v][i].pr)
        {
            // printf("u=%d,pr=%d  v=%d,pr=%d\n",u,par[u][i].pr,v,par[v][i].pr);
            mn1=min(mn1,par[u][i].mn);
            mx1=max(mx1,par[u][i].mx);

            mn2=min(mn2,par[v][i].mn);
            mx2=max(mx2,par[v][i].mx);

            u=par[u][i].pr;
            v=par[v][i].pr;

            //printf("u=%d v=%d i=%d ,mx1=%d mn1=%d,  mx2=%d mn2=%d\n",u,v,i,mx1,mn1,mx2,mn2);
        }
    }

    //  printf("lca=%d\n",par[u][0].pr);

    mn1=min(mn1,par[u][0].mn);
    mx1=max(mx1,par[u][0].mx);

    mn2=min(mn2,par[v][0].mn);
    mx2=max(mx2,par[v][0].mx);
    return { min(mn1,mn2), max(mx1,mx2)};

}

int main()
{

    int tt=0,test;
    scanf("%d",&test);

    while(tt<test)
    {
        printf("Case %d:\n",++tt);
        int n,u,v,w,q,x,y;
        scanf("%d",&n);

        for(int i=1; i<n; i++)
        {
            scanf("%d %d %d",&u,&v,&w);
//        u--,v--;
            adj[u].push_back(v);
            adj[v].push_back(u);

            edge[u].push_back(w);
            edge[v].push_back(w);
        }


        for(int i=1; i<=n; i++)
            for(int j=1; j<=maxL; j++)
                par[i][j]= {-1,INT_MAX,INT_MIN};

        dfs(1);
        precomputeSparse(n);


        scanf("%d",&q);

        for(int i=0; i<q; i++)
        {
            scanf("%d %d",&x,&y);
            //cout<<x<<" "<<y<<endl;

            pii rt;
            if(x==y) rt= {0,0};
            else rt=getLca(x,y);

            printf("%d %d\n",rt.first,rt.second);
        }
        // puts("x");


        clearr(n);

    }

    return 0;
}
