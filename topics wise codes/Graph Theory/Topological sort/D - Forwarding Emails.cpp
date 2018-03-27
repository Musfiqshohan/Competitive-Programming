#include<bits/stdc++.h>
#define print(ara,n) for(long long i=0;i<n;i++)printf("%lld ",ara[i]); puts("");
#define ms(a,b) memset(a,b,sizeof a);
#define  ll long long
using namespace std;

vector<int>adj[50009];
stack<int>bucket;
int vis[50009];
void top(int src)
{
    //printf("ss=%d\n",src);
    for(int i=0;i<adj[src].size();i++)
    {
        int node= adj[src][i];
        if(vis[node]==0)
        {
            vis[node]=1;
            top(node);
        }
    }

    bucket.push(src);
}

int dfs(int src)
{
    int total=0;
    for(int i=0;i<adj[src].size();i++)
    {
        int node= adj[src][i];
        if(vis[node]==0)
        {
            vis[node]=1;
            total= total+  1+dfs(node);
        }
    }

    return total;
}

int main()
{
    freopen("12442 - Forwarding EmailsI.txt","r",stdin);
    //freopen("12442 - Forwarding EmailsO.txt","w",stdout);

    int t=0,test;
    cin>>test;

    while(t<test){
    int n,u,v,mx=INT_MIN,mni=INT_MAX;
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&u,&v);

        adj[u].push_back(v);
    }

    for(int j=n;j>=1;j--)
    {
        if(vis[j]==0)
        {
            vis[j]=1;
            int res=top(j);

            if(res>mx)
            {
                mni=j;
            }
        }
    }



    printf("Case %d: %d\n",++t,mni);


    ms(vis,0);
    for(int i=0;i<n;i++)
        adj[i].clear();

    }

    return 0;
}
