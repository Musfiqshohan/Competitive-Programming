#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<int,int>
#define inf 100000000000
using namespace std;


int vis[50009], dis[50009], edge[50009];

int dfs(int src)
{

    int node=edge[src],res=0;

    if(vis[node]==0)
    {
        vis[node]=1;

        res=1+dfs(node);
        vis[node]=0;
    }

    return dis[src]=res;


}
int main()
{
//    freopen("input12442.txt", "r", stdin);
//    freopen("output12442.txt", "w", stdout);
    int test,t=0;
    cin>>test;

    while(t<test){

    ms(dis,-1);
    int n,u,v,res,mx=0,mni=-1;
    scanf("%d",&n);

    for(int i=0; i<n; i++)
    {
        scanf("%d %d",&u,&v);
        edge[u]=v;
    }


    for(int i=1; i<=n; i++)
    {
        if(dis[i]==-1)
        {
            res= dfs(i);
            if(res>mx)
                mni=i;
        }
    }

    printf("Case %d: %d\n", ++t,mni);
    ms(dis,0);
    ms(edge,0);

    }

    return 0;
}
