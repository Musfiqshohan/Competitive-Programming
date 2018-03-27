#include<bits/stdc++.h>
using namespace std;
int n;
int dp[1<<17+2];
int w[20][20];

bool check(int N,int pos){ return N&(1<<pos); }
int Set(int N, int pos) { return N=N|(1<<pos); }
int f(int mask)
{
    if(mask==(1<<n)-1) return 0;
    if(dp[mask]!=-1) return dp[mask];
    int mn=INT_MAX,i,j;
    for(i=0;i<n;i++)
    {
        if(check(mask,i)==0)
        {
            int price=w[i][i];
            for(j=0;j<n;j++)
            {
                if(check(mask,j)!=0)
                {
                    price+=w[i][j];
                }
            }

            mn= min(mn,price+f(Set(mask,i)));
        }
    }

    return dp[mask]=mn;

}
int main()
{
    int t=0,test;
    scanf("%d",&test);
    while(t<test){
    memset(dp,-1,sizeof dp);
    scanf("%d",&n);

    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            scanf("%d",&w[i][j]);
    }

    printf("Case %d: %d\n",++t,f(0));

    }

    return 0;
}

