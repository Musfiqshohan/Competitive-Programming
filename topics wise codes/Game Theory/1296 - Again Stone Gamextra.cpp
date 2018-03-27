#include<bits/stdc++.h>
using namespace std;
int a[2010], dp[2010];
int grundy(int n)
{
    if(n<=1) return 0;

    if(dp[n]!=-1) return dp[n];
    int stones=n-1;
    int flag[2000];
    memset(flag,0,sizeof flag);

    int till;
    if(n%2==0) till=n/2;
    else till= n/2+1;
    while(stones>=till)
    {
        int g= grundy(stones);
        //printf("%d %d %d\n",stones,g,n);
        flag[g]=1;
        stones--;
    }

   int i=0;
    while(flag[i]!=0) i++;
    return dp[n]=i;

}

int main()
{

    memset(dp, -1, sizeof dp);

    int t=0,test;
    cin>>test;

    cout<<grundy(test)<<endl;
//    while(t<test){
//    int n,i,xsum=0;
//    scanf("%d",&n);
//
//    for(i=0;i<n;i++)
//        scanf("%d",&a[i]);
//
//    for(i=0;i<n;i++)
//    {
//        xsum^=grundy(a[i]);
//    }
//
//    printf("Case %d: ",++t);
//    if(xsum==0) printf("Bob\n");
//    else printf("Alice\n");
//
//
//    }
    return 0;

}
