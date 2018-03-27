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

int cnt=0,sink;
vector<int>exist;
int vis[109], indeg[1089];
vector<int>adj[109];
void dfs(int src)
{

    if(adj[src].size()==0) { cnt++;  sink=src; }
    for(int i=0;i<adj[src].size();i++)
    {
        int node= adj[src][i];

        if(vis[node]==0)
        {
            printf("%d->%d\n",src,node);
            vis[node]=1;
            dfs(node);
        }

    }

}


int main()
{
    int tt=0,test;
    cin>>test;

    while(tt<test) {
    int n,m,x,y, flag=0;
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        scanf("%d",&m);

        for(int j=0;j<m;j++)
        {
            scanf("%d %d",&x,&y);

            adj[x].push_back(y);
            exist.push_back(x);
            exist.push_back(y);

            indeg[y]++;

        }

    }


    vis[0]=1;
    dfs(0);

    for(int i=0;i<exist.size();i++)
    {
        if(vis[exist[i]]==0)   flag=1;
    }

    cout<<flag<<"xx"<<cnt<<endl;

    printf("Case %d: ",++tt);
    if(flag==1 || cnt>1) printf("NO\n");
    else if(cnt==1)
    {
        if(indeg[sink]>1)
            printf("NO\n");
        else printf("YES\n");
    }
    else printf("YES\n");

    ms(vis,0);
    exist.clear();
    for(int i=0;i<=109;i++) adj[i].clear();

    }
    return 0;
}
