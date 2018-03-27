#include<bits/stdc++.h>
using namespace std;
int n1,n2;
int a1[200],a2[200];
int dp[105][105];
int f(int i,int j)
{
    if(i==n1 || j==n2) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    int total=0,t1,t2;
    if(a1[i]==a2[j])
    {
        total= 1+ f(i+1,j+1);
    }
    else
    {
        t1= f(i+1,j);
        t2= f(i,j+1);

        total=max(t1,t2);
    }

    return dp[i][j]=total;

}
int main()
{
    int cnt=0;
    while(1){
    cnt++;
    memset(dp,-1,sizeof dp);
    int i;
    scanf("%d %d",&n1,&n2);

    if(n1==0 && n2==0) return 0;

    for(i=0; i<n1; i++)
        scanf("%d",&a1[i]);

    for(i=0; i<n2; i++)
        scanf("%d",&a2[i]);


    printf("Twin Towers #%d\n",cnt);
    printf("Number of Tiles : %d\n\n",f(0,0));

    }

    return 0;
}
