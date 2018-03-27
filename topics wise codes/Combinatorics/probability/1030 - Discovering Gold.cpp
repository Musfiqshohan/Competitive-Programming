#include<bits/stdc++.h>
using namespace std;
double a[200],n,dp[200];
int vis[200];
double f(int i)
{
   // printf("i= %d\n",i);
    if(i>=n) return 0;

    if(vis[i]==1) return dp[i];

    double cnt=0,j,total=0;

    total=0;

    for(j=1;j<=6; j++)
    {
        double num= f(i+j);

        if(num==0) cnt++;
        else
        total+= (num + a[i])/6;

    }

    if(cnt==6) return a[i];
    total= (total*6) / (6-cnt);

    vis[i]=1;
    return dp[i]= total;

}
int main()
{

    int t=0,test;
    scanf("%d",&test);
    while(t<test){
    memset(vis,0,sizeof(vis));
    int  i;
   cin>>n;

    for(i=0;i<n;i++) cin>>a[i];

    printf("Case %d: %.10f\n", ++t, f(0) );
    }
    return 0;
}
