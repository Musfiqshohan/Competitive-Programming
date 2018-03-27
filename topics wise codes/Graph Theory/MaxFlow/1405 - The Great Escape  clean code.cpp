#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
#define ll long long
#define pii pair<int,int>
#define inf 100000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
using namespace std;

struct Edge
{
    int v,rev;
    int flow, cap;
};

int dist[20009],cur[20009];
vector<Edge>Graph[20009];

char input[101][101];

bool isOccup[20009];


void clearr(int nn)
{
    for(int i=0;i<=nn;i++)
        Graph[i].clear();
    ms(isOccup,0);

}

void addEdge(int s, int t, int cap)
{
    if(s!=0 && isOccup[t]==true) return;

    Edge a= {t, Graph[t].size(), 0, cap};
    Edge b= {s, Graph[s].size(), 0, 0 };

    Graph[s].push_back(a);
    Graph[t].push_back(b);


}


bool dinic_bfs(int s, int  t)
{
    memset(dist,-1, sizeof dist);
    dist[s]=0;
    queue<int>q;
    q.push(s);


    while(!q.empty())
    {
        int u=q.front();
        q.pop();

        for(int i=0; i<Graph[u].size(); i++)
        {
            Edge e= Graph[u][i];

            if(dist[e.v]<0 && e.flow<e.cap )
            {
                dist[e.v]= dist[u]+1;
                q.push(e.v);
            }
        }

    }

    return (dist[t]>=0);

}

int dinic_dfs(int u, int f, int dest)
{
    if(u==dest) return f;

    for(int i=cur[u]; i<Graph[u].size(); i++)
    {
        Edge &e= Graph[u][i];
        if(e.flow>=e.cap)
            continue;

        if(dist[e.v]==dist[u]+1)
        {
            int df=dinic_dfs(e.v, min(f,e.cap - e.flow ), dest);

            if(df>0)
            {
                e.flow+=df;
                Graph[e.v][e.rev].flow-=df;
                return df;
            }
        }

    }

    return 0;
}




int maxFlow(int s, int t)
{
    int result=0;

    while(dinic_bfs(s,t))
    {
        memset(cur,0,sizeof cur);
        while(int delta=dinic_dfs(s,INT_MAX, t))
            result+=delta;
    }

    return result;
}

int main()
{

    int tt,test=0;
    scanf("%d",&test);

    while(tt<test)
    {


        int n,m;
        scanf("%d %d",&n,&m);

        getchar();

        int n2=n*m;

        int src= 0, sink= m*n+n2+1, pep=0;

        for(int i=1; i<=n; i++)
        {
            scanf("%s",&input[i]);
            getchar();
        }


        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                char ch;
                ch= input[i][j-1];
                if(ch=='*')
                {
                    isOccup[(i-1)*m+j]=true;
                    addEdge(src, (i-1)*m+j, 1);
                    pep++;
                }

            }
        }


        for(int i=0; i<n; i++) /// n  row, m col
        {
            for(int j=1; j<=m; j++)
            {



                addEdge(i*m+j, i*m+j+n2, 1);

                if(j>1)
                {
                    addEdge(i*m+j+n2, i*m+j-1,   1000);
                }


                if(j<m)
                {
                    addEdge(i*m+j+n2, i*m+j+1,   1000);
                }


                if(i>0)  ///changed here
                {
                    addEdge(i*m+j+n2, (i-1)*m+j, 1000);
                }


                if(i<n-1)   /// changed here
                {
                    addEdge(i*m+j+n2, (i+1)*m+j, 1000);
                }


                if(i==0 || j==1 || i==n-1 || j==m)
                {
                    addEdge(i*m+j+n2, sink, 1);
                }

            }
        }

        int tot=maxFlow(src,sink);

        // printf("tot= %d pep=%d\n",tot,pep);

        printf("Case %d: ",++tt);
        if(tot==pep) printf("yes\n");
        else printf("no\n");

        clearr(2*n2+1);


    }



    return 0;
}

