#include<bits/stdc++.h>
using namespace std;

#define ll long long
ll a[25], dp[25][10010];
ll f(ll i, ll total)
{
    //printf("%d %d\n",i,total);
    ll total1,total2;
    if(i>21)
    {
        if(total==0) return 1;
        else return 0;
    }
    if(total==0) return 1;
    if(total<0) return 0;

    if(dp[i][total]!=-1) return dp[i][total];

    total1= f(i,total-a[i]);
    total2= f(i+1, total);

    dp[i][total]=total1+total2;
    return dp[i][total];
}
int main()
{
    ll n,i;

    for(i=1; i<=21;i++)
        a[i]= i*i*i;



    memset(dp,-1,sizeof(dp));

    while(scanf("%lld",&n)==1){

    printf("%lld\n", f(1,n));
    }

    return 0;

}
