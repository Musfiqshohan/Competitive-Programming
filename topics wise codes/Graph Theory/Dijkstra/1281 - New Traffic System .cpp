#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<ll,ll>
#define inf 100000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
using namespace std;

vector<int>adj[10009],edge[10009], Padj[10009], Pedge[10009];
int n,m,k,d;
int dis[10009][15];
struct node
{
    int city,dist,proroad;

    bool operator <(const node &n)const
    {
        return dist>n.dist;
    }
};


void clearr()
{
    ms(dis,0);
    for(int i=0; i<n; i++) adj[i].clear(), Padj[i].clear(), edge[i].clear(), Pedge[i].clear();
}


void dijkstra(int src)
{
    for(int i=1; i<n; i++)
        for(int j=0; j<=d; j++)
            dis[i][j]=inf;


    // dis[src][=0;
    priority_queue<node>pq;
    node u= {src,0};
    pq.push(u);

    while(!pq.empty())
    {
        node u=pq.top();
        pq.pop();

        for(int i=0; i<adj[u.city].size(); i++)
        {
            node v;
            v.city= adj[u.city][i];
            v.dist= u.dist+ edge[u.city][i];
            v.proroad=u.proroad;



            if(v.dist < dis[v.city][v.proroad] && v.proroad<=d)
            {
                dis[v.city][v.proroad]=v.dist;
                pq.push(v);
            }
        }


        for(int i=0; i<Padj[u.city].size(); i++)
        {
            node v;
            v.city= Padj[u.city][i];
            v.dist= Pedge[u.city][i]+u.dist;
            v.proroad=u.proroad+1;

            if(v.dist <  dis[v.city][v.proroad] && v.proroad<=d)
            {
                dis[v.city][v.proroad]=v.dist;
                pq.push(v);
            }
        }
    }

}


int main()
{
    int tt=0,test;
    cin>>test;

    while(tt<test)
    {
        int u,v,w;
        scanf("%d %d %d %d",&n,&m,&k,&d);

        for(int i=0; i<m; i++)
        {
            scanf("%d %d %d",&u,&v,&w);

            adj[u].push_back(v);
            edge[u].push_back(w);

        }


        for(int i=0; i<k; i++)
        {
            scanf("%d %d %d",&u,&v,&w);

            Padj[u].push_back(v);
            Pedge[u].push_back(w);

        }



        dijkstra(0);

        int mn= inf;
        for(int i=0; i<=d; i++)
        {
            //printf("%d \n",dis[n-1][i]);
            mn= min(mn, dis[n-1][i]);

        }


        printf("Case %d: ",++tt);
        if(mn==inf)
            printf("Impossible\n");
        else
            printf("%d\n",mn);

        clearr();

    }

    return 0;
}
