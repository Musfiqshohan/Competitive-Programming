#include<bits/stdc++.h>
using namespace std;

int frut1[1001],frut2[1001],jumpToright[1001],jumpToleft[1001],dp[1001][3];
int n;
int f(int pos, int turn)
{
    if(pos==n)
        return 0;


    if(dp[pos][turn]!=-1) return dp[pos][turn];

    int t1=0,t2=0;
    if(turn ==1)
    {
         t1= frut1[pos] + f(pos+1,1);
         t2= frut1[pos] + jumpToright[pos+1] + f(pos+1,2);
    }
    else
    {
        t1= frut2[pos]+ f(pos+1,2);
        t2= frut2[pos]+ jumpToleft[pos+1]+ f(pos+1,1);
    }


    return dp[pos][turn]=min(t1,t2);



}


int main()
{
    int tt=0,test;
    cin>>test;
    while(tt<test) {

    memset(dp,-1,sizeof dp);

    scanf("%d",&n);

    for(int i=0; i<n; i++)
        scanf("%d",&frut1[i]);

    for(int i=0; i<n; i++)
        scanf("%d",&frut2[i]);

    for(int i=1; i<=n-1; i++)
        scanf("%d",&jumpToright[i]);

    for(int i=1; i<=n-1; i++)
        scanf("%d",&jumpToleft[i]);

    int t1=f(0,1);
    int t2=f(0,2);

    printf("Case %d: %d\n",++tt,min(t1,t2));

    }

}
