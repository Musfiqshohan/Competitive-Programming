#include<bits/stdc++.h>
using namespace std;

vector<int>edge[100009];
int vis[100009], a[100009];
int n,m;

int dfs(int node, int k)
{
    if(k<0) return 0;
    int flag=0,total=0,i;

   // printf("%d %d\n",node,k);

    for(i=0; i< edge[node].size() ; i++)
    {
        if(vis[edge[node][i]]==0)
        {
            flag=1;
            vis[edge[node][i]]=1;

            if(a[edge[node][i]]==1)
                total+= dfs(edge[node][i], k-1);
            else
                total+= dfs(edge[node][i], m);
        }

    }
    if(flag==0 )
    {
      //  printf("xxx%d %d\n",node,k);
            return 1;
    }

    return total;
}
int main()
{
    int i,x,y;
    cin>>n>>m;

    for(i=1; i<=n; i++) scanf("%d",&a[i]);

    for(i=1; i<=n-1; i++)
    {
        cin>>x>>y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }

    vis[1]=1;
    if(a[1]==1) cout<<dfs(1,m-1)<<endl;
    else
        cout<<dfs(1,m)<<endl;


    return 0;

}
