#include<bits/stdc++.h>
using namespace std;
int vis[2000],cost[2000];
vector<int>adj[1009];
struct data
{
    int money,cnt;
};

data bfs(int source)
{
    queue<int>q;

    q.push(source);
    vis[source]=1;

    int total=cost[source];
    int cntx=1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();

        for(int i=0; i<adj[u].size(); i++)
        {
            int node=adj[u][i];

            if(vis[node]==0)
            {
              //  printf("%d->%d\n",u,node);
                vis[node]=1;
                total+=cost[node];
                cntx++;
                q.push(node);
            }
        }
    }

    data ret;
    ret.money=total;
    ret.cnt=cntx;

    //printf("total=%d\n",total);

    return ret;
}
void init()
{
    memset(vis,0,sizeof vis);
    memset(cost,0,sizeof cost);

}

int main()
{
    int t=0,test;
    cin>>test;
    while(t<test)
    {

        int n,m,i,x,y,total=0,cntx=0,flag=0;
        scanf("%d %d",&n,&m);



        for(i=1; i<=n; i++) scanf("%d",&cost[i]);

        for(i=0; i<m; i++)
        {
            scanf("%d %d",&x,&y);
            adj[x].push_back(y);
            adj[y].push_back(x);

        }

        int bef=-1;
        for(i=1; i<=n; i++)
        {

            if(vis[i]==0)
            {

                data ret=bfs(i);

               // printf("money=%d cnt=%d from=%d\n",ret.money,ret.cnt,i);
                //cout<<ret.money<<" <--> "<<ret.cnt<<endl;

                if(ret.money%ret.cnt!=0)
                {
                    flag=1;
                    break;

                }
                else
                {
                   int  num= ret.money/ret.cnt;
                    if(num!= bef && bef!=-1)
                    {
                        flag=1;
                        break;
                    }

                    bef=num;
                }

            }

        }


        printf("Case %d: ",++t);

        if(flag==1)
            printf("No\n");
        else
            printf("Yes\n");

        for(int i=0; i<n; i++) adj[i].clear();
        init();


    }
    return 0;
}
