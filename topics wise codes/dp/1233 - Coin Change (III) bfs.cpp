#include<bits/stdc++.h>
using namespace std;

int num[109],val[109], ara[100009],vis[100009];
 int n,m;
int bfs(int src)
{
    queue<int>q;
    q.push(0);
    int tot=0;

    while(!q.empty())
    {
        int u=q.front();
        q.pop();

        for(int i=0;i<n && num[i];i++)
        {
            int node=u+val[i];

                printf("%d ->%d\n",u,node);
            if(vis[node]==0)
            {
                vis[node]=1;
                tot++;
                q.push(node);
            }
        }

        for(int i=0;i<n && num[i];i++)
            num[i]--;
    }

    return tot;
}

int main()
{

    scanf("%d %d",&n,&m);

    for(int i=0;i<n;i++)
        scanf("%d",&val[i]);
    for(int i=0;i<n;i++)
        scanf("%d",&num[i]);

    int res=bfs(0);

    cout<<res<<endl;



}

