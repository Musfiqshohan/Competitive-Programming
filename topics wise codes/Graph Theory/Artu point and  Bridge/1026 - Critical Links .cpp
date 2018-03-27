#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<int,int>
#define inf 100000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(b,"w",stdout)
using namespace std;

int times;
vector<int>adj[10009];
vector<pii>edge;
int disc[10009], low[10009], vis[10009], par[10009];


void clearr(int n)
{
    times=0;
    for(int i=0;i<=n;i++) adj[i].clear();
    edge.clear();
    ms(vis,0);
}

void dfs(int src)
{
    disc[src]= low[src] = ++times;

    for(int i=0; i<adj[src].size(); i++)
    {
        int node= adj[src][i];

        if(vis[node]==0 )
        {


            vis[node]=1;
            par[node]=src;

            dfs(node);

            low[src]= min( low[src], low[node]);

            if(low[node]>disc[src])
            {
                int mn= min(src,node);
                int mx= max(src, node);
                edge.push_back({mn, mx});
            }
        }

        else if(node != par[src])  //back edge
        {
            low[src]= min( low[src], disc[node]);
        }



    }




}


bool compare(pii a, pii b)
{
    if(a.first==b.first)
        return a.second<b.second;
    return a.first<b.first;

}

int main()
{

    int tt=0,test;
    cin>>test;

    while(tt<test) {

    int n,x,y;
    scanf("%d",&n);
    vector<int>exist;

    for(int i=0; i<n; i++)
    {
        scanf("%d",&x);
        exist.push_back(x);

        getchar();
        int m;
        char c1,c2;
        scanf("%c%d%c",&c1,&m,&c2);


        for(int j=0; j<m; j++)
        {
            scanf("%d",&y);
            adj[x].push_back(y);
        }
    }

    for(int i=0; i<exist.size(); i++)
    {
        int src= exist[i];


        if(vis[src]==0)
        {
            //par[src]=src;
            vis[src]=1;
            dfs(src);

        }

    }

    sort(edge.begin(), edge.end(), compare);

    printf("Case %d:\n",++tt);

    printf("%d critical links\n",edge.size());
    for(int i=0;i<edge.size();i++)
        printf("%d - %d\n",edge[i].first,edge[i].second);


    clearr(n);


    }


    return 0;
}
