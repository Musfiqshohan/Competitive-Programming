#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[35][35][35];
ll f(ll row, ll col , ll k)
{

    if(k>row || k>col) return 0;
    if(row<0 || col <0) return 0;
    if(k==0) return 1;


    if( dp[row][col][k]!=-1 ) return  dp[row][col][k];

    return dp[row][col][k]= row* f(row-1,col-1 , k-1) + f(row, col -1, k);

}

int main()
{
    memset(dp,-1,sizeof(dp));

    int t=0,test;
    scanf("%d",&test);
    while(t<test){
    ll n,k;
    scanf("%lld %lld",&n,&k);


    printf("Case %d: %lld\n", ++t, f(n,n,k) );

    }
}
