#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define inf 1000099
using namespace std;

int dist1[5009], dist2[5009];

vector<int>adj[5009];
vector<int>edge[5009];

bool vis[5009][4];
int n;

struct node
{
    int city;
    int sp1,sp2;

    bool operator < (const node &a)const
    {
        if(sp1==a.sp1)
            return sp2>a.sp2;

        return sp1>a.sp1;

    }
};

void clearr()
{
   // ms(dist1,0);
   // ms(dist2,0);
    for(int i=1;i<=n;i++) { adj[i].clear(); edge[i].clear(); }
    ms(vis,0);
}

void dijkstra()
{
    priority_queue<node>pq;
    dist1[1]=0;
    dist2[1]=inf;
    pq.push({1,0,inf});

    while(!pq.empty())
    {
        node temp=pq.top();
        pq.pop();

        int u=temp.city;

        if(vis[u][1]== true && vis[u][2]==true) continue;
        else if(vis[u][1]==true) vis[u][2]=true;
        else vis[u][1]= true;

        for(int i=0;i<adj[u].size();i++)
        {
            int v=adj[u][i];

            if(dist1[u]+edge[u][i]<dist1[v])
            {
                dist1[v]=dist1[u]+edge[u][i];

                //printf("%d->%d %d |%d   %d %d \n",u,v,dist1[v],   dist2[v], dist2[u]+edge[u][i] ,dist1[u]+edge[u][i]*3 );
                dist2[v]= min (dist2[v], min(dist2[u]+edge[u][i] , dist1[u]+edge[u][i]*3) );


                pq.push({v,dist1[v],dist2[v]});


            }
            else if(dist1[u]+edge[u][i]==dist1[v])
            {
                if(min(dist2[u]+edge[u][i] , dist1[u]+edge[u][i]*3)  < dist2[v])
                {
                     dist2[v]=  min(dist2[u]+edge[u][i] , dist1[u]+edge[u][i]*3) ;

                     pq.push({v,dist1[v], dist2[v]});
                }
            }
            else if(dist1[u]+edge[u][i]<dist2[v])
            {
                dist2[v]=dist1[u]+edge[u][i];
                pq.push({v,dist1[v],dist2[v]});
            }

        }

    }

}

int main()
{
    int t=0,test;
    cin>>test;

    while(t<test){
    int r,u,v,w;
    scanf("%d %d",&n,&r);

    for(int i=0;i<r;i++)
    {
        scanf("%d %d %d",&u,&v,&w);

        adj[u].pb(v);
        adj[v].pb(u);

        edge[u].pb(w);
        edge[v].pb(w);
    }

    for(int i=1;i<=n;i++){ dist1[i]=inf;   dist2[i]=inf;      }

    dijkstra();

    printf("Case %d: ",++t);
    printf("%d\n",dist2[n]);

    clearr();
    }
    return 0;
}
