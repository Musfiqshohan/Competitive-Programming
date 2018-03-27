#include <iostream>
#include <vector>
#include <algorithm>
#include<stdio.h>
#include <cstdio>
#include <cstring>
using namespace std;
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
#define ll long long
#define pii pair<int,int>
#define inf 100000000000
using namespace std;


int vis[101],cnt[101];

int dfs(int src, vector<int>adj[])
{
    int tot=0;

    //if(cnt[src]!=0) return cnt[src];

    for(int i=0; i<adj[src].size(); i++)
    {
        int node= adj[src][i];

        if(vis[node]==0)
        {

            //printf("%d->%d\n",src,node);
            vis[node]=1;
            tot+= 1+ dfs(node,adj);
            //vis[node]=0;
        }

    }

    return cnt[src]=tot;
}


int main()
{
    int test;
    cin>>test;

    while(test--)
    {

        vector<int>adj1[101];
        vector<int>adj2[101];

        int n,m,u,v;
        scanf("%d %d",&n,&m);

        for(int i=0; i<m; i++)
        {
            scanf("%d %d",&u,&v);

            adj1[u].push_back(v);
            adj2[v].push_back(u);
        }

        int cntx=0;

        for(int i=1; i<=n; i++)
        {

            // printf("%d->%d\n",i, dfs(i,adj1));

            if( dfs(i,adj1)>=(n+1)/2) cntx++;
            ms(vis,0);
        }


        ms(cnt,0);
        // puts("");


        for(int i=1; i<=n; i++)
        {
            // printf("%d->%d\n",i, dfs(i,adj2));

            if( dfs(i,adj2) >=  (n+1)/2) cntx++;

            ms(vis,0);
        }

        printf("%d\n",cntx);
        ms(cnt,0);
    }
    return 0;
}
