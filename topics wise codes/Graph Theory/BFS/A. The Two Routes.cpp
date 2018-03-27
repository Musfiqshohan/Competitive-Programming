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

vector<int>rail,road;


void bfs1(int src)
{
    vis[src]=1;
    dis[src]=1;

    queue<int>q;
    q.push(src);


    while(!q.empty())
    {
        int u= q.front();
        q.pop();

        for(int i=0; i<rail[u].size(); i++)
        {
            int node= rail[u][i];

            if(vis[node]==0)
            {
                vis[node]=1;
                dis[node]= dis[u]+1;
                q.push(node);
            }
        }

    }

}


void bfs2(int src)
{
    vis[src]=1;

    dis2[src]=0;

    queue<int>q;
    q.push(src);


    while(!q.empty())
    {
        int u= q.front();
        q.pop();

        for(int i=0; i<road[u].size(); i++)
        {
            int node= road[u][i];


            if(vis[node]==0)
            {
                vis[node]=1;

                if(dis[node]== dis2[u]+1)
                    dis2[node]= dis2[u]+3;
                else dis2[node]= dis2[i]+1;

                q.push(node);
            }

        }
    }



}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);

    for(int i=0; i<m; i++)
    {
        scanf("%d %d",&u,&v);
        rail[u].push_back(v);
        rail[v].push_back(u);

        mp[ {min(u,v), max(u,v)]=1;
          }

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(mp[ { min(i,j), max(i,j) } ]==0)
                    road[i].push_back(j), road[j].push_back(i);
            }
        }

        bfs1(1);
        ms(vis,0);

        bfs2(1);








        return 0;
    }
