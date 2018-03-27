#include<bits/stdc++.h>
using namespace std;
int vis[200],earn[200];
vector<int>v[200];
struct data
{
    int value, index;
};
data dp[200];

data dfs(int node)
{

    if(dp[node].value!=-1) return dp[node];

    data mx;
    mx.value=mx.index=0;
    int flag=0;

    for(int i=0; i<v[node].size(); i++)
    {
        int next= v[node][i];

        if(vis[next]==0)
        {

            vis[next]=1;

            flag=1;

            if(dfs(next).value>=mx.value)
                mx=dfs(next);
            vis[next]=0;

        }
    }

    if(flag==0)
    {
        mx.index=node;
    }

    mx.value+=earn[node];

    return dp[node]=mx;

}
int main()
{
    int t=0,test;
    scanf("%d",&test);
    while(t<test)
    {

        memset(dp,-1,sizeof dp);
        memset(vis, 0, sizeof vis);
        int n,i,m,x,y;
        scanf("%d %d",&n,&m);


        for(i=0; i<n; i++) scanf("%d",&earn[i]);

        for(i=0; i<m; i++)
        {
            scanf("%d %d",&x,&y);

            v[x].push_back(y);
        }

        vis[0]=1;
        printf("Case %d: %d %d\n",++t,dfs(0).value,dfs(0).index);

        for(i=0;i<n;i++) v[i].clear();
    }

    return 0;
}

