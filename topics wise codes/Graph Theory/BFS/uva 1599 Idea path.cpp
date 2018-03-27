///https://uva.onlinejudge.org/external/15/1599.pdf
#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<int,int>
#define inf 100000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

vector<int>adj[100009],ColorSeq[100009];

void bfs(int src)
{
    vis[src]=true;
    dis[src][src]=0;

    queue<int>q;
    q.push(src);

    while(!q.empty())
    {
        int u= q.front();
        q.pop();

        for(int i=0;i<adj[u].size();i++)
        {
            int node= adj[u][i];

            if(vis[node]==false)
            {

            }
        }

    }

}
int main()
{
    int n;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d %d %d",&u,&v,&l);

        adj[u].push_back(v);
        adj[v].push_back(u);
        ColorSeq[u].push_back(l);
        ColorSeq[v].push_back(l);
    }

    bfs(1);
    bfs(n);





    return 0;
}
