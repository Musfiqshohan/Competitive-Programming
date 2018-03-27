///AC Code
#include<bits/stdc++.h>
#define pii  pair<int,int>
#define ll long long
#define ms(a,b) memset(a,b,sizeof a);
#define inf 1000000009
using namespace std;

int Set(int N, int pos)
{
    return N= (N|(1<<pos));
}
bool Check(int N, int pos)
{
    return (bool) (N&(1<<pos));
}


int dist[505][505], isShop[505];
pii dp[18][131082];
vector<int>adj[509],edge[509],Shop;

int n,m,S;

struct node
{
    int city,dis;
    bool operator < (const node &n) const
    {
        return dis>n.dis;
    }

};




void dijkstra(int start,int source)
{
    for(int i=1; i<=n; i++)    dist[start][i]=inf;
    dist[start][source]=0;
    node u;
    u= {source,0};

    priority_queue<node>pq;
    pq.push(u);
    while(!pq.empty())
    {
        node u =pq.top();
        pq.pop();

        for(int i=0; i<adj[u.city].size(); i++)
        {
            int v= adj[u.city][i];
            int dis=u.dis + edge[u.city][i];
            if(dist[start][v]>dis)
            {
                dist[start][v]=dis;
                pq.push({v, dist[start][v]});
            }

        }
    }
}


pii DP(int prevI, int mask)
{
    if(Shop[prevI]==n)
        return {0,0};

    if(dp[prevI][mask].first!=-1) return dp[prevI][mask];

    pii mn = make_pair(-1,inf);

    for(int i=0; i<Shop.size(); i++)
    {
        if(Check(mask,i)==false && dist[Shop[prevI]][Shop[i]]<inf)
        {
            pii ret= DP(i, Set(mask,i));

            ret.first+= isShop[Shop[i]];
            ret.second+= dist[Shop[prevI]][Shop[i]];

            if(ret.first > mn.first)
                mn=ret;

            else if(ret.first == mn.first)
                mn.second= min(mn.second,ret.second);

        }
    }

    return dp[prevI][mask]=mn;

}

int main()
{

    int tt=0,test;
    scanf("%d",&test);

    while(tt<test)
    {
        ms(dp,-1);
        ms(isShop,0);
        ms(dist,0);


        scanf("%d %d %d",&n,&m,&S);

        int x,u,w,v;
        for(int i=0; i<S; i++)
        {
            scanf("%d",&x);
            x++;

            if(x!=1 && x!=n)
                Shop.push_back(x);

            isShop[x]=1;

        }


        Shop.push_back(1);
        Shop.push_back(n);

        sort(Shop.begin(), Shop.end());



        for(int i=0; i<m; i++)
        {
            scanf("%d %d %d",&u,&v,&w);
            u++;
            v++;
            adj[u].push_back(v);
            edge[u].push_back(w);
        }

        for(int i=0; i<Shop.size(); i++)
        {
            int src= Shop[i];
            dijkstra(src,src);
        }


        printf("Case %d: ",++tt);

        if(dist[1][n]>=inf)
            printf("Impossible\n");
        else
        {
            pii ret= DP(0,1);
            ret.first+=isShop[1];
            printf("%d %d\n",ret.first, ret.second);
        }


        for(int i=1; i<=n; i++) adj[i].clear(), edge[i].clear();
        Shop.clear();

    }


    return 0;
}

