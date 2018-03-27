#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int>edge[150109];
int vis[150109];
ll cnt=0;
pair<int ,int>p[150109];

void dfs(int node)
{

    if(vis[node]==1) return;
    vis[node]=1;
    for(int i=0;i<edge[node].size();i++)
    {
        if(vis[edge[node][i]]==0){
      //  printf("%d %d\n",node, edge[node][i]);
        cnt++;
        dfs(edge[node][i]);
        }
    }
}

int main()
{
    int n,m,i,x,y;
    ll total=0;
    scanf("%d %d",&n,&m);

    for(i=0;i<m;i++){
        cin>>x>>y;

        p[i].first=x;
        p[i].second=y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }


    for(i=1;i<=n;i++)
    {
        if(vis[i]==0){

            dfs(i);
            total+= ((cnt+1)*(cnt))/2;
            cnt=0;

        }

    }

    if(total==m) printf("YES\n");
    else printf("NO\n");

    return 0;
}
