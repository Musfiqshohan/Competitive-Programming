#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define i64 long long
#define pii pair<int,int>
#define inf 100000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;


struct node
{
    int city;
    i64 dist;


    bool operator < (const node &n) const
    {
        if(dist==n.dist)
            return city>n.city;
        return dist > n.dist;
    }
};
vector<node>G[25*1019];

pii ara[25][1019];
i64 d[25*1019];

int totn;

void clearr(int n)
{

    for(int i=0; i<=n; i++)
        G[i].clear();

    ms(ara,0);
    totn=0;
}

void dijkstra(int source)
{
    for(int i = 1; i <= totn; i++) d[i] = 1000000000000;
    d[source] = 0;
    node u;
    u.city = source;
    u.dist = 0;
    priority_queue <node> pq;
    pq.push(u);
    while(!pq.empty())
    {
        node u= pq.top();
        pq.pop();
        //if(vis[u.city]==1) continue;
        for(int i = 0; i < G[u.city].size(); i++)
        {
            node v;
            v.city = G[u.city][i].city;
            v.dist = u.dist + G[u.city][i].dist;
            // printf("src=%d to %d %d\n",u.city,v.city,v.dist);

            if(d[v.city] > v.dist)
            {
                d[v.city] = v.dist;
                pq.push(v);
            }
        }
    }
}



int main()
{

    int tt;
    scanf("%d",&tt);
    while(tt--)
    {


        int cat,t,last,x,y;
        scanf("%d %d %d",&cat,&t,&last);

        for(int i=1; i<=cat; i++)
        {
            for(int j=1; j<=t; j++)
            {
                scanf("%d %d",&x,&y);
                ara[i][j]= {x,y};
            }
        }



        for(int i=1; i<=t; i++)
        {
            G[0].push_back({i, ara[1][i].first });
        }

        for(int i=1; i<=cat; i++)
        {
            for(int j=1; j<=t; j++)
            {
                for(int k=1; k<=t; k++)
                {
                    int city=(i*t)+k;
                    int dis=abs(ara[i+1][k].first- ara[i][j].first) +ara[i][j].second;

                    // printf("->>%d %d =%d\n",(i-1)*t+j , city, dis);
                    G[(i-1)*t+j].push_back({city,dis});
                }
            }
        }

        for(int i=1; i<=t; i++)
        {
            G[(cat-1)*t+i].push_back({cat*t+5,last-ara[cat][i].first+ara[cat][i].second});
        }


        totn=cat*t+5;
        dijkstra(0);


        printf("%lld\n",d[cat*t+5]);

        clearr(cat*t+1);

    }






    return 0;
}
