///http://codeforces.com/problemset/problem/208/E
/** Okay i dont know if i can ac this because im doubt about its memory limit. Lets give a try
*/
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

const int MAXN=100009;
vector<int>adj[MAXN];
const int maxL=18;  ///log2(2*1e5)
int Level[MAXN], par[MAXN][maxL+5];
vector<int>child[MAXN][maxL+5];



void dfs(int src, int pr)
{
    for(int i=0; i<adj[src].size(); i++)
    {
        int node=adj[src][i];
        if(node!=pr)
        {
            child[src][0].push_back(node);
            Level[node]=Level[src]+1;
            par[node][0]=src;
            dfs(node,src);
        }
    }
}


void precomputeSparse(int N)
{
    for(int i=1; i<=maxL; i++)
    {
        for(int u=1; u<=N; u++)
        {
            if(par[u][i-1]!=-1)
                {par[u][i]= par[ par[u][i-1] ][i-1];
                }
        }
    }


    for(int i=1;i<=maxL;i++)
    {
        for(int u=1;u<=n;u++)
        {
            for(int j=0;j<child[u][i-1].size();j++)
            {
                int ch=child[u][i-1][j];

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
            u=par[u][i];
        }
    }

    if(u==v)
        return u;


    for(int i=maxL; i>=0; i--)
    {
      //  printf("i=%d %d->%d , %d->%d\n",i,u,par[u][i],v,par[v][i]);
        if(par[u][i]!=par[v][i])
            u=par[u][i], v=par[v][i];
    }

     return par[u][0];
}

int main()
{
    int n;
    scanf("%d",&n);

    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        adj[x].push_back(i);
    }

    dfs(1,-1);






    return 0;
}
