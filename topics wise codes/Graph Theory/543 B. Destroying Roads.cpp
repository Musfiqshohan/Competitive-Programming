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
vector<int>adj[3009];
int dis[3009][3009], vis[3009][3009];
void bfs(int src)
{

    vis[src][src]=1;
    dis[src][src]=0;

    queue<int>q;
    q.push(src);

    while(!q.empty())
    {
        int u= q.front();
        q.pop();

        for(int i=0; i<adj[u].size(); i++)
        {
            int node= adj[u][i];

            if(vis[src][node]==0)
            {
                vis[src][node]=1;
                dis[src][node]= dis[src][u]+1;
                q.push(node);
            }
        }
    }

}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m,s1,t1,l1,s2,t2,l2,u,v;
    cin>>n>>m;

    for(int i=0; i<m; i++)
    {
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    cin>>s1>>t1>>l1;
    cin>>s2>>t2>>l2;




    for(int i=1; i<=n; i++)
    {
        bfs(i);
    }

    int mx=0;



    if(dis[s1][t1]>l1 || dis[s2][t2]>l2)
    {
        cout<<"-1"<<endl;
        return 0;
    }

    mx= m- dis[s1][t1]-dis[s2][t2];
   // cout<<mn<<endl;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
           int  res= m- dis[s1][i] - dis[i][j] - dis[j][t1] - dis[s2][i]- dis[j][t2];
           printf("i=%d j=%d %d\n",i,j,res);
            mx= max(mx,res);
        }
    }

    cout<<mx<<endl;



    return 0;
}
