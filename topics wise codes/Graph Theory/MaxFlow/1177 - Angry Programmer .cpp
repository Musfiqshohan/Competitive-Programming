#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<int,int>
#define inf 100000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
#define rep(i,a,n) for(int i=a;i<n;i++)
using namespace std;
int Graph[165][165], rGraph[165][165], parent[165];
bool bfs(int s, int t)
{
    bool vis[165];
    memset(vis,0,sizeof vis);

    vis[s]=1;
    queue<int>q;
    q.push(s);

    while(!q.empty())
    {
        int u=q.front();
        q.pop();

        for(int v=1; v<160; v++)
        {
            if(vis[v]==0 && rGraph[u][v]>0)
            {
            //printf("%d->%d %d\n",u,v, rGraph[u][v]);
                vis[v]=1;
                parent[v]=u;
                q.push(v);

            }
        }
    }

    return (vis[t]==true);
}

int fordFulkerson(int s, int t)
{
    int u,v;
    for(int i=0; i<160; i++)
        for(int j=0; j<160; j++)
            {rGraph[i][j]=Graph[i][j];
            //if(rGraph[i][j]>0)
               // printf("%d %d\n",i,j);
            }




    int max_flow=0;

       bfs(s,t);

    while(bfs(s,t))
    {
        int path_flow=INT_MAX;

        for(v=t; v!=s; v=parent[v])
        {
            int u=parent[v];
            path_flow=min(path_flow, rGraph[u][v]);

        }

        for(v=t; v!=s; v=parent[v])
        {
            int u=parent[v];
            rGraph[u][v]-=path_flow;
            rGraph[v][u]+=path_flow;
        }

        max_flow+=path_flow;
      //  cout<<path_flow<<endl;


    }

    return max_flow;


}


int main()
{
    int tt=0, test;
    cin>>test;
    while(tt<test)
    {
        int M,W,x,u,v,w;
        scanf("%d %d",&M,&W);

        for(int i=2; i<=M-1; i++)
        {
            scanf("%d",&x);

            Graph[i][i+100]=x;
           // Graph[i+100][i]=x;

        }



        rep(i,0,W)
        {
            scanf("%d %d %d",&u,&v,&w);

            int ex=100;


            if(u==1 || u==M) Graph[u][v]=w;
            else
            Graph[u+ex][v]=w;

            if(v==1 || v==M) Graph[v][u]=w;
            else
            Graph[v+ex][u]=w;
        }


        int res=0;
        res=fordFulkerson(1,M);

        printf("Case %d: %d\n",++tt,res);


        memset(Graph,0,sizeof Graph);
        memset(rGraph,0,sizeof rGraph);
        memset(parent,0,sizeof parent);



    }



    return 0;
}
