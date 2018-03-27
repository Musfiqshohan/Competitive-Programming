#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<int,int>
#define inf 10000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
using namespace std;


int dis[10001];
int par[10001],par_cnt[10001];
int n,m,k;
int flag=0;

struct Graph
{
    int v,w;
};
vector<Graph>adj[10001];

struct node
{
    int city,dist;

    bool operator <(const node &n)const
    {
        return dist>n.dist;
    }
};

void dijkstra1(int src)
{
    for(int i=1; i<=n; i++)
        dis[i]=inf;



    dis[src]=0;
    priority_queue<node>pq;

    pq.push({src,0});

    while(!pq.empty())
    {
        node u=pq.top();
        pq.pop();

        for(int i=0; i<adj[u.city].size(); i++)
        {
            int v= adj[u.city][i].v;
            int w= adj[u.city][i].w;


            if(u.dist+w <dis[v])
            {
                dis[v]=u.dist+w;
                pq.push({v,dis[v]});
            }
        }
    }

}
void dijkstra2(int src)
{
    dis[src]=0;
    priority_queue<node>pq;

    pq.push({src,0});

    while(!pq.empty())
    {
        node u=pq.top();
        pq.pop();

        for(int i=0; i<adj[u.city].size(); i++)
        {
            int v= adj[u.city][i].v;
            int w= adj[u.city][i].w;


            if(u.dist+w <dis[v])
            {
                dis[v]=u.dist+w;
                pq.push({v,dis[v]});
            }

            //printf("%d to %d ->->%d +%d =%d?\n",u.city,v,u.dist,w,dis[v]);
            if(u.dist+w ==dis[v])
            {
                pq.push({v,dis[v]});

                par_cnt[v]++;

                if(par[v]!=0 && par_cnt[v]>1)
                {
                   // printf("u=%d  v=%d  par[v]=%d\n",u,v,par[v]);
                    flag=1;
                    return;
                }
            }
        }
    }

}



int main()
{
    int u,v,w,prev,x;
    scanf("%d %d %d",&n,&m,&k);


    scanf("%d",&prev);
    for(int i=1; i<k; i++)
    {
        scanf("%d",&x);
        par[x]=prev;
        prev=x;
    }

    for(int i=0; i<m; i++)
    {
        scanf("%d %d %d",&u,&v,&w);

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    dijkstra1(1);
    //  for(int i=1;i<=n;i++) printf("dis[%d]= %d\n",i,dis[i]);


    flag=0;
    dijkstra2(1);

    // printf("->%d\n",n);
    // check_path(n);

    if(flag==0)
        printf("no\n");
    else printf("yes\n");

//    for(int i=1;i<=n;i++)
//        adj[i].clear(), edge[i].clear(), par[i].clear();



    return 0;
}
