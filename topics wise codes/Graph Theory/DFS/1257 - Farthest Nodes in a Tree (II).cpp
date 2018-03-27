#include<bits/stdc++.h>
using namespace std;
vector<int>adj[30009];
vector<int>cost[30009];
int vis[30009],level[30009],save[30009];
int temp,mx=0;
void dfs(int src,int flag)
{
    vis[src]=1;

    for(int i=0; i<adj[src].size(); i++)
    {
        int node= adj[src][i];

        if(vis[node]==0)
        {

            level[node]=level[src]+cost[src][i];

            if(flag==1)
                save[node]= max(save[node],level[node]);

            if(level[node]>mx)
            {
                mx=level[node];
                temp=node;
            }
            dfs(node,flag);
        }
    }
}
void init()
{
    memset(vis,0,sizeof vis);
    memset(level,0,sizeof level);
    mx=0;

}
int main()
{
    int t=0,test;
    cin>>test;

    while(t++<test)
    {
        int n,i,x,y,z;
        scanf("%d",&n);

        for(i=0; i<n-1; i++)
        {
            scanf("%d %d %d",&x,&y,&z);

            adj[x].push_back(y);
            adj[y].push_back(x);

            cost[x].push_back(z);
            cost[y].push_back(z);
        }

        dfs(0,0);
        // printf("%d\n",temp);

        init();

        dfs(temp,0);
        for(i=0; i<n; i++) save[i]=level[i];
//    for(i=0;i<n;i++)
//        printf("%d->%d\n",i,level[i]);

        init();

        dfs(temp,1);
        printf("Case %d:\n",t);
        for(i=0; i<n; i++)
            printf("%d\n",save[i]);

        init();

        for(i=0; i<n; i++)
        {
            adj[i].clear();
            cost[i].clear();
        }


    }

    return 0;
}
