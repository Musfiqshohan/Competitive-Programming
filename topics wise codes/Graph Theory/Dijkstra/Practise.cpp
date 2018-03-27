#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
using namespace std;

vector< pair<int, int> >v[1000];

int dist[1000];
bool vis[1000];
vector<int>adj[500];
vector<int>edge[500];

void dijkstra()
{
    ms(vis,0);
    dist[1]=0;
    multiset< pair<int,int>> s;

    s.insert({0,1});

    while(!s.empty())
    {
        pair< int, int>p = *s.begin();
        s.erase(s.begin());

        int x=p.second;     int wei=p.first;
        if(vis[x]) continue;
        vis[x]=true;

        for(int i=0;i<adj[x].size();i++)
        {
            int e=edge[x][i];
            int w=adj[x][i];

            if(dist[x]+e <dist[w])
            {
                dist[w]=dist[x]+e;
                s.insert({dist[w],w});
            }

        }
    }

}


int main()
{
    int n,u,v,w;
    scanf("%d",&n);

    for(int i=0; i<=27; i++)
    {
        scanf("%d %d %d",&u,&v,&w);
        adj[u].push_back(v);
        adj[v].push_back(u);

        edge[u].push_back(w);
        edge[v].push_back(w);
    }

    for(int i=0; i<=n; i++) dist[i]=INT_MAX;
    dijkstra();

    for(int i=0; i<=n; i++)
    {
        printf("vertex=%d   distance=%d\n",i,dist[i]);
    }


}
