#include<bits/stdc++.h>
#define ll long long
#define inf1 100000000000000
#define inf2 10000000000000
using namespace std;

ll n, vis[55],travel[55][55], cost[55][55];
struct data
{
    ll toll,time;
};


data dp[55][1009];
ll cnt=0;
data f(ll src, ll time)
{
    if(src==n-1 && time>=0) return {0,0};
    if(time<=0) return {inf1,inf1};

    if(dp[src][time].toll!=-1 && dp[src][time].time!=-1) return dp[src][time];
    ll mn1=inf1, mn2=inf1;
    for(ll i=0;i<n;i++)
    {
        if(i==src) continue;        // will not go to itself
        if(vis[i]==0)   // to not again visit the already visited nodes
        {

           // printf("%lld->%lld\n",src,i);
            vis[i]=1;

            ll res1=f(i,time-travel[src][i]).toll+cost[src][i];     //  toll for possible soln
            ll res2=f(i,time-travel[src][i]).time + travel[src][i]; //  time for possible soln

            if(res1<mn1)    //  I need minimum toll
            {
                mn1=res1;
                mn2=res2;

            }
            else if(res1==mn1)      // if two tolls are same minimum time
            {
                if(res2<mn2)
                {
                    mn1=res1;
                    mn2=res2;
                }
            }

            vis[i]=0;
        }
    }

    return dp[src][time]={mn1,mn2};
}

int main()
{
    ll time,i,j;

    while(1){

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
    data res=f(0,time);

    //printf("Ans: ");
    if(res.toll>=inf2) printf("-1\n");
    else{
    cout<<res.toll<<" "<<res.time<<endl;
    }

    memset(travel,0,sizeof travel);
    memset(vis,0,sizeof vis);
    memset(cost,0,sizeof cost);


    }
    return 0;
}

