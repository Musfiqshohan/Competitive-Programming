#include<bits/stdc++.h>
#define print(ara,n) for(long long i=0;i<n;i++)printf("%lld ",ara[i]); puts("");
#define ms(a,b) memset(a,b,sizeof a);
#define  ll long long
using namespace std;

int trav[50009],To[50009], vis[50009];
int dfs(int u)
{
    int v=To[u];

    int r=0;
    if(vis[v]==0)
    {
        vis[v]=1;
        int r=dfs(v)+1;
        vis[v]=0;
    }

    trav[u]=r;
    return r;

}

int main()
{
    int n,u,v;
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&u,&v);
        To[u]=v;
    }

    ms(trav,-1);
    int mx=-1, mni=-1;
    for(int i=1;i<=n;i++)
    {
        if(trav[i]==-1)
        {
            trav[i]=dfs(i);

            printf("%d %d\n",i, trav[i]);
            if(trav[i]>mx)
            {
                mx=trav[i];
                mni=i;
            }
        }
    }


    printf("%d\n",mni);

    return 0;
}
