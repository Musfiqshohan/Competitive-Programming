#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define i64 long long
#define pii pair<i64,i64>
#define inf 100000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
#define rep(i,n) for(i64 i=0;i<n;i++)
using namespace std;
vector<int>adj[10009];
int vis[10009],color[10009];

int tot;
void dfs(int src, int col)
{


    for(int i=0; i<adj[src].size(); i++)
    {
        int node= adj[src][i];

        if(vis[node]==0)
        {

            if(color[node]!=col)
                tot++;
          //  printf("%d %d\n",src,node);
            vis[node]=1;
            dfs(node,color[node]);
        }
    }


    return ;
}



int main()
{
    int n,x;
    scanf("%d",&n);

    for(int i=2;i<=n;i++)
    {
        scanf("%d",&x);

        adj[i].push_back(x);
        adj[x].push_back(i);
    }

    for(int i=1;i<=n;i++)
        scanf("%d",&color[i]);


    vis[1]=1;
    dfs(1,color[1]);

    printf("%d\n",tot+1);
}
