#include<bits/stdc++.h>
#define ms(a,b) memset(a,b,sizeof a);
#define ll long long
using namespace std;
int cost[109][109], dp[109][109][209];

int n,m;
int f(int r1, int r2, int moves)
{
    //printf("%d %d %d\n",r1,r2,moves);

    if(r1>m || r2>m ) return 0;
    int c1= moves- r1 +2;
    int c2= moves -r2 +2;
    if(c1>n || c2>n) return 0;
    if(r1==r2 && c1==c2 &&(r1!=1 || c1!=1)) return 0;

    if(dp[r1][r2][moves]!=-1) return dp[r1][r2][moves];

    int t1,t2,t3,t4,mx= INT_MIN;


    t1= f(r1,r2,moves+1);       mx= max(mx,t1);
    t2= f(r1+1,r2, moves+1);    mx= max(mx,t2);
    t3= f(r1,r2+1, moves+1);    mx= max(mx,t3);
    t4= f(r1+1,r2+1, moves+1);  mx= max(mx,t4);


   int res=0;

    if(r1!=1 || c1!=1)
     res=  cost[r1][c1]+ cost[r2][c2] + mx;
    else res=mx;

    return dp[r1][r2][moves]=res;



}
int main()
{
    int t=0,test;
    cin>>test;

    while(t<test) {
    ms(dp,-1);
    scanf("%d %d",&m,&n);

    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
            scanf("%d",&cost[i][j]);
    }

     printf("Case %d: %d\n",++t,f(1,1,0)+cost[1][1] + cost[m][n]);

    }
    return 0;
}
