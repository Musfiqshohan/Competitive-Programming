#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define inf 1000000000000000
#define pii pair<ll,ll>
#define mod 1000000007
using namespace std;

int dp[1000009];

int f(int n)
{
    if(n==0)
        return 1;
    if(n<0)
        return 0;

    if(dp[n]!=-1) return dp[n];

    int t1=0,t2=0;

    t1=f(n-2);
    t2=f(n-3);

    return dp[n]=(t1+t2)%mod;

}

int main()
{
    memset(dp,-1,sizeof dp);

    int tt;
    scanf("%d",&tt);
    while(tt--)
    {
        int n;
        scanf("%d",&n);

        int res=f(n);
        printf("%d\n",res);
    }

}
