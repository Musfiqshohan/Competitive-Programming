#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define i64 long long
#define pii pair<i64,i64>
#define INF 1000000000000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
#define rep(i,n) for(i64 i=0;i<n;i++)
using namespace std;

vector<int>adj[10009];
int main()
{
    int n,x;
    scanf("%d",&n);

    for(int i=1; i<n; i++)
    {
        scanf("%d",&x);
        adj[x].push_back(i+1);
    }

    int flag=0;
    for(int u=1; u<=n; u++)
    {
        int cnt=0;
        if(adj[u].size()==0) continue;

        for(int i=0; i<adj[u].size();i++)
        {
            int node=adj[u][i];
            if(adj[node].size()==0)
                cnt++;
        }
        if(cnt<3)
            flag=1;
    }

    if(flag==1) printf("No\n");
    else
    printf("Yes\n");
    return 0;
}
