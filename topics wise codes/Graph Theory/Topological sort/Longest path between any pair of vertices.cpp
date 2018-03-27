///http://www.geeksforgeeks.org/longest-path-between-any-pair-of-vertices/
///not sure
#include<bits/stdc++.h>
#define ll long long
//#define mod 1001113
using namespace std;

vector<int>adj[100009], edge[100009];


int dfs(int u, int pr)
{



    int mx=0;
    for(int i=0;i<adj[u].size();i++)
    {
        int node= adj[u][i];

        if(node!=pr){
        int res= dfs(node,u)+ edge[u][i];
        mx= max(mx,res);
        }

    }


    return mx;

}


int main()
{
   // memset(dp,-1,sizeof dp);
    int n,u,v,w,m;
    scanf("%d %d",&n,&m);

    for(int i=0;i<m;i++)
    {
        scanf("%d %d %d",&u,&v,&w);
        adj[u].push_back(v);
        adj[v].push_back(u);
        edge[u].push_back(w);
        edge[v].push_back(w);
    }


    int mx=0;
    for(int i=1;i<=n;i++)
    {
       mx= max(mx,dfs(i,-1));

    }


    cout<<mx<<endl;




    return 0;
}
