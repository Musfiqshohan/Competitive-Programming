///Diameter of a tree
#include<bits/stdc++.h>
using namespace std;
vector<int>adj[100009];

int f[100009], g[100009],diameter;

void dfs(int src, int Pr)
{
    if(adj[src].size()==1)
        return;



    int mx1=-1,mx2=-1;
    for(int i=0;i<adj[src].size();i++)
    {
        int node= adj[src][i];
        if(node==Pr) continue;

        dfs(node,src);

        if(f[node]>mx1)
        {
            mx2=mx1;
            mx1=f[node];
        }
        else if(f[node]>mx2)
        {
            mx2=f[node];
        }
    }



    f[src]=1+ mx1;

    if(mx2!=-1)
        g[src]= 2+ mx1+ mx2;


    diameter= max(max(diameter, f[src]), g[src]);



}
int main()
{
    int n,u,v;
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        scanf("%d %d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }



    dfs(1,-1);

    cout<<diameter<<endl;


    return 0;
}
