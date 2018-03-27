#include<bits/stdc++.h>
using namespace std;
 int a1[22],b1[22];
int dp[22][22];
int l;
int printLcs(int i, int j)
{
    //printf("%d %d\n",i,j);
    if(i==l || j==l) return 0;

    if(dp[i][j]!=-1) return dp[i][j];
    int total=0,t1,t2;
    if(a1[i]==b1[j])
    {

        total=1+printLcs(i+1,j+1);
    }
    else
    {
        t1= printLcs(i+1,j);
        t2=printLcs(i,j+1);

        total= max(t1,t2);
    }
    return dp[i][j]=total;
}

int main()
{
    memset(dp,-1,sizeof dp);

    int n,i;
    scanf("%d",&n);
    l=n;

    for(i=0;i<n;i++)
        scanf("%d",&a1[i]);

    for(i=0;i<n;i++)
        scanf("%d",&b1[i]);


    printf("%d\n",printLcs(0,0));


    return 0;
}
