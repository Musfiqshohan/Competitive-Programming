#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
#define ll long long
#define pii pair<int,int>
#define inf 100000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
using namespace std;


struct node
{
    int x,y,ni,mi;
};
struct Edge
{
    int v,rev;
    int flow, cap;
};


node ara[205];
vector<Edge> Graph[205];
int n;
int dist[205],cur[205];


void addEdge(int s, int t, int cap)
{
    Edge a = { t, Graph[t].size(), 0, cap };
    Edge b = { s, Graph[s].size(), 0, 0 };

    Graph[s].push_back(a);
    Graph[t].push_back(b);
}


double Calculate_Distance(node a, node b)
{
    return sqrt(
               (a.x-b.x)*(a.x-b.x)
               +(a.y-b.y)*(a.y-b.y)
           );
}


bool dinic_bfs(int s, int t)
{

    memset(dist,-1,sizeof dist);

    dist[s]=0;
    queue<int>q;
    q.push(s);

    while(!q.empty())
    {
        int u= q.front();
        q.pop();


        for(int i=0; i<Graph[u].size(); i++)
        {
            Edge &e= Graph[u][i];
            if(dist[e.v]<0 && e.flow<e.cap)
            {
                dist[e.v]=dist[u]+1;
                q.push(e.v);
            }
        }
    }


    return (dist[t]>=0);

}

int dinic_dfs(int u, int f, int dest)
{
    if(u==dest) return f;

    for(int i=cur[u]; i< Graph[u].size(); i++)
    {
        Edge &e= Graph[u][i];

        if(e.flow>=e.cap) continue;

        if(dist[e.v]== dist[u]+1)
        {
            int df= dinic_dfs(e.v, min(f, e.cap-e.flow), dest);
            if(df>0)
            {
                //printf("%d -> %d\n",u, e.v);
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
        // puts("hi");
        while(int delta= dinic_dfs(s,INT_MAX,t))
        {
           // cout<<delta<<endl;
            result+=delta;

        }
    }

    return result;

}


void init(int n)
{
    for(int i=0;i<=n;i++)
        Graph[i].clear();
}

int main()
{
    int tt=0,test;
    scanf("%d",&test);

    while(tt<test)
    {

        double d;
        scanf("%d",&n);
        scanf("%lf",&d);

        int totPenguins=0, source=0;
        for(int i=1; i<=n; i++)
        {
            scanf("%d %d %d %d",&ara[i].x, &ara[i].y, &ara[i].ni, &ara[i].mi);
            totPenguins+=ara[i].ni;

        }

        vector<int>vec;
        for(int sink=1; sink<=n; sink++)
        {
            init(2*n+1);

            for(int i=1; i<=n; i++)
            {
                addEdge(source,i,ara[i].ni);
                addEdge(i, i+n, ara[i].mi);
            }


            for(int i=1; i<=n; i++)
            {
                for(int j=i+1; j<=n; j++)
                {

                    double dis=Calculate_Distance(ara[i],ara[j]);
                    if(dis<=d)
                    {

                        // printf("%d -> %d\n",i,j);
                        addEdge(n+i,j,100001);
                        addEdge(n+j,i,100001);
                    }
                }
            }




            //  cout<<"hi"<<endl;


           // int sink=5;
            int res= maxFlow(0,sink);
          //  cout<<res<<endl;
            if(res==totPenguins)
                vec.push_back(sink);
        }

        printf("Case %d: ",++tt);
        if(vec.size()==0) printf("-1\n");
        else
        {
            for(int i=0; i<vec.size(); i++)
            {
                if(i) printf(" ");
                printf("%d",vec[i]-1);
            }
            puts("");
        }


        for(int i=0; i<=2*n; i++)
            Graph[i].clear();

        vec.clear();
        ms(ara,0);


    }

}
