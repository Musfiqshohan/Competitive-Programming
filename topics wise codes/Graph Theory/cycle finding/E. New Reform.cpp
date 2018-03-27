#include<bits/stdc++.h>
using namespace std;
int flag=0;
vector<int>adj[200009];
int vis[200009];
int dfs(int parent, int source)
{

    for(int i=0;i<adj[source].size();i++)
    {
        int node=adj[source][i];

        if(vis[node]==0)
        {
            vis[node]=1;
            //printf("%d->%d\n",source,node);
            if(dfs(source,node)==0)
                return 0;
        }
        else
        {
            if(node!=parent){
                printf("cycle found %d <->%d\n",source,node);
                flag=1;
            }
        }
    }

    return 1;
}


int main()
{
    int n,m,t=0,i,x,y;
    scanf("%d %d",&n,&m);

    for(i=0;i<m;i++)
    {
        scanf("%d %d",&x,&y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }



    for(i=1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            if(adj[i].size()!=0) //;
          //  else
          {
            vis[i]=1;
            vis[adj[i][0]]=1;

            printf("From %d\n",i);
            t+=dfs(i, adj[i][0]);
            printf("flag=%d\n",flag);
          }

        }

    }

    cout<<t<<endl;

    return 0;
}
