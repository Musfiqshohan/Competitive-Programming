#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<int,int>
#define inf 100000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int Graph[105][105], rGraph[105][105], parent[105], g1[55], g2[55];

bool bfs(int s, int t)
{
    bool vis[105];
    memset(vis,0,sizeof vis);

    vis[s]=1;
    queue<int>q;
    q.push(s);

    while(!q.empty())
    {
        int u=q.front();
        q.pop();

        for(int v=s; v<=t; v++)
        {
            if(rGraph[u][v]>0 && vis[v]==false)
            {
                //  printf("%d -> %d\n",u,v);
                vis[v]=true;
                q.push(v);
                parent[v]=u;
            }
        }
    }

    return (vis[t]==true);

}


int fordfulkerson(int s, int t, int n)
{
    for(int i=s; i<=t; i++)
        for(int j=s; j<=t; j++)
        {
            if(Graph[i][j]>0)
            {
                // printf("%d -> %d %d\n",i,j,Graph[i][j]);
                rGraph[i][j]=Graph[i][j];
            }

        }

    int max_flow=0;

    int u,v;

//        bfs(s,t);
    while(bfs(s,t))
    {
        int path_flow= INT_MAX;

        for(v=t; v!=s; v=parent[v])
        {
            u=parent[v];
            printf("%d-> %d ",v,u);
            path_flow= min(path_flow, rGraph[u][v]);
        }
        puts("");

        for(v=t; v!=s; v=parent[v])
        {
            u=parent[v];

            if(v==t && path_flow==1 && rGraph[v][u]==1) continue;
                //rGraph[u][v]=0, rGraph[v][u]+=rGraph[u][v];
            else
            {
                rGraph[u][v]-=path_flow;
                rGraph[v][u]+=path_flow;
            }
        }

        cout<<path_flow<<endl;
        max_flow+=path_flow;
    }

    return max_flow;

}

int  main()
{
    int tt=0, test;
    cin>>test;

    while(tt<test)
    {
        int n;
        scanf("%d",&n);

        for(int i=1; i<=n; i++)
        {
            scanf("%d",&g1[i]);
            Graph[0][i]=1;
        }

        for(int i=1; i<=n; i++)
        {
            scanf("%d",&g2[i]);
            Graph[i+n][2*n+1]=2;
        }


        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
            {
                if(g1[i]>g2[j])
                    Graph[i][j+n]=2;
                else if(g1[i]==g2[j])
                    Graph[i][j+n]=1;

            }

        int res= fordfulkerson(0, 2*n+1, n);

        printf("Case %d: %d\n",++tt,res);

        ms(Graph,0);
        ms(rGraph,0);
        ms(parent,0);

    }


    return 0;
}
