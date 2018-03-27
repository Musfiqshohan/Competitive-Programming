#include<bits/stdc++.h>
using namespace std;

vector<int>adj[100009];
int vis[100009], level[100009], exist[100009];

int bfs(int source,int flag)
{
    queue<int>q;
    q.push(source);
    vis[source]=flag;
    level[source]=0;

    int cnt1=1,cnt2=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();

        for(int i=0;i<adj[u].size();i++)
        {
            int node=adj[u][i];

            if(vis[node]==0)
            {
               // printf("%d -> %d\n",u,node);
                vis[node]=flag;
                level[node]=level[u]+1;

                if(level[node]%2==0) cnt1++;
                else cnt2++;

                q.push(node);
            }
        }
    }

    return max(cnt1,cnt2);

}

int main()
{
    int t=0,test;
    cin>>test;

    while(t<test){
    int n,i,x,y,mx=0;
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d %d",&x,&y);
        adj[x].push_back(y);
        adj[y].push_back(x);

        exist[x]=1;
        exist[y]=1;
        mx=max(mx,x);
        mx=max(mx,y);
    }

    int total=0;
    for(i=1;i<=mx;i++)
    {
        if(vis[i]==0 && exist[i]==1)
            {
              // printf("from -> ->%d\n",i);
               total+=bfs(i,i);
            }
    }


    printf("Case %d: %d\n",++t,total);
//    int t1=0,t2=0;
//    for(i=1;i<=mx;i++)
//    {
//       // printf("%d %d\n",level[i], i);
//        if(level[i]%2==0) t1++;
//        else t2++;
//    }
//
//    printf("Case %d: %d\n",++t,max(t1,t2));

    for(i=1;i<=mx;i++) adj[i].clear();
    memset(vis,0,sizeof vis);
    memset(level,0,sizeof level);
    memset(exist, 0 ,sizeof exist);

    }

    return 0;
}
