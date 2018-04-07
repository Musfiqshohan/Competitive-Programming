///https://vjudge.net/contest/219574#problem/I

/**
1. Think exp as left col= I will not execute these exps
2. right col= will take these instruments
3. I have to give the ans: "whether taking this exp with the cost of these instruments is better or not executing the exp
where i dont get any profit." So, if any instrument is cheap then exp that means it will bring profit so, it will be cut in
min cut. and go further. If I find no instrument is then cheaper than any exp then cut the minimum exp which means i will not
execute this exp.
4.when the all min cut will happen it will mean the remaining exp will take placce and instruments will not taken(cz their
corresponding exp gives less profit so was cut).
5. The eq= max profit= total profit- (least profit exp + least instruments)

*/

#include<bits/stdc++.h>
#define i64 long long
#define inf  100000000000
#define ms(a,b) memset(a,0,sizeof a)
using namespace std;

const i64 MAXN=205,SRC=0,SINK=203,lastnode=100;

i64 dist[MAXN], work[MAXN];

struct Edge
{
    i64 to,rev;
    i64 f,cap;
};
vector<Edge>g[MAXN];


void clearr()
{
    for(i64 i=0;i<MAXN;i++)
        g[i].clear();

    ms(dist,0);
    ms(work,0);
}

void addEdge(i64 s, i64 t, i64 cap)
{
    Edge a= {t,(i64)g[t].size(), 0, cap};
    Edge b= {s,(i64)g[s].size(), cap,cap};

    g[s].push_back(a);
    g[t].push_back(b);
}


bool dinic_bfs(i64 src, i64 dest)
{
    memset(dist,-1,sizeof dist);
    dist[src]=0;
    queue<i64>q;
    q.push(src);

    while(!q.empty())
    {
        i64 u=q.front();
        q.pop();

        for(i64 j=0; j<g[u].size(); j++)
        {
            Edge &e= g[u][j];

            if(dist[e.to]<0 && e.f<e.cap)
            {
                //pri64f("%d->%d\n",u,e.to);
                dist[e.to]=dist[u]+1;
                q.push(e.to);
            }
        }

    }
    return dist[dest]>=0;

}


i64 dinic_dfs(i64 u, i64 dest, i64 f)
{
    if(u==dest)
        return f;
    for(i64 &i=work[u]; i< g[u].size(); i++)
    {
        Edge &e= g[u][i];
        if(e.cap<=e.f) continue;

        //   pri64f("%d->%d\n",u,e.to);
        if(dist[e.to]==dist[u]+1)
        {
            i64 df=dinic_dfs(e.to,dest, min(e.cap-e.f,f));
            if(df>0)
            {
                e.f+=df;
                g[e.to][e.rev].f-=df;
                return df;
            }
        }

    }
    return 0;

}



i64 maxFlow(i64 src,i64 dest)
{
    i64 result=0;
    i64 cnt=0;
    while(dinic_bfs(src,dest))
    {

        memset(work,0,sizeof work);
        while(i64 delta=dinic_dfs(src,dest,inf))
            result+=delta;

        //  pri64f("res=%d\n",result);
    }
    return result;

}


int main()
{

    i64 tt=0,test;
    cin>>test;

    while(tt<test)
    {

        i64 m,n,x,q,qi;
        cin>>m>>n;


        i64 tot=0;
        for(i64 i=1; i<=m; i++)
        {
            cin>>x;
            tot+=x;
            addEdge(SRC,i,x);
        }

        for(i64 i=1; i<=n; i++)
        {
            cin>>x;
            addEdge(i+lastnode,SINK,x);
        }


        for(i64 i=1; i<=m; i++)
        {
            cin>>q;
            for(i64 j=0; j<q; j++)
            {
                cin>>qi;
                addEdge(i,lastnode+qi,inf);
            }

        }

        i64 flow=maxFlow(SRC,SINK);
      //  cout<<tot<<" "<<flow<<endl;

        tot-=flow;

        printf("Case %lld: %lld\n",++tt,tot);
        clearr();


    }
}
