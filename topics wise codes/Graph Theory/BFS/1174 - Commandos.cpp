#include<bits/stdc++.h>
using namespace std;
vector<int>adj[200];
int vis[200];

void bfs(int source, int level[])
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
            int node= adj[u][i];
            if(vis[node]==0)
            {
                vis[node]=1;
                level[node]= level[u]+1;
                q.push(node);
            }
        }
    }

}


int main()
{
    int t=0,test;
    cin>>test;

    while(t<test){

    int n,r,mx=0,i,x,y,s,d;
    int level1[200],level2[200];

    memset(level1, 0, sizeof level1);
    memset(level2, 0, sizeof level2);
    memset(vis,0,sizeof vis);

    scanf("%d %d",&n,&r);

    for(i=0;i<r;i++)
    {
        scanf("%d %d",&x,&y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    scanf("%d %d",&s,&d);

    bfs(s,level1);
    memset(vis,0,sizeof(vis));
    bfs(d,level2);

    for(i=0;i<n;i++)
    {
        mx= max(mx,  level1[i]+level2[i]);

    }

    printf("Case %d: %d\n",++t,mx);

    for(i=0;i<n;i++) adj[i].clear();

    }


    return 0;
}
