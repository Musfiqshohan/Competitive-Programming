#include<bits/stdc++.h>
#define ms(a,b) memset(a,b,sizeof a);
using namespace std;

int coins[109];
int n,total;
int dp[109][50009];
int f(int  index, int sum)
{
    static int cnt=0;
    cnt++;
    if(sum>=ceil(total/2.0))
    {

        return dp[index][sum]=2*sum - total;

    }
    if(index==n) return INT_MAX;

    if(dp[index][sum]!=-1) return dp[index][sum];
    int res1,res2;

    res1= f(index+1, sum+coins[index]);

    res2= f(index+1, sum);

    return dp[index][sum]=min(res1,res2);
}

int main()
{

  //  freopen("562 - Dividing coinsI.txt", "r", stdin);
  //  freopen("562 - Dividing coinsO.txt", "w", stdout);
    int t;
    cin>>t;

    while(t--)
    {
        ms(dp,-1);
        scanf("%d",&n);

        total=0;
        for(int i=0; i<n; i++)
        {
            scanf("%d",&coins[i]);
            total+=coins[i];
        }

        //cout<<total<<endl;
        cout<<f(0,0)<<endl;
    }

    return 0;
}
