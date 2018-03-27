#include<bits/stdc++.h>
#define ll long long
using namespace std;

string s;
int dp[109][109];
int f(int i, int j)
{
    if(i>=j) return 0;

    if(dp[i][j]!=-1) return dp[i][j];
    int sum=0;
   if(s[i]==s[j])
    sum= f(i+1,j-1);

   else
    sum= min(1+f(i,j-1), 1+f(i+1,j));

   return dp[i][j]=sum;
}

int main()
{
    int t=0,test;
    cin>>test;

    while(t++<test){

    memset(dp,-1,sizeof dp);
    cin>>s;

    int res= f(0, s.length()-1);

   printf("Case %d: %d\n",t,res);


    }


    return 0;
}
