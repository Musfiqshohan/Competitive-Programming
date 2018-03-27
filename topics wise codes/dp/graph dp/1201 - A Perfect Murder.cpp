#include<bits/stdc++.h>
using namespace std;

vector<int>v[1009];
int dp[1009][2],parent[1009],vis[1009];

int f(int u, int isGuard)
{
    if(v[u].size()==0) return 0;

    if(dp[u][isGuard]!=-1) return dp[u][isGuard];
    int total=0;
    for(int i=0;i<v[u].size();i++)
    {
        int node= v[u][i];
        if(parent[u]!=node)
        {
           // printf("%d ->%d\n",u,node);
           vis[node]=1;
            parent[node]=u;
            if(isGuard==0)
                total+= f(node,1);
            else
            {
                total+= min(f(node,1), f(node,0));
            }
        }

    }

    return dp[u][isGuard]=total+isGuard;
}
int main()
{
    int t=0,test;
    cin>>test;

    while(t<test){
    memset(dp,-1,sizeof dp);
    int n,i,x,y,m;
    scanf("%d %d",&n,&m);

    for(i=0;i<m;i++)
    {
        scanf("%d %d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }

    int total=0;

    for(i=1;i<=n;i++){
        if(vis[i]==0)
                total+=min(f(i,0), f(i,1));
    }

    printf("Case %d: %d\n",++t,n-total);
    memset(parent,0,sizeof parent);
    memset(vis,0,sizeof vis);

    for(i=1;i<=n;i++) v[i].clear();

    }
    return 0;
}
