#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<int,int>
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
#define rep(i,n) for(int i=0;i<n;i++)
#define inf 500
using namespace std;
int cap[105], g1[105],g2[105], Graph[405][405], rGraph[405][405], parent[405];


bool bfs(int s, int t)
{
    bool vis[t+5];
    memset(vis,0,sizeof vis);
    vis[s]=1;

    queue<int>q;
    q.push(s);

    while(!q.empty())
    {
        int u=q.front();
        q.pop();

        for(int v=0; v<=t; v++)
        {
            if(rGraph[u][v]>0 && !vis[v])
            {
              //  printf("%d -> %d\n",u,v);
                vis[v]=true;
                parent[v]=u;
                q.push(v);
            }
        }
    }

    return (vis[t]==true);
}

int fordfulkerson(int s, int t)
{
    for(int i=0; i<=401; i++)
        for(int j=0; j<=401; j++)
            rGraph[i][j]=Graph[i][j];

    int max_flow=0;

    //bfs(s,t);

    while(bfs(s,t))
    {
        int path_flow=INT_MAX;

        for(int v=t; v!=s; v=parent[v])
        {
            int u=parent[v];
            path_flow= min(path_flow, rGraph[u][v]);
        }

        for(int v=t; v!=s; v=parent[v])
        {
            int u=parent[v];
            rGraph[u][v]-=path_flow;
            rGraph[v][u]+=path_flow;
        }

        //cout<<path_flow<<endl;
        max_flow+=path_flow;
    }


    return max_flow;

}
int main()
{
    int tt=0,test;
    cin>>test;

    while(tt<test)
    {
        int n,m;
        scanf("%d",&n);

        for(int i=1; i<=n; i++)
            scanf("%d",&g1[i]);

        scanf("%d",&m);

        for(int i=1; i<=m; i++)
        {
            scanf("%d",&g2[i]);
            Graph[200+i][300+i]=1;
            Graph[300+i][401]=1;
        }


        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(g2[j]%g1[i]==0)
                {
                    cap[i]++;

                    Graph[i+100][200+j]=inf;
                }
            }
        }



        for(int i=1; i<=n; i++)
        {
            Graph[i][i+100]=1; //cap[i];
           // printf("%d %d %d\n",i,i+100, cap[i]);
            Graph[0][i]=inf;
        }


        int res=fordfulkerson(0,401);

        printf("Case %d: %d\n",++tt,res);

        ms(parent,0);
        ms(Graph,0);
        ms(rGraph,0);
        ms(cap,0);
        ms(g1,0);
        ms(g2,0);

    }
}
