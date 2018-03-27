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

vector<int>rail[409],road[409];
map<pii,int>mp;
int n,m,u,v;

int vis[409],dis[409], dis2[409];

void bfs1(int src)
{

    for(int i=1; i<=n; i++) dis[i]=10000009;

    vis[src]=1;
    dis[src]=0;

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
                // printf("%d->%d\n",u,node);
                vis[node]=1;
                dis[node]= dis[u]+1;
                q.push(node);
            }
        }

    }

}


struct node
{

    int city, dist;


    bool operator < (const node &n)const
    {
        return dist>n.dist;
    }
};


void dijkstra(int src)
{
    for(int i=1; i<=n; i++)
    {
        dis2[i]=10000009;
    }

    dis2[src]=0;



    priority_queue<node>pq;
    pq.push({src,0});


    while(!pq.empty())
    {
        node u= pq.top();
        pq.pop();


        for(int i=0; i<road[u.city].size(); i++)
        {
            node v;
            v.city= road[u.city][i];



            if(dis[v.city]==dis2[u.city]+1)
                v.dist=dis2[u.city]+3;
            else
                v.dist=dis2[u.city]+1;

            if(v.dist<dis2[v.city])
            {
                //printf("%d ->%d\n",u.city,v.city);
                dis2[v.city]=v.dist;
                pq.push(v);
            }

        }
    }

}



int main()
{

    scanf("%d %d",&n,&m);

    for(int i=0; i<m; i++)
    {
        scanf("%d %d",&u,&v);
        rail[u].push_back(v);
        rail[v].push_back(u);


        mp[ {min(u,v), max(u,v)}]=1;

    }


    for(int i=1; i<=n; i++)
    {
        for(int j=i+1; j<=n; j++)
        {
            if(mp[ { min(i,j), max(i,j) } ]==0)
            {
                road[i].push_back(j), road[j].push_back(i);

            }
        }
    }

    bfs1(1);

    ms(vis,0);

    dijkstra(1);
    //  cout<<dis2[n]<<endl;

    //printf("%d %d\n",dis[n], dis2[n]);

    int mx=max(dis[n],dis2[n]);

    if(mx==10000009) mx=-1;
    printf("%d\n",mx);

    return 0;
}
