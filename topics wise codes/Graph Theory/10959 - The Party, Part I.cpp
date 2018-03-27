#include<bits/stdc++.h>
using namespace std;
vector<int>v[1009];
int vis[1009], level[1009];

void bfs(int source)
{
    queue<int>q;

    q.push(source);
    vis[source]=1;
    level[source]=0;

    while(!q.empty())
    {
        int u=q.front();
        q.pop();

        for(int i=0;i<v[u].size();i++)
        {
            int node=v[u][i];
            if(vis[node]==-1)
            {
                vis[node]=1;
               // printf("from %d  to %d\n",u,node);
                level[node]= level[u]+1;
                q.push(node);
            }
        }
    }


}
int main()
{
    int t;

    cin>>t;
    while(t--){

    memset(vis,-1,sizeof vis);
    memset(level,0,sizeof level);


    int n,d,i,x,y;

    scanf("%d %d",&n,&d);

    for(i=0;i<d;i++)
    {
        scanf("%d %d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }


    bfs(0);

    for(i=1;i<n;i++) printf("%d\n",level[i]);

    for(i=0;i<n;i++) v[i].clear();


    if(t!=0) puts("");


    }

    return 0;
}
