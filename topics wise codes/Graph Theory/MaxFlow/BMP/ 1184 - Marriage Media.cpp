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

int matchR[55],Graph[55][55];
bool vis[55];
struct person
{
    int h,a,d;
} mp[55], fp[55];


bool bpm(int u, int m)  // for each node,  match with m elements in 2nd set
{
    for(int v=1;v<=m;v++)
    {
        if(Graph[u][v]==1 && vis[v]==false)
        {
            vis[v]=true;

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

    int tt=0,test;
    cin>>test;

    while(tt<test)
    {
        int n,m;

        scanf("%d %d",&n,&m);


        for(int i=1; i<=n; i++)
        {
            scanf("%d %d %d",&mp[i].h,&mp[i].a, &mp[i].d);
        }

        for(int i=1; i<=m; i++)
        {
            scanf("%d %d %d",&fp[i].h,&fp[i].a, &fp[i].d);

        }



        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(abs(fp[j].h-mp[i].h)<=12 && abs(fp[j].a-mp[i].a)<=5  && fp[j].d==mp[i].d)
                    Graph[i][j]=1;
            }

        }

        int res= maxBPM(n,m);

        printf("Case %d: %d\n",++tt,res);

        memset(Graph,0,sizeof Graph);
        memset(mp,0,sizeof mp);
        memset(fp,0,sizeof fp);


    }

    return 0;

}
