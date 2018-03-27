#include<bits/stdc++.h>
#define  ms(a,b) memset(a,b,sizeof a);
#define mod  1000000
using namespace std;

int dp[109][109];
int f(int n, int k)
{

    if(n==0 && k==0) return 1;
    if(k==0) return 0;
    if(n<0) return 0;


    if(dp[n][k]!=-1) return dp[n][k];
    int res=0;

    for(int i=0; i<=n; i++)
    {
        res= (res + f(n-i,k-1))%mod;
    }

    return dp[n][k]=res;
}

int main()
{
    int n,k;
    while(scanf("%d %d",&n,&k)==2 && (n!=0 || k!=0))
    {
        ms(dp,-1);

        printf("%d\n",f(n,k));
    }
}
