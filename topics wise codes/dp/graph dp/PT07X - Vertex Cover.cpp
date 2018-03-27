#include<bits/stdc++.h>
using namespace std;
int dp[100000][3], parent[100000];
vector<int>adj[100000];
int f(int src,int isGuard)
{
    if(adj[src].size()==0) return 0;
    if(dp[src][isGuard]!=-1) return dp[src][isGuard];
    int sum=0;
    for(int i=0;i<adj[src].size();i++)
    {
        int node= adj[src][i];

        if(node!=parent[src])
        {
            printf("%d->%d\n",src,node);
            parent[node]=src;

            if(isGuard==0)
            sum+= f(node,1);
            else
            sum+= min(f(node,0),f(node,1));
        }
    }
    return dp[src][isGuard]=sum+isGuard;
}

int main()
{
    memset(dp,-1,sizeof dp);
    int n,x,y;
    scanf("%d",&n);

    for(int i=1;i<n;i++)
    {
        scanf("%d %d",&x,&y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    printf("%d\n", min(f(1,0), f(1,1)));

    return 0;
}
