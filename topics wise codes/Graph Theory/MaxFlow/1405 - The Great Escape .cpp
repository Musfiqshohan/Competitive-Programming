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

int dist[205],cur[205];
vector<Edge>Graph[20009];

char input[101][101];

bool isOccup[20009];

void addEdge(int s, int t, int cap)
{
    if(s!=0 && isOccup[t]==true) return;

//    if(s==26)
//    {
//        printf("%d edged %d\n",s,t);
//    }


  //  printf("edge to %d to %d\n",s ,t);
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
               // printf("%d -> %d  (e.flow=%d < e.cap=%d)\n",u,e.v, e.flow, e.cap);
                dist[e.v]= dist[u]+1;
                q.push(e.v);
            }
        }

    }

    printf("dist= %d, t= %d\n",dist[t],t);
    return (dist[t]>=0);

}

int dinic_dfs(int u, int f, int dest)
{
    if(u==dest) {  printf("dest= %d,,,  f=%d\n",dest,f);   return f;  }

    for(int i=cur[u]; i<Graph[u].size(); i++)
    {
        Edge &e= Graph[u][i];
        if(e.flow>=e.cap)
         continue;

       //  if(u==26)
        //  printf("%d -> %d  %d,%d\n",u,e.v,dist[e.v], dist[u]);

        if(dist[e.v]==dist[u]+1)
        {
            int df=dinic_dfs(e.v, min(f,e.cap - e.flow ), dest);
          //  printf("min=  %d  %d  df=%d\n", f, e.cap-e.flow,df);

            if(df>0)
            {
                e.flow+=df;
                Graph[e.v][e.rev].flow-=df;
                return df;
            }
        }

    }


  //  printf("No place to go\n");

    return 0;
}




int maxFlow(int s, int t)
{
    int result=0;

    int cnt=0;
    while(dinic_bfs(s,t))
    {
        memset(cur,0,sizeof cur);
        while(int delta=dinic_dfs(s,INT_MAX, t))
            result+=delta;

        printf("result->%d\n",result);


        if(++cnt>1) break;
    }

    return result;
}

int main()
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
                addEdge(i*m+j+n2, i*m+j-1,   1);
                //addEdge(i*m+j-1, i*m+j+n2,   1000);

            }

            //if(i*m+j+1<= (i+1)*m)
            if(j<m)
            {
                addEdge(i*m+j+n2, i*m+j+1,   1);
               // addEdge( i*m+j+1, i*m+j+n2,  1000);
            }

            //if((i-1)*m+j>0)
            if(i>0)  ///changed here
                {addEdge(i*m+j+n2, (i-1)*m+j, 1);
               // printf("%d %d ,, %d %d\n", i*m+j+n2, (i-1)*m+j, i, j);

                }

            //if( (i+1)*m+j <= (n+1)*m )
            if(i<n-1)   /// changed here
            {
                addEdge(i*m+j+n2, (i+1)*m+j, 1);
              //  addEdge( (i+1)*m+j,  i*m+j+n2,1000);
            }


            if(i==0 || j==1 || i==n-1 || j==m)
            {
                addEdge(i*m+j+n2, sink, 1);
            }

        }
    }

    int tot=maxFlow(src,sink);

    printf("tot= %d pep=%d\n",tot,pep);
    if(tot==pep) printf("yes\n");
    else printf("no\n");





    return 0;
}
