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

vector<int>adj[105];
int vis[105];
void create(int src, int till)
{
    for(int i=src+1; i<=till; i++)
    {
        adj[src].push_back(i);
    }
}

void dfs(int src)
{
    for(int i=0; i<adj[src].size(); i++)
    {
        int node= adj[src][i];

        if(vis[node]==0)
        {
           // printf("%d %d\n",src,node);
            vis[node]=1;
            dfs(node);
        }
    }
}

int main()
{
    int n,m,src,till;
    scanf("%d %d",&n,&m);

    for(int i=0; i<n; i++)
    {
        scanf("%d %d",&src, &till);

        create(src,till);
    }


    vis[0]=1;
    dfs(0);

    if(vis[m]==1) printf("YES\n");
    else printf("NO\n");



    return 0;
}
