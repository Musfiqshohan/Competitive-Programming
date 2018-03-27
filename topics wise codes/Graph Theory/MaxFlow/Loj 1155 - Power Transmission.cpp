#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

int Graph[205][205], rGraph[205][205], parent[205];


bool bfs(int s, int t)
{
    bool vis[205];
    memset(vis,0,sizeof vis);

    vis[s]=true;
    parent[s]=-1;
    queue<int>q;
    q.push(s);

    while(!q.empty())
    {
        int u= q.front();
        q.pop();

        for(int v=0; v<=201; v++)
        {
            if(vis[v]==false && rGraph[u][v]>0)
            {
                //  printf("%d->%d\n",u,v);
                vis[v]=true;
                q.push(v);
                parent[v]=u;
            }
        }
    }

    return (vis[t]==true);

}

int fordFulkerson(int s, int t)
{
    int u,v;
    for(int i=0; i<=201; i++)
        for(int j=0; j<=201; j++)
            rGraph[i][j]=Graph[i][j];

    int maxflow=0;
    int cnt=0;
    while(bfs(s,t))
    {
        int path_flow=INT_MAX;

        for(int v=t; v!=s ; v= parent[v])
        {
            int u= parent[v];
            path_flow= min(path_flow, rGraph[u][v]);
        }

        for(int v=t; v!=s; v= parent[v])
        {
            int u= parent[v];
            rGraph[u][v]-=path_flow;
            rGraph[v][u]+=path_flow;
        }
        maxflow+=path_flow;

        //  puts("End");
        //    cout<<path_flow<<endl;



    }

    return maxflow;

}

int main()
{
    int tt=0,test;
    cin>>test;

    while(tt<test)
    {
        int n,m,x,u,v,w;
        scanf("%d",&n);

        for(int i=1; i<=n; i++)
        {
            scanf("%d",&x);
            Graph[i][i+100]=x;
        }

        scanf("%d",&m);

        for(int i=0; i<m; i++)
        {
            scanf("%d %d %d",&u,&v,&w);
            Graph[u+100][v]=w;
        }

        int b,d;
        cin>>b>>d;

        for(int i=0; i<b; i++)
        {
            scanf("%d",&x);
            Graph[0][x]=1e6;
        }
        for(int i=0; i<d; i++)
        {
            scanf("%d",&x);
            Graph[x+100][201]=1e6;
        }


        int res= fordFulkerson(0,201);
        printf("Case %d: %d\n",++tt,res);

        memset(Graph,0,sizeof Graph);
        memset(rGraph,0,sizeof rGraph);
        memset(parent,0,sizeof parent);




    }


}
