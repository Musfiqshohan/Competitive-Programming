#include<bits/stdc++.h>
using namespace std;
vector<int>v[209];
int level[209], vis[209];

int ver,edge,flag;

int bfs(int source, int ini, int state)
{
    int cnt=0;

    queue<int>q;

    q.push(source);
    level[source]=0;
    vis[source]=1;

    while(!q.empty())
    {
        int u=q.front();
        q.pop();

        for(int i=0; i<v[u].size(); i++)
        {
            int node= v[u][i];

            if(vis[node]==0)
            {
                vis[node]=state;
                level[node]= level[u]+1;
                q.push(node);
            }
            else
            {

                if(level[u]%2 == level[node]%2)
                {
                   flag=1;
                }

            }
        }

        if(level[u]%2==0 && ini==1)
        {
            cnt++;
        }

        else if(level[u]%2==1 && ini==0)
        {
            cnt++;
        }
    }

    return cnt;

}

void init(int state)
{
    for(int i=0;i<ver;i++)
    {
        if(vis[i]==state)
        {
            vis[i]=0;
            level[i]=0;
        }
    }

}


int main()
{

   int t=0,test;
   cin>>test;

   while(t++<test){


    int x,y,i,total=0;

    scanf("%d %d",&ver,&edge);

    for(i=0; i<edge; i++)
    {
        scanf("%d %d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }


    flag=0;
    for(i=0; i<ver; i++)
    {
        if(vis[i]==0)
        {

            int t1=bfs(i,1,i+1);

            init(i+1);
            int t2=bfs(i,0,i+1);

            if(t1==0) total+=t2;
            else if(t2==0) total+=t1;
            else
            total+= min(t1,t2);

        }
    }


    if(flag==1) printf("-1\n");
    else
   printf("%d\n",total);

   for(i=0;i<ver;i++) v[i].clear();
   memset(vis,0,sizeof (vis));
   memset(level,0,sizeof (level));


   }
    return 0;
}



