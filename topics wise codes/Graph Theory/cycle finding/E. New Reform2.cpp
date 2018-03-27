#include<bits/stdc++.h>
using namespace std;
int flag=0;
vector<int>adj[200009];
int vis[200009],parent[200009];
void dfs(int source)
{

    for(int i=0; i<adj[source].size(); i++)
    {
        int node=adj[source][i];

        if(vis[node]==0)
        {
            vis[node]=1;
            parent[node]=source;
            // printf("%d->%d\n",source,node);
            dfs(node);

        }
        else
        {
            if(node!=parent[source])
            {
                // printf("cycle found %d <->%d\n",source,node);
                flag=1;
            }
        }
    }


}
int main()
{
    int n,m,t=0,i,x,y,total=0;
    scanf("%d %d",&n,&m);

    for(i=0; i<m; i++)
    {
        scanf("%d %d",&x,&y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }


    for(i=1; i<=n; i++)
    {

        if(vis[i]==0)
        {

            parent[i]=i;
            vis[i]=1;
            flag=0;
            dfs(i);
            if(flag==0) total++;
        }

    }

    printf("%d\n",total);

    return 0;
}
