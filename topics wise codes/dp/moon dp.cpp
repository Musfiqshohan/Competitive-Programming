#include<bits/stdc++.h>

long long dp[50][50];

long long ways(long long old, long long now,long long rest)
{
    if(rest==0)
    {
        if(now==2) return 0;
        return 1;
    }
    if(dp[now][rest]!=-1) return dp[now][rest];

    if(now==2)
    {
        if(old==1) return dp[now][rest]= ways(2,3,rest-1);
        if(old==3) return dp[now][rest]= ways(2,1,rest-1);
    }
    if(now==1) return dp[now][rest]= ways(1,2,rest-1)+ways(1,3,rest-1);

    if(now==3) return dp[now][rest]= ways(3,2,rest-1)+ways(3,1,rest-1);

}

int main()
{
    long long n;
    std::cin>>n;
    memset(dp,-1,sizeof(dp));

    long long ans ;
    ans = (n>1)? ways(1,2,n-2) + ways(1,3,n-2)+ways(3,1,n-2) + ways(3,2,n-2) : 2;

    std::cout<<ans<<std::endl;


    return 0;
}
