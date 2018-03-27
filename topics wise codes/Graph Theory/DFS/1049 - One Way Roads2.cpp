#include<bits/stdc++.h>
using namespace std;

map<pair<int,int>, int>cost;
vector<int>adj[109];
int vis[109][109];

int dfs(int source)
{

    int total=0;
    int flag=0;
    for(int i=0;i<adj[source].size();i++)
    {
        int node= adj[source][i];

        if(vis[source][node]==0)
        {
            vis[source][node]=1;
            vis[node][source]=1;
            flag=1;

           // printf("%d ->%d\n",source,node);

           return   cost[{source,node}] +dfs(node);

        }
    }

    return total;

}


int main()
{
    int t=0,test;
    cin>>test;

    while(t<test){
    int n,i,x,y,z,total=0;
    scanf("%d",&n);

    for(i=1; i<=n; i++)
    {
        scanf("%d %d %d",&x,&y,&z);

        cost[{y,x}]=z;
        cost[{x,y}]=0;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }



    int t1=dfs(1);
    memset(vis,0,sizeof vis);
    swap(adj[1][0],adj[1][1]);
    int t2=dfs(1);

    printf("Case %d: %d\n",++t,min(t1,t2));

    for(i=1;i<=n;i++) adj[i].clear();
    memset(vis,0,sizeof vis);
    cost.clear();

    }
    return 0;
}
