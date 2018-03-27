#include<bits/stdc++.h>
using namespace std;
vector<int>adj[200];
int dir[200];

struct data{
    int length,index;
};
data dp[200];

data f(int src)
{

    if(adj[src].size()==0)
    {
        return {0,src};
    }

    if(dp[src].length!=-1 && dp[src].index!=-1) return dp[src];

    data mx={0,INT_MAX};
    for(int i=0; i<adj[src].size(); i++)
    {
        int node=adj[src][i];
        data temp= f(node);

        if(temp.length>mx.length)
        {
            mx=temp;
        }
        else if(temp.length==mx.length)
        {
            if(temp.index<mx.index)
                mx=temp;
        }


    }


    return dp[src]={mx.length+1, mx.index};
}



int main()
{
    int test=1;
    int flag=0;
    while(1)
    {

        int n,src,i,x,y;
        memset(dir,-1,sizeof dir);
        memset(dp,-1,sizeof dp);

        scanf("%d",&n);
        if(n==0) break;
        scanf("%d",&src);


        while(1)
        {
            scanf("%d %d",&x,&y);
            if(x==0 &&  y==0 ) break;
            adj[x].push_back(y);
        }

        data mx=f(src);
       // printf("length=%d last=%d\n",mx.length,mx.index);

       printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n",test++,src,mx.length,mx.index);

        for(i=1;i<=n;i++) adj[i].clear();

    }

    return 0;
}
