#include<bits/stdc++.h>
#define ms(a,b) memset(a,b,sizeof a);
using namespace std;

int ara[109],sum1[109],sum2[109],dp[109][109][3];
int f(int i, int j, int turn)
{

    if(i>j) return 0;

    if(dp[i][j][turn]!=-1) return dp[i][j][turn];

    int res=0;

    if(turn==1)
    {
        res=0;
        int mx=INT_MIN;
        for(int k=i; k<=j; k++)
        {
            //printf("-> ->%d %d,%d = %d\n",i,k,j,sum1[k]-sum1[i-1]);
            res= sum1[k]-sum1[i-1] + f(k+1,j,2);

            mx= max(res,mx);
        }

        for(int k=j; k>=i; k--)
        {
            res= (sum2[k]-sum2[j+1])  + f(i,k-1,2);
            mx= max(res,mx);
        }


        return dp[i][j][turn]=mx;
    }
    else
    {
        res=0;
        int mn= INT_MAX;

        for(int k=i; k<=j; k++)
        {

            res= -(sum1[k]-sum1[i-1]) + f(k+1,j,1);
            mn= min(res,mn);
        }

        for(int k=j; k>=i; k--)
        {
            res= -(sum2[k]-sum2[j+1])  + f(i,k-1,1);
            mn= min(mn,res);

        }
        return dp[i][j][turn]=mn;
    }


}
int main()
{
    int t=0,test;

    cin>>test;

    while(t<test)
    {

        ms(dp,-1);
        int n;
        scanf("%d",&n);

        for(int i=1; i<=n; i++)
            scanf("%d",&ara[i]);


        for(int i=1; i<=n; i++) sum1[i]=sum1[i-1]+ara[i];


        for(int i=n; i>=1; i--) sum2[i]=sum2[i+1]+ara[i];

//    for(int i=1;i<=n;i++) printf("%d ",sum1[i]);
//    for(int i=1;i<=n;i++) printf("%d ",sum2[i]);


        printf("Case %d: %d\n",++t, f(1,n,1));


    }
    return 0;

}


