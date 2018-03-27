#include<bits/stdc++.h>
using namespace std;

vector<int>adj[100999];
int vis[100999];
stack<int>stk;
map<string, int> mp;
int flag=0;
void dfs(int src )
{



    for(int i=0; i<adj[src].size(); i++)
    {
        int node= adj[src][i];

        if(vis[node]==0)
        {

            vis[node]=1;
            dfs(node);
        }
        else if(vis[node]==1)
            flag=1;
    }

    vis[src]=2;
    stk.push(src);

}
int main()
{


    int t=0,test;
    cin>>test;

    while(t++<test)
    {

        int n,m,cnt,src,dis,x,y;

        scanf("%d %d",&n,&m);


        for(int i=0; i<m; i++)
        {
            scanf("%d %d",&x,&y);


            adj[x].push_back(y);
        }



        for(int i=1; i<=n; i++)
        {
            if(vis[i]==0)
            {
                vis[i]=1;
                dfs(i);

            }
        }




        stack<int>stk2;

        stk2=stk;

        memset(vis,0,sizeof vis);


        flag=0;
        int com=0;
        while(!stk2.empty())
        {
            if(vis[stk2.top()]==0)
            {
                com++;
                vis[stk2.top()]=1;

                dfs(stk2.top());
            }
            stk2.pop();
        }


        printf("Case %d: ",t);

        printf("%d\n",com);

        memset(vis,0,sizeof vis);
        while(!stk.empty()) stk.pop();

        for(int i=1; i<=n; i++) adj[i].clear();
        mp.clear();

    }

    return 0;
}
