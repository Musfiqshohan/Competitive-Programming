#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long

using namespace std;

string s;

int dp[1009][1009];

int f(int i, int j)
{
    //printf("%d %d\n",i,j);
    if(i==j) return dp[i][j]=1;

    if(dp[i][j]!=-1) return dp[i][j];

    if(i+1==j)
    {
        if(s[i]==s[j]) return dp[i][j]=1;
        return 2;
    }

    if(s[i]==s[j] && f(i+1,j-1)==1)
       {
       // printf("->%d %d\n",i,j);
        dp[i][j]=1;
       }

    f(i+1,j);
    f(i,j-1);

    if(dp[i][j]==1) return 1;
    return 2;

}

int main()
{
    cin>>s;
    ms(dp,-1);
    for(int i=0;i<s.length();i++) dp[i][i]=1;
    f(0,s.length()-1);


    int start=0,cnt=0,endd;

    while(start<=s.length()-1)
    {
        endd=s.length()-1;
        while(dp[start][endd]!=1)
        {
            endd--;
        }
        cnt++;

       // printf("%d %d\n",start,endd);
        start=endd+1;

    }

    cout<<cnt<<endl;

    return 0;
}
