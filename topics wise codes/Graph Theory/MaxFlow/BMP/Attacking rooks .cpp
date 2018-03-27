///https://vjudge.net/contest/197593#problem/A

#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
#define ll long long
#define pii pair<int,int>
#define INF 1000000009
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
using namespace std;

int src,snk, nNode,nEdge;

const int MAXN =100009;
int Q[MAXN], fin [MAXN], pro[MAXN], dist[MAXN];

int flow[MAXN], cap[MAXN], nextt[MAXN], to[MAXN];

char str[105][105];
int grid[105][105], m, n;



void init(int _src, int _snk, int _n)
{

    src=_src, snk=_snk, nNode= _n, nEdge=0;
}


inline void addEdge(int u, int v, int _cap)
{

    //  printf("%d edged %d\n",u,v);

    to[nEdge]=v, cap[nEdge]=_cap, flow[nEdge]=0;
    nextt[nEdge]=fin[u], fin[u]=nEdge++;

    to[nEdge]=u, cap[nEdge]=0, flow[nEdge]=0;
    nextt[nEdge]=fin[v], fin[v]=nEdge++;
}

bool bfs()
{
    int st, en, i,u,v;

    ms(dist,-1);

    dist[src]=st=en=0;

    Q[en++]=src;

    while(st<en)
    {
        u=Q[st++];

        for(i=fin[u]; i>=0; i=nextt[i])
        {
            v=to[i];
            if(flow[i]<cap[i] && dist[v]==-1)
            {
                //  printf("%d- > %d\n",u,v);
                dist[v]=dist[u]+1;
                Q[en++]=v;
            }
        }
    }

    return (dist[snk]!=-1);
}

int dfs(int u, int f1)
{

    if(u==snk) return f1;

    for(int &e=pro[u], v, df; e>=0; e= nextt[e])
    {
        v=to[e];
        if(flow[e]<cap[e] && dist[v]==dist[u]+1)
        {
            // printf("%d-> %d\n",u,v);
            df=dfs(v, min(cap[e]-flow[e], f1));
            if(df>0)
            {
                flow[e]+=df;
                flow[e^1]-=df;
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


//   bfs();

    while(bfs())
    {
        for(int i=0; i<=nNode; i++) pro[i]=fin[i];

        int cnt=0;
        while(true)
        {
            df=dfs(src, INF);
            if(df) ret+= df;
            else break;
        }

        //cout<<ret<<endl;
    }

    return ret;
}


int main()
{



    int nn;
    while(scanf("%d",&nn)!=EOF)
    {

        getchar();
        for(int i=0; i<nn; i++)
        {
            scanf("%s",&str[i]);
            getchar();
        }

        ms(grid,-1);
        ms(fin,-1);


        // puts("");

        int cnt=0;

        bool isOn=false;
        for(int i=0; i<nn; i++)
        {
            for(int j=0; j<nn; j++)
            {

                if(str[i][j]=='X')
                {
                    if(isOn==true)
                        continue;
                    else
                        isOn=true,cnt++;
                }
                else
                    isOn=false, grid[i][j]=cnt;
            }

            if(isOn==false)
                cnt++;
            else isOn=false;
        }


        m=cnt;

        cnt++;


        isOn=false;
        for(int i=0; i<nn; i++)
        {
            for(int j=0; j<nn; j++)
            {

                if(str[j][i]=='X')
                {
                    if(isOn==true)
                        continue;
                    else
                        isOn=true,cnt++;
                }
                else
                {
                    isOn=false;
                    addEdge(cnt, grid[j][i], 1);
                }
            }

            if(isOn==false)
                cnt++;
            else isOn=false;
        }


        int _src,_sink;
        _src= cnt+1;
        _sink=cnt+2;
        for(int i=0; i<=m; i++) addEdge(i,_sink,1);
        for(int i=m+1; i<=cnt; i++) addEdge(_src, i, 1);

        init(_src,_sink, cnt+2);



        int tot= dinitz();
        printf("%d\n",tot);
        // cout<<tot<<endl;

     //   clearr();


    }

    return 0;
}


