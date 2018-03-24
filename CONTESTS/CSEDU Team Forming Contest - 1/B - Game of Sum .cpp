#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define inf 1000099
using namespace std;
ll ara[105];
ll dp[105][105][3];
ll f(ll i, ll j, ll turn)
{
    static ll cnt=0;
   // printf("%d %d\n",i,j);
    if(i>j) return  0;

    //if(dp[i][j][turn]!=-1) return dp[i][j][turn];


    ll total=0,sum=0,mx=INT_MIN;
     printf("->%lld %lld %lld ->%lld\n",i,j,turn,mx);
    for(ll k=i;k<=j;k++)
    {

        sum+=ara[k];

        if(turn==0)
        total=sum+f(k+1,j,1);
        else
        total=sum+f(k+1,j,0);

        printf("hi=%lld\n",++cnt);

        mx=max(mx,total);
    }

    sum=0,total=0;
    for(ll k=j;k>=i;k--)
    {
        sum+=ara[k];
        if(turn==0)
        total=sum+f(i,k-1, 1);
        else
        total=sum+f(i,k-1, 0);

        mx=max(mx,total);

    }

    printf("%lld %lld %lld ->%lld\n",i,j,turn,mx);

    if(turn==0) return dp[i][j][turn]=mx;
    else return dp[i][j][turn]=(-1)*mx;

}
int main()
{
    while(1){
    ll n;
    scanf("%lld",&n);
    if(n==0) break;
    ms(dp,-1);
    for(int i=0;i<n;i++) scanf("%lld",&ara[i]);

   // cout<<f(0,n-1,0)<<endl;
    printf("%lld\n",f(0,n-1,0));

    }
    return 0;
}
