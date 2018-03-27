#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<int,int>
#define inf 100000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
#define rep(i,a,n) for(int i=a;i<n;i++)
using namespace std;
int Graph[365][365], rGraph[365][365],parent[365];
map<string,int>mp;
int src,dest, l,r;
void prepare()
{
    mp["XS"]=0;
    mp["S"]=1;
    mp["M"]=2;
    mp["L"]=3;
    mp["XL"]=4;
    mp["XXL"]=5;

    src=360;
    dest=361;


}

bool bfs(int s, int t)
{
    bool vis[365];
    memset(vis,0,sizeof vis);

    vis[s]=true;
    parent[s]=-1;
    queue<int>q;
    q.push(s);



    while(!q.empty())
    {
        int u=q.front();
        q.pop();

        for(int v=0; v<365; v++)
        {
            if(vis[v]==false && rGraph[u][v]>0)
            {
                //  printf("%d ->%d, %d\n",u,v, rGraph[u][v]);
                vis[v]=true;
                q.push(v);
                parent[v]=  u;
            }
        }

    }

    return (vis[t]==true);

}

int fordFulkerson(int s, int t)
{

    for(int i=0; i<365; i++)
        for(int j=0; j<365; j++)
            rGraph[i][j]=Graph[i][j];

    int max_flow=0;

    while(bfs(s,t))
    {
        int path_flow=INT_MAX;

        //puts("->");
        for(int v=t ; v!=s; v= parent[v])
        {
            int u= parent[v];
            path_flow= min(path_flow, rGraph[u][v] );
            //   printf("%d-> %d ",v,u);
        }
        //  puts("->");


        for(int v=t ; v!=s; v= parent[v])
        {
            int u= parent[v];
            rGraph[u][v]-=path_flow;
            rGraph[v][u]+=path_flow;
        }

        // cout<<path_flow<<endl;

        max_flow+=path_flow;

    }


    return max_flow;


}

int main()
{
    prepare();

    int tt,test;
    cin>>test;

    while(tt<test)
    {
        int n,m;
        scanf("%d %d",&n,&m);
        getchar();

        n=n*6;
        int packs=n/6;

        string s1,s2;
        for(int i=1; i<=m; i++)
        {
            cin>>s1>>s2;
            int t1=mp[s1],t2=mp[s2];

            Graph[src][i+300]=1;

            for(int j=0; j<packs; j++)
            {
                Graph[i+300][6*j+t1]=1;
                Graph[i+300][6*j+t2]=1;

                Graph[6*j+t1][dest]=1;
                Graph[6*j+t2][dest]=1;

            }


        }



        int res= fordFulkerson(src,dest);

        //  cout<<"res "<<res<<endl;
        printf("Case %d: ",++tt);
        if(res==m)printf("YES\n");
        else printf("NO\n");

        memset(Graph,0,sizeof Graph);
        memset(rGraph,0,sizeof rGraph);
        memset(parent,0,sizeof parent);



    }


    return 0;
}
