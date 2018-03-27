#include<bits/stdc++.h>
using namespace std;
int dp[10020], a[10020];
int grundy(int n)
{
    // printf("%d\n",n);
    if(n==1 || n==2) return 0;
    else if(n==3) return 1;


    if(dp[n]!=-1) return dp[n];

    int flag[10090];
    memset(flag,0,sizeof flag);

    for(int  i=1, j=n-1 ; i<j ; i++, j--)
    {
        //printf("grundy(%d)^grundy(%d) =%d\n",i,j,grundy(i)^grundy(j));
        flag[grundy(i)^grundy(j)]=1;
    }

    for(int i=0;  ; i++)
    {
        if(!flag[i]) return  dp[n]=i;
    }


}


int main()
{
    memset(dp,-1,sizeof dp);

    int i;
    for(i=1; i<=10000; i++)
        dp[i]=grundy(i);



    int t=0, test;
    cin>>test;

    while(t<test)
    {


    int n,xsum=0;

    scanf("%d",&n);
    for(i=0; i<n; i++) scanf("%d",&a[i]);



    for(i=0; i<n; i++)
    {
        xsum^= dp[a[i]];
    }

    printf("Case %d: ",++t);
    if(xsum==0) printf("Bob\n");
    else printf("Alice\n");


    }

    return 0;
}
