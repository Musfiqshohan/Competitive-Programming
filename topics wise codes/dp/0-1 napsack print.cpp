#include<bits/stdc++.h>
using namespace std;
int n,cap;
int cost[100],weight[100], dp[100][100],dir[100][100];
int f(int i, int w)
{

    int total1=0,total2=0;

    if(dp[i][w]!=-1) return dp[i][w];
    if(i==n+1) return 0;

    if(w+weight[i]<=cap)
    total1= cost[i]+ f(i+1, w+ weight[i]);
    total2= f(i+1,w);

    if(total1>total2)
    {
        dir[i][w]=1;
        return dp[i][w]= total1;
    }
    if(total2>total1)
    {
        dir[i][w]=2;
        return dp[i][w]=total2;
    }

}
int main()
{
    memset(dir,-1,sizeof(dir));
    memset(dp,-1,sizeof(dp));

    int i;
    scanf("%d %d",&n,&cap);


    for(i=1;i<=n;i++)
        scanf("%d %d",&weight[i],&cost[i]);

    cout<<f(1,0)<<endl;

    int w=0;
    i=1;
    while(dir[i][w]!=-1)
    {
        if(dir[i][w]==1)
        {
            w=w+weight[i];
            printf("%d %d %d\n",i,w,cost[i]);
            i=i+1;
        }
        else
            i++;

    }
    return 0;
}
/*
5 10
1 120
7 400
4 280
3 150
4 200
*/
