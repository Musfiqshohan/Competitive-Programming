#include<bits/stdc++.h>
using namespace std;
vector<int>edge[100007];
queue<int>q;
int level[1000009], vis[100009], parent[100000];
void bfs(int source)
{
    int u,v,i;
    q.push(source);
    level[source]=0;


    while(!q.empty())
    {
        u=q.front();
        q.pop();

        for(i=0; i< edge[u].size(); i++)
        {
            v= edge[u][i];
            if(level[v]==-1)
            {
                parent[v]=u;
                level[v]= level[u]+1;
                q.push(v);
            }
        }

    }

}
int main()
{
    memset(level,-1,sizeof(level));
    int n,m,i,x,y;
    scanf("%d %d",&n,&m);

    for(i=0; i<m; i++)
    {
        cin>>x>>y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }

    bfs(1);

    int mx=0,mxi=-1;
    for(i=1;i<=n;i++)
    {
        if(level[i]>mx) { mx= level[i]; mxi=i;   }
    }

    int index=mxi;

    cout<<mxi<<endl;

    while(parent[index]!=0)
    {
        printf("%d ",parent[index]);
        index= parent[index];

    }






    return 0;
}
