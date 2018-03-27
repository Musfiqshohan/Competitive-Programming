#include<bits/stdc++.h>
using namespace std;
vector<int>adj[1009];
int dp[1009][3],parent[1009];
int f(int src, int taken)
{
    if(adj[src].size()==0) return 1;

    int total=0,i;
    if(dp[src][taken]!=-1) return dp[src][taken];
    for(i=0; i<adj[src].size(); i++)
    {
        int node=adj[src][i];
        if(node != parent[src])
        {
            parent[node]=src;
            if(taken==0)
            {
                total+= f(node,1);
            }
            else
            {
                total+= min(f(node,0), f(node,1));
            }

        }

    }

    return dp[src][taken]=total+taken;

}

void init(int n)
{
    for(int i=1; i<=n; i++)
        adj[i].clear();
    memset(parent,0,sizeof parent);
}
int main()
{
    int n;
    while(1)
    {
        memset(dp,-1,sizeof dp);
        int i,j,x,m;
        scanf("%d",&n);
        if(n==0) break;

        for(i=1; i<=n; i++)
        {
            scanf("%d",&m);
            for(j=0; j<m; j++)
            {
                scanf("%d",&x);
                adj[i].push_back(x);
            }
        }

        printf("%d\n",min(f(1,0),f(1,1)));
        init(n);

    }
}
