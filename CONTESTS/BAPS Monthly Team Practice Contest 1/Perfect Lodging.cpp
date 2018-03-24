#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<int,int>
#define inf 100000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int matchR[205],Graph[205][205];
bool vis[205];



bool bpm(int u, int m)  // for each node,  match with m elements in 2nd set
{
    for(int v=1;v<=m;v++)
    {
        if(Graph[u][v]==1 && vis[v]==false)
        {
            vis[v]=true;
            vis[u]=true;

            if(matchR[v]<0 || bpm(matchR[v],m))
            {
                matchR[v]=u;
                return true;
            }

        }
    }

    return false;
}


int maxBPM(int n, int m)  // n= number in 1st set,  m is # in another set
{
    memset(matchR, -1, sizeof matchR);

    int result=0;
    for(int u=1;u<=n;u++)
    {
        memset(vis,0,sizeof vis);

        if(bpm(u,m))
            result++;
    }

    return result;
}

int main()
{

    int n,v;
    scanf("%d",&n);

    for(int u=1;u<=n;u++)
    {
        int m;
        scanf("%d",&m);
        for(int j=0;j<m;j++)
        {
            scanf("%d",&v);
            Graph[u][v]=1;
        }

    }


    int res= maxBPM(n,n);
    cout<<res<<endl;

    memset(Graph,0,sizeof Graph);




    return 0;

}
