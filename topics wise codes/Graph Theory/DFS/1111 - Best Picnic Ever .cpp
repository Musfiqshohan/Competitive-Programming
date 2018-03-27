#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<int,int>
#define inf 100000000000
using namespace std;

int vis[1009], cnt[1009],ara[109];
vector<int>adj[1009];

void clearr()
{
    ms(vis,0);
    ms(cnt,0);

}

void  dfs(int src)
{
    for(int i=0; i<adj[src].size(); i++)
    {
        int node= adj[src][i];

        if(vis[node]==0)
        {
            vis[node]=1;
            cnt[node]++;
            dfs(node);
        }
    }
}

int main()
{
    int t=0,test;
    cin>>test;

    while(t<test)
    {
        int k,n,m,u,v;
        scanf("%d %d %d",&k,&n,&m);

        for(int i=1; i<=k; i++)
            scanf("%d",&ara[i]);

        for(int i=1; i<=m; i++)
        {
            scanf("%d %d",&u,&v);
            adj[u].push_back(v);
        }

        for(int i=1; i<=k; i++)
        {
            ms(vis,0);
            vis[ara[i]]=1;
            cnt[ara[i]]++;

            dfs(ara[i]);

        }

        int tot=0;

        for(int i=1; i<=n; i++)
        {
            //printf("%d  ",cnt[i]);
            if(cnt[i]==k) tot++;
        }


        printf("Case %d: %d\n",++t,tot);
        for(int i=1; i<=n; i++)
            adj[i].clear();
        clearr();

    }
    return 0;
}
