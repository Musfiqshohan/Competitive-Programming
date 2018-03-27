#include<bits/stdc++.h>
#define ms(a,b) memset(a,b,sizeof a);
using namespace std;

int ara[10009], dp[10009][150];
int k,n;
int f(int index, int sum)
{
    if(index==n)
    {
        if(sum%k==0) return 1;
        else return 0;
    }

    if(dp[index][sum]!=-1) return dp[index][sum];

    int t1= f(index+1, (sum-ara[index])%k);
    int t2= f(index+1, (sum+ara[index])%k);

    return dp[index][sum]=t1|t2;
}


int main()
{
    int t;
    cin>>t;

    while(t--)
    {

        ms(dp,-1);


        scanf("%d %d",&n,&k);

        for(int  i=0; i<n; i++)
            scanf("%d",&ara[i]);

        int l=f(0,0);
        if(l==1)
            printf("Divisible\n");
        else printf("Not divisible\n");

    }
    return 0;
}
