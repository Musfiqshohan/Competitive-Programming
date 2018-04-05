///https://vjudge.net/contest/219574#problem/H
/**
note:
1.element range[1,100] = edge cap
2.each LR ray as in left col and RL ray in right col
then each LR ray distributes its sum into different RL rays. Those RL rays gets partial sum from other LR rays too
3.src to all nodes = total sum- (keep 1 for all cells)
*/
#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define i64 long long
#define pii pair<i64,i64>
#define INF 100000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
#define rep(i,n) for(i64 i=0;i<n;i++)
using namespace std;
const int MAXN=205;
const int LASTNODE=100, SRC=0, SINK=201;

int ara[55][55],ara2[55][55], dist[MAXN],work[MAXN],LR[MAXN],RL[MAXN],RES[55][55], num[MAXN];


struct Edge
{
    int to,rev;
    int f,cap;
};

vector<Edge>g[MAXN];

void clearr()
{
    ms(ara,0);
    ms(ara2,0);
    ms(dist,0);
    ms(work,0);
    ms(LR,0);
    ms(RL,0);
    ms(RES,0);
    ms(num,0);

    for(int i=0;i<=MAXN;i++)
        g[i].clear();

}
void addEdge(int s,int t,int cap)
{
    Edge a= {t,(int)g[t].size(),0,cap};
    Edge b= {s,(int)g[s].size(),cap,cap};
    g[s].push_back(a);
    g[t].push_back(b);
}

bool dinic_bfs(int src,int dest)
{
    memset(dist,-1,sizeof dist);
    dist[src]=0;
    queue<int>q;
    q.push(src);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int j=0; j<g[u].size(); j++)
        {
            Edge &e= g[u][j];
            int v=e.to;
           // printf("%d->%d\n",u,v);
            if(dist[v]<0 && e.f < e.cap)
            {
                dist[v]=dist[u]+1;
                //printf("ok %d(%d)->%d(%d)  \n",u,dist[u],v,dist[v]);
                q.push(v);
            }
        }
    }
    return dist[dest]>=0;
}


int dinic_dfs(int u, int dest,int f)
{
    if(u==dest)
        return f;

    for(int &i=work[u]; i<g[u].size(); i++)
    {
        Edge &e=g[u][i];
        if(e.cap<=e.f) continue;
        int v=e.to;
        if(dist[v]==dist[u]+1)
        {
            //printf("%d->%d  f=%d\n",u,v,min(f,e.cap-e.f));
            int df=dinic_dfs(v, dest,min(f,e.cap-e.f));
            if(df>0)
            {
                e.f+=df;
                g[v][e.rev].f-=df;
                return df;
            }
        }
    }

    return 0;
}

int maxFlow(int src, int dest)
{
    int result=0;
    while(dinic_bfs(src,dest))
    {
        ms(work,0);
        while(int delta=dinic_dfs(src,dest, INT_MAX))
        {
            result+=delta;
            //printf("res=%d\n",delta);
        }
    }
    return result;
}


void process_ara(int m,int n)
{
    int cnt=0;
    for(int i=1; i<=m; i++)
    {
        cnt++;

        for(int r=i,c=1; r>0 && c<=n ; r--, c++)
        {
            ara[r][c]=cnt;
            num[cnt]++;
        }
        addEdge(SRC,cnt,LR[cnt]-num[cnt]);
        // printf("edge={%d->%d  w=%d}\n",SRC,cnt, LR[cnt]);
    }

    //  cnt--;
    for(int i=2; i<=n; i++)
    {
        cnt++;
        for(int r=m, c=i; r>0 && c<=n; r--, c++)
        {
            ara[r][c]=cnt;
            num[cnt]++;
        }

        addEdge(SRC,cnt,LR[cnt]-num[cnt]);
        //printf("edge={%d->%d  w=%d}\n",SRC,cnt, LR[cnt]);
    }


//    for(int i=1;i<=m;i++)
//    {
//        for(int j=1;j<=n;j++)
//        {
//            printf("%d ",ara[i][j]);
//        }
//        puts("");
//
//    }

}



void make_graph(int m,int n)
{

    int cnt=0;
    for(int i=1; i<=m; i++)
    {
        cnt++;

        for(int r=i,c=n; r>0 && c>0 ; r--, c--)
        {
            addEdge(ara[r][c], cnt+LASTNODE, min(LR[ara[r][c]]- num[ara[r][c]],99));
            ara2[r][c]=cnt;
            // printf("edge={%d->%d w=%d}\n",ara[r][c],cnt+LASTNODE,LR[ara[r][c]]- num[ara[r][c]]+1);
        }
        addEdge(cnt+LASTNODE,SINK, RL[cnt]-num[cnt]);
        // printf("edge={%d->%d w=%d}\n",cnt+LASTNODE,SINK,RL[cnt]);
    }

    // cnt--;
    for(int i=n-1; i>=1; i--)
    {
        cnt++;
        for(int r=m, c=i; r>0 && c>0; r--, c--)
        {
            addEdge(ara[r][c], cnt+LASTNODE, min(LR[ara[r][c]]- num[ara[r][c]],99));
             //printf("edge={%d->%d w=%d}\n",ara[r][c],cnt+LASTNODE,LR[ara[r][c]]- num[ara[r][c]]+1);
            ara2[r][c]=cnt;
        }

        addEdge(cnt+LASTNODE,SINK, RL[cnt]-num[cnt]);
        // printf("edge={%d->%d w=%d}\n",cnt+LASTNODE,SINK,RL[cnt]);
    }


//    for(int i=1;i<=m;i++)
//    {
//        for(int j=1;j<=n;j++)
//        {
//            printf("%d ",ara2[i][j]);
//        }
//        puts("");
//
//    }

}

int main()
{
    int tt=0,test;
    cin>>test;
    while(tt<test)
    {
        int m,n;
        cin>>m>>n;

        for(int i=1; i<=n+m-1; i++)
            cin>>LR[i];

        for(int i=1; i<=n+m-1; i++)
            cin>>RL[i];

        process_ara(m,n);
        make_graph(m,n);


        int flow=maxFlow(SRC, SINK);
        // cout<<flow<<endl;



        int cnt=0;
        for(int i=1; i<=n; i++)
        {
            cnt++;
            for(int r=1,c=i;  r<=m, c>0; r++, c--)
            {
                RES[r][c]=g[cnt][r].f;
            }

        }

        for(int i=2; i<=m; i++)
        {
            cnt++;
            for(int r=i, c=n; r<=m, c>0 ; r++,c--)
            {
                RES[r][c]=g[cnt][n-c+1].f;
            }
        }

        printf("Case %d:\n",++tt);
        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(j>1) printf(" ");
                printf("%d",RES[i][j]+1);
            }
            puts("");
        }

        clearr();
    }


    return 0;

}
