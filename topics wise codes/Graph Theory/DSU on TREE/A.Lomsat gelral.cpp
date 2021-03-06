#include<bits/stdc++.h>
#define i64 long long
using namespace std;
i64 mx,sum;
const i64 MAXN=100009;
i64 res[MAXN],cnt[MAXN],col[MAXN],sz[MAXN];
bool big[MAXN];
vector<i64>g[MAXN];



void dfsSize(i64 v, i64 p)
{
    sz[v]=1;
    for(auto u: g[v])
        if(u!=p)
            dfsSize(u,v), sz[v]+=sz[u];
}

void add(i64 v, i64 p,i64 x)
{
   // printf("I am in %lld\n",v);
    cnt[col[v]]+=x;
    if(cnt[col[v]]>mx)
        mx=cnt[col[v]], sum=col[v];
    else if(cnt[col[v]]==mx) sum+=col[v];

   // printf("sum=%lld  col=%lld\n",sum,col[v]);
    for(auto u:g[v])
        if(u!=p && !big[u])
            add(u,v,x);

}


void dfs(i64 v,i64 p, i64 keep)
{
    i64 mxx=-1, bigChild=-1;
    for(auto u:g[v])
        if(u!=p && sz[u]>mxx)
            mxx=sz[u], bigChild=u;

    for(auto u:g[v])
        if(u!=p && u!=bigChild)
            dfs(u,v,0);
    if(bigChild!=-1)
        dfs(bigChild,v,1), big[bigChild]=1;


   // printf("root: %lld\n",v);
    add(v,p,1); ///got answer for node v;
   // printf("at last =mx=%lld sum=%lld\n",mx,sum);

    res[v]=sum;

    if(bigChild!=-1)
        big[bigChild]=0;
    if(keep==0)
        add(v,p,-1), mx=0,sum=0;

}

int main()
{
    i64 n,u,v;
    cin>>n;
    for(i64 i=1;i<=n;i++)
    {
        cin>>col[i];
    }

    for(i64 i=1;i<n;i++)
    {
        scanf("%lld %lld",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfsSize(1,-1);

    mx=0,sum=0;
    dfs(1,-1,1);

    for(i64 i=1;i<=n;i++)
        printf("%lld ",res[i]);

    puts("");


 return 0;
}
