#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

struct node{
    int city,dist;


    bool operator < (const node &n) const{
        if(dist==n.dist)
            return city>n.city;
        return dist > n.dist;
    }
};


void dijkstra(int source){
    for(int i = 1; i <= n; i++) d[i] = inf;
    d[source] = 0;
    node u;
    u.city = source;
    u.dist = 0;
    priority_queue <node> pq;
    pq.push(u);
    while(!pq.empty()){
        node u= pq.top();
        pq.pop();
	//if(vis[u.city]==1) continue;
        for(int i = 0; i < G[u.city].size(); i++){
            node v;
            v.city = G[u.city][i].first;
            v.dist = u.dist + G[u.city][i].second;
            if(d[v.city] > v.dist){
                d[v.city] = v.dist;
                pq.push(v);
            }
        }
    }
}



int main()
{

    scanf("%d",&n);

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
            scanf("%d",&ara[i][j]);
    }


    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            adj[i].push_back(j);
            adj[j].push_back(i);

            edge[i].push_back(ara[i][j]);
            edge[j].push_back(ara[i][j]);
        }
    }

    int k,a,b,l;
    cin>>k;

    for(int i=0; i<k; i++)
    {

        cin>>a>>b>>l;

        for(int i=0;i<adj[a].size();i++)
        {
            if(adj[a][i]==b)
                edge[a][i]=l;
        }

        queue<int>q;
        q.push(a);

    }



    return 0;
}
