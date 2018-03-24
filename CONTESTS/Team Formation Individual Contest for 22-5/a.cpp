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

vector<i64>adj[100009],edge[100009];
i64 vis[100009],dis[100009], T[100009];

i64 dfs(i64 src)
{
    vis[src]=1;

    i64 tot=0;
    for(i64 i=0;i<adj[src].size();i++)
    {
        i64 nd=adj[src][i];

        if(vis[nd]==0)
        {
            dis[nd]=dis[src]+edge[src][i];
            tot+=dfs(nd)+ edge[src][i]*2;
        }
    }

    return tot;

}


int main()
{
    i64 n,u,v,w;
    cin>>n;

    for(i64 i=0;i<=n;i++)
    {
        scanf("%lld",&T[i]);
    }

    for(i64 i=0;i<n;i++)
    {
        scanf("%lld %lld %lld",&u,&v,&w);

        adj[u].push_back(v);
        edge[u].push_back(w);

        adj[v].push_back(u);
        edge[v].push_back(w);
    }


    //dfs(0);

    i64 tot=dfs(0);
    //cout<<tot<<endl;

    i64 mn=1000000000000;
    for(i64 i=0;i<=n;i++)
    {
        mn=min(mn,T[i]+tot-dis[i]);
    }


    cout<<mn<<endl;

}
