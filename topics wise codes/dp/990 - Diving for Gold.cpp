#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll d[50], gold[50];
ll n;
ll dp[50][2000], dir[50][2000];
ll f(ll i, ll t, ll w)
{
    ll total1=0,total2=0;

    if(i>=n+1 || t<=0) return 0;

    if(dp[i][t]!=-1) return dp[i][t];

    if(t-3*w*d[i]>=0)
        total1= gold[i] + f(i+1, t - 3*w*d[i] ,w);

    total2= f(i+1, t, w );


    if(total1>total2)
    {
       // printf("x\n");
        dir[i][t]=1;
     //   printf("%lld %lld\n",gold[i],t);

        return dp[i][t]=total1;
    }
    else
    {
        dir[i][t]=2;
        return dp[i][t]=total2;
    }


}

ll solve1(ll i,ll t, ll w)
{
    ll cnt=0;
    while(dir[i][t]!=-1)
    {

        if(dir[i][t]==1)
        {   cnt++;

            t=t- 3*w*d[i];
            i++;

        }
        else if( dir[i][t]==2)
        {
            i++;
        }

    }
    return cnt;
}
void solve2(ll i, ll t, ll w)
{
 while(dir[i][t]!=-1)
    {
        if(dir[i][t]==1)
        {
            printf("%lld %lld\n",d[i], gold[i]);
            t=t-3*w*d[i];
            i++;
        }
        else
        {
            i++;
        }

    }

}
int main()
{
    bool notfirst=false;
    ll t,i,w;
     while(cin>>t>>w)
    {

    if(notfirst)
            putchar('\n');
    notfirst=true;

    scanf("%lld",&n);


    memset(dp,-1,sizeof(dp));
    memset(dir,-1,sizeof(dir));
    memset(gold,0,sizeof(gold));
    memset(d,0,sizeof(d));


    for(i=1;i<=n;i++)
    {
        scanf("%lld %lld",&d[i], &gold[i]);
    }



    cout<<f(1,t,w)<<endl;
    cout<<solve1(1,t,w)<<endl;
    solve2(1,t,w);


    getchar();

    }

    return 0;

}
