#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>v;
int main()
{
    int n,m,i;
    scanf("%d %d",&n,&m);

    for(i=0;i<m;i++)
    {
        scanf("%d %d",&x,&y);
        adj[x].push_back(y);

        indegree[y]++;
        //adj[y].push_back(x);
    }





    return 0;
}
