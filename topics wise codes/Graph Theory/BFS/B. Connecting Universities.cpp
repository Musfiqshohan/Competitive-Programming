#include<bits/stdc++.h>
using namespace std;

void dfs(int src,int flag)
{
    vis[src]=1;

    for(int i=0; i<adj[src].size(); i++)
    {
        int node= adj[src][i];

        if(vis[node]==0)
        {

            level[node]=level[src]+1;

            if(flag==1)
                save[node]= max(save[node],level[node]);

            dfs(node,flag);
        }
    }
}
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);

    for(i=0;i<2*k;i++)
        scanf("%d",&towns[i]);

    for(i=0;i<n-1;i++)
    {
          scanf("%d %d",&x,&y);

            adj[x].push_back(y);
            adj[y].push_back(x);
    }

    dfs(1);


    return 0;
}
