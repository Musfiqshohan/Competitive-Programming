#include <bits/stdc++.h>
using namespace std ;
string a,b;
int l1,l2;
int dp[2009][2009];
int LCS(int i, int j)
{

    if(i==l1)
    {
        return l2-j;
    }
    else if(j==l2)
    {
        return l1-i;
    }


    if(dp[i][j]!=-1) return dp[i][j];

    int total,t1,t2,t3;
    if(a[i]==b[j])
    {

        total=LCS(i+1,j+1);
    }
    else
    {
        t1=1+ LCS(i+1,j+1);   //for change
        t2=1+ LCS(i+1,j); // for insert
        t3=1+ LCS(i,j+1);  //delete

        total= min(min(t1,t2),t3);

    }

    return dp[i][j]=total;
}
int main()
{
    int t=0,test;

    scanf("%d",&test);

    while(t++<test) {

    memset(dp,-1,sizeof dp);
    cin>>a>>b;
   // cout<<a<<" "<<b<<endl;
    l1=a.length();
    l2=b.length();
    cout<<LCS(0,0)<<endl;
    }


    return 0;
}
