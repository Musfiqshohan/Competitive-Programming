#include<bits/stdc++.h>
#define ll long long
//#define mod 1001113
using namespace std;

vector<int>adj[1000];


void dfs(int u)
{
    for(int i=0;i<adj[u].size();i++)
    {
        int node= adj[u][i];

        indegree[node]--;
        vis[node]=1;
        dfs(node);
        indegree[node]++;
        vis[node]=0;
    }
}


int main()
{
    int n,m;
    scanf("%d %d",&n,&m);

    for(int i=0;i<m;i++)
    {
        scanf("%d %d",&u,&v);

        adj[u].push_back(v);
        indegree[v]++;
    }


    for(int i=0;i<n;i++)
    {
        if(indegree[i]==0)
            dfs(i);

    }


}
