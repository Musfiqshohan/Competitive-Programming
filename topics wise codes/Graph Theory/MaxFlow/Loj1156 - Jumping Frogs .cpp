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
    int flow,cap, ds;
};


int stones[205],dist[205],cur[205];
bool isSmall[205];
vector<Edge>Graph[205];

void clearr(int n)
{
    for(int i=0; i<=n; i++) Graph[i].clear();
}

void addEdge(int s, int t, int cap, int d)
{
    Edge a= { t, Graph[t].size(), 0, cap, d };
    Edge b= { s, Graph[s].size(), 0,  0, d };
    Graph[s].push_back(a);
    Graph[t].push_back(b);
}

bool dinic_bfs(int s, int t)
{
    memset(dist,-1,sizeof dist);

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
                //printf("%d -> %d %d\n",u,e.v,e.ds);
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
        if(e.flow>=e.cap)
            continue;
        if(dist[e.v]== dist[u]+1)
        {
            int df= dinic_dfs(e.v, min(f, e.cap- e.flow), dest);
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

        while(int delta=dinic_dfs(s,INT_MAX,t))
            result+=delta;
        // cout<<"res "<<result<<endl;
    }

    return result;
}


void createGraph(int n, int lim)
{
    for(int i=1; i<=n; i++)
    {
        if(isSmall[i]==true)
            addEdge(i, i+n, 1, 0);
    }


    for(int i=0; i<=n; i++)
    {
        for(int j=i+1; j<=n; j++)
        {
            if(stones[j]-stones[i]<=lim)
            {
                if(i==0)
                    addEdge(i,j, 2, stones[j]);
                else if(isSmall[i]==true)
                    addEdge(i+n,j,INT_MAX, stones[j]-stones[i]);
                else
                    addEdge(i,j,INT_MAX, stones[j]-stones[i] );

            }
        }
    }

}

int main()
{
    int tt=0,test;
    cin>>test;

    while(tt<test)
    {
        int n,d;
        scanf("%d %d",&n,&d);
        //  getchar();
        char ch,t;

        for(int i=1; i<=n; i++)
        {
            // scanf(" %c-%d ",&Ch,&stones[i]);
            cin>>ch;
            cin>>t;
            cin>>stones[i];

            if(ch=='S')
                isSmall[i]=true;

        }

        stones[++n]=d;
        sort(stones,stones+n);

        int low=0, high=INT_MAX,cnt=32,mid;

        while(cnt--)
        {
            mid=low+ (high-low)/2;
            //mid=92 ;
            createGraph(n,mid);
            int res= maxFlow(0,n);
            //   printf("lim= %d   flow= %d\n",mid, res);

            if(res>=2)
                high=mid;
            else low=mid;

            clearr(2*n+1);
        }

        createGraph(n,mid);
        if(maxFlow(0,n)<2) mid++;


        printf("Case %d: %d\n",++tt,mid);


        ms(isSmall,0);
        ms(stones,0);

    }



    return 0;
}

