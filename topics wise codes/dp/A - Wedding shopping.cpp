#include<bits/stdc++.h>
#define  ms(a,b) memset(a,b,sizeof a);
#define mod  1000000
#define ll long long
using namespace std;

vector<ll>cost[25];

ll M,C;
ll dp[25][220];
ll f(ll index, ll money)
{
    //printf("%d %d\n",index,money);
    if(money>=0 && index==C) return 0;
    if(money<=0) return INT_MIN;


    if(dp[index][money]!=-1) return dp[index][money];

    ll mx=INT_MIN,res=0,res2=0;
    for(ll i=0; i<cost[index].size(); i++)
    {
        res=cost[index][i] + f(index+1, money-cost[index][i]);
        if(res<=M)
            mx= max(mx,res);
    }


    return dp[index][money]= mx;

}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        ms(dp,-1);
        scanf("%lld %lld",&M,&C);

        ll i,k,val,j;
        for(i=0; i<C; i++)
        {
            scanf("%lld",&k);

            for(j=0; j<k; j++)
            {
                scanf("%lld",&val);
                cost[i].push_back(val);
            }
        }


        ll res= f(0,M);

        if(res<0) printf("no solution\n");
        else printf("%lld\n",res);

        for(i=0;i<C;i++) cost[i].clear();

    }
    return 0;
}
