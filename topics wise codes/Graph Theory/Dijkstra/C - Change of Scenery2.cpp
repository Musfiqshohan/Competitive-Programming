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

vector<int> par[10001];
int dis[10001];
int n,m,k;

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
                //printf("%d to %d\n",u.city,v);
               // pq.push({v,dis[v]});

                if(par[v].size()<2)
                    par[v].push_back(u.city);
            }
        }
    }

}

int flag=0;
void check_path(int n)
{
    if(par[n].size()==0)
    {
        return;
    }

    if(par[n].size()>1) flag=1;
    return;
    for(int i=0; i<par[n].size(); i++)
    {
        //  printf("->%d\n",par[n][i]);

        //   if(par[n][i]!=num) flag=1;
        if(flag==0)
        check_path(par[n][i]);
    }

}


int main()
{
    int u,v,w;
    scanf("%d %d %d",&n,&m,&k);

    int dummy;
    for(int i=0; i<k; i++)
        scanf("%d",&dummy);

    for(int i=0; i<m; i++)
    {
        scanf("%d %d %d",&u,&v,&w);

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    dijkstra1(1);
    //  for(int i=1;i<=n;i++) printf("dis[%d]= %d\n",i,dis[i]);


    dijkstra2(1);

    flag=0;
    // printf("->%d\n",n);
    check_path(n);

    if(flag==0)
        printf("no\n");
    else printf("yes\n");

//    for(int i=1;i<=n;i++)
//        adj[i].clear(), edge[i].clear(), par[i].clear();



    return 0;
}
