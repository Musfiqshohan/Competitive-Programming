#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
using namespace std;
///INCOMPLETE
struct node
{
    int cost;
    int at;

    bool operator<(const node &temp)const
    {
        return cost<temp.cost;
    }

    bool operator>(const node &temp)const{
        return cost>temp.cost;
    }


};


priority_queue <node>pq;
vector<int>adj[500];
vector<int>edge[500];
int vis[500],dist[500];

void dijkstra(int src)
{
    dist[src]=0;

    node t1;
    t1.at=src;
    t1.cost=0;
    pq.push(t1);



    while(!pq.empty())
    {
        node temp=pq.top();
        pq.pop();

        int u=temp.at;
        int weight=temp.cost;

        if(vis[u]==true) continue;
        vis[u]=true;
       // printf("at=%d dis=%d -> ",u+1,weight);

        for(int i=0; i<adj[u].size(); i++)
        {
            int nde= adj[u][i];

            if(dist[u]+edge[u][i]<dist[nde])
            {
                dist[nde]=dist[u]+edge[u][i];

               // printf("to=%d  dis=%d\n",nde+1, dist[nde]);
                node t2;
                t2.cost=dist[nde];
                t2.at=nde;
                pq.push(t2);

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
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);

        edge[u-1].push_back(w);
        edge[v-1].push_back(w);
    }

    for(int i=0; i<n; i++) dist[i]=INT_MAX;
    dijkstra(0);

    for(int i=0; i<n; i++)
    {
        printf("vertex=%d   distance=%d\n",i,dist[i]);
    }

    return 0;
}
