#include<bits/stdc++.h>
#define ll long long
#define inf1 100000000000000
#define inf2 10000000000000
using namespace std;

ll n, vis[55],travel[55][55], cost[55][55],dir[1009], dp[55][1009],cnt=0;
ll f(ll src, ll time)
{
    if(time<=0) return inf1;
    if(src==n-1) return 0;

    if(dp[src][time]!=-1) return dp[src][time];
    ll mn=inf1;
    for(ll i=1;i<n;i++)
    {
        if(vis[i]==0)
        {

            vis[i]=1;
           // printf("%lld -> %lld\n",src,i);
            ll res=f(i,time-travel[src][i])+cost[src][i];

            if(res<mn)
            {
              //  printf("%lld ->-> %lld\n",src,i);
                mn=res;
                dir[src]=i;
            }

            vis[i]=0;
        }
    }

    return dp[src][time]=mn;
}

void printTime(ll src)
{

    if(dir[src]==-1)
    {
        printf("%lld\n",cnt);
        return;
    }
    printf("%d->",src);
    cnt+= travel[src][dir[src]];
    printTime(dir[src]);

}
int main()
{
    ll time,i,j;

    while(1){

    memset(dir,-1,sizeof dir);
    memset(dp,-1,sizeof dp);
    cnt=0;
    scanf("%lld %lld",&n,&time);
    if(n==0 && time==0) break;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            scanf("%lld",&travel[i][j]);
    }

     for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            scanf("%lld",&cost[i][j]);
    }

    vis[0]=1;
    ll res=f(0,time);

    if(res>=inf2) printf("-1\n");
    else{
    cout<<res<<"->";
    printTime(0);

    }


    memset(vis,0,sizeof vis);
    memset(travel,0,sizeof travel);
    memset(cost,0,sizeof cost);


    }
    return 0;
}
