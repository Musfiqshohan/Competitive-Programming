#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include<bitset>
using namespace std;

vector<int>adj[1009];
int dp[1009];
int grundy(int src)
{
    if(adj[src].size()==0)
        return 0;

    if(dp[src]!=-1) return dp[src];

    //puts("Hi");

    bitset<1009>bitara;
    for(int i=0; i<adj[src].size(); i++)
    {
        int node= adj[src][i];
        int ret=grundy(node);
        bitara[ret]=true;
        //printf("%d -> %d g= %d\n",src,node, ret);
    }

    int mex=0;
    for(mex=0; mex<adj[src].size(); mex++)
    {
        if(bitara[mex]==false)
            break;
    }

    //printf("src= %d %d\n",src,mex);

    return dp[src]=mex;

}


int main()
{
    int n,X,xj,m;
    while(scanf("%d",&n)!=EOF) {

    memset(dp,-1,sizeof dp);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&X);

        for(int j=0; j<X; j++)
        {
            scanf("%d",&xj);
            adj[i].push_back(xj);
        }
    }






    while(scanf("%d",&m) && m!=0) {

    int xorr=0,xx;
    for(int i=0; i<m; i++)
    {
        scanf("%d",&xx);
        xorr^= grundy(xx);
    }

    if(xorr==0) printf("LOSE\n");
    else printf("WIN\n");

    }

    for(int i=0;i<n;i++)
        adj[i].clear();

    }


    return 0;
}
