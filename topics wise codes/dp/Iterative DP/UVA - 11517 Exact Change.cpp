#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<int,int>
#define inf 100000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int dp[2*10009], coins[109];


int main()
{
    int test;
    cin>>test;
    while(test--)  {

    int M,n;
    scanf("%d",&M);

    scanf("%d",&n);

    for(int i=0; i<n; i++) scanf("%d",&coins[i]);

    int mxMoney=20009;


    dp[0]=0;
    for(int i=1; i<=mxMoney; i++) dp[i]=100000;


    for(int i=0; i<n; i++)
    {
        for(int j=mxMoney; j>=coins[i]; j--)
        {
            if(dp[j-coins[i]]!=100000) dp[j]=min(dp[j],dp[j-coins[i]]+1);
        }
    }

    int res=0,cnt=0;
    for(int i=M; i<=mxMoney; i++)
    {
        if(dp[i]!=100000)
        {
            res=i,cnt=dp[i];
            break;
        }

    }

    printf("%d %d\n",res,cnt);

    }


}
