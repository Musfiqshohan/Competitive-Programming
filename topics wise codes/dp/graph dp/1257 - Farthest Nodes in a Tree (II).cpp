#include<bits/stdc++.h>
#define pb push_back
using namespace std;




int main()
{

    int n;
    scanf("%d",&n);


    for(i=1;i<=n-1;i++)
    {
        scanf("%d %d %d",&u,&v,&w);

        adj[u].pb(v);
        adj[v].pb(u);

        cost[u][v]=cost[v][u]=w;
    }


    dfs(0);



    return 0;

}
