#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define inf 1000099
using namespace std;

ll ara[105], dp[105][105][3];
ll f(ll start, ll endd, ll turn)
{
    if(start>endd) return 0;

    if(dp[start][endd][turn]!=-1) return dp[start][endd][turn];

    ll sum=0,total=0, mn=INT_MAX, mx=INT_MIN;
    for(int i=start;i<=endd;i++)
    {
        sum+=ara[i];

        if(turn==0){
        total=sum+ f(i+1,endd, turn^1);
        mx= max(mx,total);
        }

        if(turn==1){
        total=-sum+f(i+1,endd,turn^1);
        mn=min(mn,total);

        }

    }

    sum=0;
    for(int i=endd;i>=start;i--)
    {
        sum+=ara[i];

        if(turn==0)
        {
            total=sum+ f(start,i-1,turn^1);
            mx= max(mx, total);
        }

        if(turn==1)
        {
            total=-sum + f(start, i-1, turn^1);
            mn= min(mn,total);
        }

    }


    if(turn==0) return dp[start][endd][turn]= mx;
    if(turn==1) return dp[start][endd][turn]= mn;
}


int main()
{
    while(1){
    ll n;
    scanf("%lld",&n);
    if(n==0) break;
    ms(dp,-1);
    for(int i=0;i<n;i++) scanf("%lld",&ara[i]);

    printf("%lld\n",f(0,n-1,0));

    }
    return 0;
}
