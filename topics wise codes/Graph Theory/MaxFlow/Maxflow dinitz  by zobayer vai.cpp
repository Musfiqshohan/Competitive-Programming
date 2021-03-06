#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
#define i64 long long
#define pii pair<int,int>
#define INF 1000000009
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
using namespace std;

int src,snk, nNode,nEdge;

const int MAXN =100009;
char input[105][105];

bool isOccup[MAXN];

int Q[MAXN], fin [MAXN], pro[MAXN], dist[MAXN];

int flow[MAXN], cap[MAXN], nextt[MAXN], to[MAXN];

inline void init(int _src, int _snk, int _n)
{
    ms(Q,0);
    ms(pro,0);
    ms(dist,0);

    ms(flow,0);
    ms(cap,0);
    ms(nextt,0);
    ms(to,0);
    ms(isOccup,0);
    ms(input,0);

    src= _src, snk=_snk, nNode=  _n,  nEdge=0;
    ms(fin,-1);
}

inline void addEdge(int u, int v, int _cap)
{

    if(u!=0 && isOccup[v]==true) return;


    to[nEdge]=v, cap[nEdge]=_cap, flow[nEdge]=0;
    nextt[nEdge]=fin[u], fin[u]=nEdge++;

    to[nEdge]=u, cap[nEdge]=0,  flow[nEdge]=0;
    nextt[nEdge]=fin[v], fin[v]=nEdge++;
}


bool bfs()
{
    int st, en, i,u, v;
    ms(dist,-1);
    dist[src]=st=en=0;
    Q[en++]=src;


    while(st<en)
    {
        u=Q[st++];

        for(i=fin[u]; i>=0; i=nextt[i])
        {
            v=to[i];
          //  printf("%d %d  i=%d  cap= %d  flo=%d\n",u,v,i,flow[i],cap[i]);
            if(flow[i]<cap[i] && dist[v]==-1)
            {
                dist[v]=dist[u]+1;
                Q[en++]=v;
            }
        }

    }


    return (dist[snk]!=-1);

}

int dfs(int u, int f1)
{
    if(u==snk ) return f1;

    for(int &e=pro[u],  v, df ; e>=0 ; e=nextt[e])
    {
        v=to[e];
        if(flow[e]< cap[e] && dist[v]==dist[u]+1)
        {
      //  printf("%d to %d?\n",u,v);
            df= dfs(v, min(cap[e]-flow[e], f1));
            if(df>0)
            {
                flow[e]+=df;
                flow[e^1]-=df;
                //cap[e]-=df;
                return df;
            }
        }
    }

    return 0;
}


int dinitz()
{
    int ret=0;
    int df;

    while(bfs()){

        for(int i=0; i<= nNode; i++) pro[i]=fin[i];

        int cnt=0;
        while(true){

            df=dfs(src, INF);
            if(df) ret+= (int)df;
            else break;
            cnt+=df;
        }
    }

    return ret;
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

        init(src,sink,2*n2+1 );

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
                    addEdge(i*m+j+n2, i*m+j-1,   1);
                }


                if(j<m)
                {
                    addEdge(i*m+j+n2, i*m+j+1,   1);
                }


                if(i>0)  ///changed here
                {
                    addEdge(i*m+j+n2, (i-1)*m+j, 1);
                }


                if(i<n-1)   /// changed here
                {
                    addEdge(i*m+j+n2, (i+1)*m+j, 1);
                }


                if(i==0 || j==1 || i==n-1 || j==m)
                {
                    addEdge(i*m+j+n2, sink, 1);
                }

            }
        }

        int tot=dinitz();

        // printf("tot= %d pep=%d\n",tot,pep);

        printf("Case %d: ",++tt);
        if(tot==pep) printf("yes\n");
        else printf("no\n");




    }



    return 0;
}




