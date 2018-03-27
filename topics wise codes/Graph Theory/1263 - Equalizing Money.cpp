#include<bits/stdc++.h>
using namespace std;
vector<int>v[1009];
int vis[1009],cost[1009];

struct data
{
    int money;
    int cnt=0;
};

data bfs(int source)
{
    queue<int>q;
    q.push(source);
    vis[source]=1;

    int total=0,cnt=0;

    while(!q.empty())
    {
        int u= q.front();
        q.pop();

        //printf("head =%d \n",u);
        for(int i=0;i<= v[u].size(); i++)
        {
            int node= v[u][i];
                printf("FFFF %d\n",node);
            if(vis[node]==0)
            {
                vis[node]=1;
                cnt++;
                total+= cost[node];
                q.push(node);

            }
        }
    }

    data x;
    x.money=total;
    x.cnt=cnt;
    return x;
}
int main()
{
    int n,m,x,y,u,i;

    data ret;

    scanf("%d %d",&n,&m);

    for(i=0;i<n;i++) scanf("%d",&cost[i]);

    for(i=0;i<m;i++)
    {
        scanf("%d %d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);

    }



//    for(i=1;i<=n;i++)
//    {
//        if(vis[i]==0)
//        {
//
//            ret=bfs(i);
//            cout<<ret.money<<" output  "<<ret.cnt<<endl;
//
//        }
//    }

    return  0;
}
