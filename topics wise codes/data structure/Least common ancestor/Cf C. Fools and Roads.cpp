///http://codeforces.com/problemset/problem/191/C
#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define i64 long long
#define pii pair<int,int>
#define inf 100000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
#define rep(i,n) for(i64 i=0;i<n;i++)
using namespace std;
const int MAXN=100009, maxL=18;  ///2*1e5

vector<int>adj[MAXN];
vector<pii>vec;
int Level[MAXN];

struct info
{
    int pr,sum;
} par[MAXN][maxL+5];

void dfs(int src, int pr)
{
    for(int i=0; i<adj[src].size(); i++)
    {
        int node=adj[src][i];

        if(node!=pr)
        {
            Level[node]=Level[src]+1;
            par[node][0].pr=src;
            dfs(node,src);
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
                par[u][i].pr=par[ par[u][i-1].pr ][i-1].pr;
            }
        }
    }
}


int getLca(int u, int v)
{
    if(Level[u]<Level[v])
        swap(u,v);

    int dif=Level[u]-Level[v];

    for(int i=maxL; i>=0; i--)
    {
        int d=1<<i;

        if(dif>=d)
        {
            dif-=d;
            par[u][i].sum++;
            u=par[u][i].pr;
        }
    }

    //printf("%d %d\n",u,v);


    if(u==v) return u;


    for(int i=maxL; i>=0; i--)
    {
        if(par[u][i].pr!=par[v][i].pr)
        {

            par[u][i].sum++;
            u=par[u][i].pr;

            par[v][i].sum++;
            v=par[v][i].pr;
           // printf("u=%d, %d  v=%d  \n",u,par[u][i].sum,v,par[v][i].sum);

        }
    }

    par[u][0].sum++;
    par[v][0].sum++;


    return par[u][0].pr;
}


void distributesparse(int n)
{
    for(int i=maxL; i>=0; i--)
    {
        for(int u=1; u<=n; u++)
        {
            if(par[u][i].pr!=-1)
            {
               // printf("%d %d =%d\n",u,i,par[u][i].sum);
                par[u][i-1].sum+=par[u][i].sum;
                par[ par[u][i-1].pr ][i-1].sum+=par[u][i].sum;
            }
        }
    }

}
int main()
{
    int n,u,v,q,a,b;
    scanf("%d",&n);
    for(int i=1; i<n; i++)
    {
        scanf("%d %d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);

        vec.push_back({u,v});
    }

    for(int i=0; i<=maxL; i++)
        for(int u=1; u<=n; u++)
            par[u][i].pr=-1,par[u][i].sum=0;

    dfs(1,-1);

    precomputeSparse(n);

    cin>>q;

    while(q--)
    {
        cin>>a>>b;
        int x=getLca(a,b);
    }

    distributesparse(n);

    for(int i=0; i<vec.size(); i++)
    {
        u=vec[i].first;
        v=vec[i].second;

        int res=0;

       // printf("%d %d, %d %d\n",u,par[v][0].pr, v,par[u][0].pr );
        if(u==par[v][0].pr) res=par[v][0].sum;
        else  res=par[u][0].sum;

        printf("%d ",res);
    }

    puts("");




    return 0;
}
