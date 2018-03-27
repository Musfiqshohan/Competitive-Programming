#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[7000080], dp[2000][2000][2];
ll n,m;
ll f(ll i, ll sum, ll state)
{


    if( sum%m==0 && state==1  ) { return 1;  }
    if(i>=n) return 0;

    if(dp[i][sum][state]!=-1) return dp[i][sum][state];
    return  dp[i][sum][state]= f(i+1, (sum+a[i])%m ,1 ) | f(i+1,sum%m,state);





}
int main()
{
    memset(dp,-1,sizeof(dp));
     //memset(a,-1,sizeof(a));
    int i;
    scanf("%lld %lld",&n,&m);

    for(i=0;i<n;i++) scanf("%lld",&a[i]);

    if(n>m) { printf("YES\n"); return 0; }
    sort(a,a+n);

    if( a[0]==0) printf("YES\n");
    else if(f(0,0,0)==1) printf("YES\n");
    else printf("NO\n");

    return 0;

}
