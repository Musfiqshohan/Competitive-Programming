#include<bits/stdc++.h>
using namespace std;
vector<int>adj[100999];
int vis[100999];
 stack<int>stk;
void dfs(int src )
{

    vis[src]=1;

        for(int i=0;i<adj[src].size();i++)
        {
            int node= adj[src][i];

            if(vis[node]==0)
            {
                dfs(node);
            }

        }

    stk.push(src);

}
int main()
{
 //   freopen("11504 - Dominos_input.txt","r",stdin);
   // freopen("11504 - Dominos_output.txt","w",stdout);

    int t=0,test;
    cin>>test;

    while(t++<test){

    int n,m,cnt,i,src,dis;

    scanf("%d %d",&n,&m);

    cnt=0;
    for(i=0;i<m;i++)
    {
        scanf("%d %d",&src,&dis);

        adj[src].push_back(dis);
    }


    for(i=1;i<=n;i++){
        if(vis[i]==0)
        dfs(i);
    }

    stack<int>stk2;

    stk2=stk;

    memset(vis,0,sizeof vis);

    while(!stk2.empty())
    {
        if(vis[stk2.top()]==0)
            {
                cnt++;
                dfs(stk2.top());
            }
        stk2.pop();
    }

    printf("%d\n",cnt);

     memset(vis,0,sizeof vis);
     while(!stk.empty()) stk.pop();

     for(i=1;i<=n;i++) adj[i].clear();

    }

    return 0;
}
