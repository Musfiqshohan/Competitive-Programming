#include<bits/stdc++.h>
using namespace std;
long long D,n;
long long a[300];
long long dp[305][20][25];
long long f(long long i, long long cnt, long long sum)
{   long long total=0;

    if(i==n+1) return 0;

    if(cnt==0)
    {
        if(sum%D==0) {  return 1;   }
        else return 0;
    }

    if(dp[i][cnt][sum]!=-1) return dp[i][cnt][sum];

    total= f(i+1, cnt-1, (sum+(a[i]%D+D))%D )+ f(i+1 , cnt , (sum%D) );

    dp[i][cnt][sum]=total;
    return total;
}
int main()
{
    long long t,test,q;
    scanf("%lld",&test);
    for(t=0;t<test;t++){
    long long M,i;
    scanf("%lld %lld",&n,&q);
    for(i=0;i<n;i++) scanf("%lld",&a[i]);

    printf("Case %lld:\n",t+1);
    for(i=0;i<q;i++){
    scanf("%lld %lld",&D,&M);
    memset(dp,-1,sizeof(dp));
    printf("%lld\n",f(0,M,0));
    }

    }
    return 0;
}
