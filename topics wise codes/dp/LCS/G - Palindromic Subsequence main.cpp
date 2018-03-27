#include<bits/stdc++.h>
#define ms(a,b) memset(a,b,sizeof a);
using namespace std;

string a,b;
int dp[1009][1009];
int f(int i,int j)
{
    if(i==a.length() || j== b.length())
        return 0;

    if(dp[i][j]!=-1) return dp[i][j];
    int res=0;
    if(a[i]==b[j])
    {
        res= 1 + f(i+1, j+1);
    }
    else
    {
        int res1= f(i+1,j);
        int res2= f(i,j+1);

        res= max(res1,res2);
    }

    return dp[i][j]=res;
}

string ans;
string mn;
void f2(int i, int j)
{
    if(i=a.length() || j==b.length())
    {
        mn= min(mn,ans);
        cout<<mn<<" "<<ans<<endl;
        return ;
    }

    if(a[i]==b[j])
    {
        ans+= a[i];
        f2(i+1,j+1);
        ans.erase(ans.length()-1);
    }
    else
    {
        if(dp[i+1][j] > dp[i][j+1] )
            f2(i+1,j);
        else if( dp[i][j+1] < dp[i][j+1] )
            f2(i,j+1);
        else
        {
             f2(i+1,j);
             f2(i,j+1);
        }
    }

}

int main()
{
    ms(dp,-1);
    cin>>a;
    b=a;
    reverse(b.begin(),b.end());

    for(int i=0;i<a.length();i++) mn+='z';

    cout<<f(0,0)<<endl;
    f2(0,0);

    cout<<mn<<endl;

}
