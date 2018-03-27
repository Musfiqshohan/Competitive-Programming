#include<bits/stdc++.h>
using namespace std;
vector<int>adj[7000];
int parent[7000],rating[7000];

int f(int src, int istaken)
{


    int res=0,res1,res2;
    for(int i=0; i<adj[src].size(); i++)
    {
        int node= adj[src][i];

        if(node!=parent[src])
        {

            parent[node]=src;

            if(istaken==0)
            {
                //printf("%d->%d\n",src, node);
                res1= rating [node] + f(node,1);
                res2= f(node,0);

                res+= max(res1,res2);
            }
            else
            {

                res+= f(node,0);

            }

        }

    }

    return res;

}
int main()
{
    int n,i,u,v;
    while(scanf("%d",&n)==1){

    for(i=1; i<=n; i++) scanf("%d",&rating[i]);

   while(1)
    {
        scanf("%d %d",&u,&v);
        if(u==0 && v==0) break;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    printf("%d\n",max(f(1,0), rating[1]+f(1,1)));

    memset(parent,0,sizeof parent);

    for(i=1;i<=n;i++) adj[i].clear();

    }

    return 0;
}
