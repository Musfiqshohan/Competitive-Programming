#include<bits/stdc++.h>
using namespace std;

int Set(int N, int pos){ return N=N|(1<<pos); }
bool check(int N, int pos) { return N&(1<<pos); }
int n;
int dp[18][1<<16+2];
int w[18][18];
int bitmask(int index, int mask)
{
    if(index==n) return 0;

    if(dp[index][mask]!=-1) return dp[index][mask];
    int mx=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(check(mask,i)==0)
        {
            int ret=w[i][index]+bitmask(index+1, Set(mask,i));
            mx= max(mx,ret);
        }
    }

    return dp[index][mask]=mx;
}

int main()
{
    int t=0,test;
    scanf("%d",&test);
    while(t<test){
    memset(dp,-1,sizeof dp);
    int i,j;
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            scanf("%d",&w[i][j]);
    }

    printf("Case %d: %d\n",++t, bitmask(0,0));

    }
}
