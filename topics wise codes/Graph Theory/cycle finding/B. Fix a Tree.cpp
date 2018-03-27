#include<bits/stdc++.h>
#define print(ara,n) for(long long i=0;i<n;i++)printf("%lld ",ara[i]); puts("");
#define ms(a,b) memset(a,b,sizeof a);
#define  ll long long
using namespace std;

void dfs(int src)
{


}


int main()
{
    int n;
    scanf("%d",&n);

    for(int i=1;i<=n;i++)
    {
        scanf("%d",&ara[i]);
        if(ara[i]==i)
        {cnt++;
            root=i;
        }
    }


    for(int i=1;i<=n;i++)
    {
        if(vis[i]==0)
            dfs(i);
    }

    return 0;
}
