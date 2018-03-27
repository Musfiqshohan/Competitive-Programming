/**http://codeforces.com/contest/519/problem/E
Okay lets try this problem, I think I can solve this one with my own effort.*/

#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define i64 long long
#define pii pair<i64,i64>
#define INF 1000000000000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
#define rep(i,n) for(i64 i=0;i<n;i++)
using namespace std;

const int MAXN=100009, maxL=18;
vector<int>adj[MAXN];
int par[MAXN][maxL+5], Level[MAXN];

int child[MAXN];

int dfs(int src,int pr)
{
    int tot=0;
    for(int i=0; i<adj[src].size(); i++)
    {
        int node=adj[src][i];
        if(node!=pr)
        {
            Level[node]=Level[src]+1;
            par[node][0]=src;
            tot+=dfs(node,src);
        }
    }

    return child[src]=tot+1;
}


void precomputeSparse(int n)
{
    for(int i=1; i<=maxL; i++)
    {
        for(int u=1; u<=n; u++)
        {
            if(par[u][i-1]!=-1)
            {
                par[u][i]=par[ par[u][i-1] ][i-1];
            }
        }
    }
}


int getLca(int u, int v)
{

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
        if(par[u][i]!=par[v][i])
        {
            u=par[u][i];
            v=par[v][i];
        }
    }

    return par[u][0];
}


int main()
{

    int n,u,v,q;
    scanf("%d",&n);

    for(int i=1; i<n; i++)
    {
        scanf("%d %d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ms(par,-1);
    dfs(1,-1);

    precomputeSparse(n);


    cin>>q;
    while(q--)
    {

        cin>>u>>v;

        int tot=0;

        if(Level[u]<Level[v])
            swap(u,v);

        int rt=getLca(u,v);
       // cout<<"LCA "<<rt<<endl;

        int L1=Level[u]-Level[rt], L2=Level[v]-Level[rt];

        if((L1+L2)%2==1)   tot=0;
        else if(u==v) tot=n;
        else
        {
            if(L1==L2)
            {
                for(int i=maxL; i>=0; i--)
                {
                    if(par[u][i]!=par[v][i])
                    {
                        u=par[u][i];
                        v=par[v][i];
                    }
                }

              //  cout<<"Equal Length"<<endl;
                tot=n-child[u]-child[v];
            }
            else
            {
                int midL=(L1+L2)/2 -1;
              //  printf("midl=%d\n",midL);
                for(int i=maxL; i>=0; i--)      /// Lifted u to midL-1 up.
                {
                    int d=1<<i;
                    if(midL>=d)
                    {
                        midL-=d;
                        u=par[u][i];
                    }
                }

              //  cout<<"child of midpoint "<<u<<endl;
                tot=child[par[u][0]]-child[u];
            }
        }
        printf("%d\n",tot);

    }
    return 0;
}

