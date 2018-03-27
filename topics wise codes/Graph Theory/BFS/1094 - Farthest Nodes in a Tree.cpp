#include<bits/stdc++.h>
using namespace std;

vector<int>adj[30009];
vector<int>cost[30009];

int vis[30009],level[30009];
int temp,mx=0;
void dfs(int source)
{
    queue<int>q;
    q.push(source);
    vis[source]=1;
    level[source]=0;

    while(!q.empty())
    {
        int u=q.front();
        q.pop();

        for(int i=0;i<adj[u].size();i++)
        {
            int node=adj[u][i];
            int cs= cost[u][i];
            if(vis[node]==0)
            {
                vis[node]=1;


                level[node]= level[u]+ cs;

                if(level[node]>mx)
                {
                    mx=level[node];
                    temp=node;
                }

                q.push(node);
            }
        }
    }
}

void init()
{
    memset(vis,0,sizeof vis);
    memset(level,0,sizeof level);

}
int main()
{
    int t=0,test;
    cin>>test;

    while(t++<test){
    int n,i,src,dis,weight;

    scanf("%d",&n);

    for(i=0;i<n-1;i++)
    {
        scanf("%d %d %d",&src,&dis,&weight);


        adj[src].push_back(dis);
        adj[dis].push_back(src);

        cost[src].push_back(weight);
        cost[dis].push_back(weight);
    }

    temp=0,mx=0;
    dfs(0);
   // printf("%d\n",temp);
    init();
    dfs(temp);
    printf("Case %d: %d\n",t,mx);
    init();
    for(i=0;i<n;i++) {
        adj[i].clear();
        cost[i].clear();
    }

    }

}
