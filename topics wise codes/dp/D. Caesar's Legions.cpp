#include<bits/stdc++.h>
using namespace std;
long long dp[200][200][20][20];
long long m1, m2,mod=100000000 ;
long long f(long long n1,long long n2,long long k1,long long k2)
{
    long long total1=0,total2=0;


   // printf("%d %d %d %d\n",n1,n2,k1,k2);
    if(n1<0 || n2<0) return 0;
    if(n1==0 && n2==0) {  return 1;  }

    if(dp[n1][n2][k1][k2]!=-1) return dp[n1][n2][k1][k2];

    if(k1==m1 ) {  k1=0; total2= f(n1, n2-1, k1, k2+1);  }
    else if(k2==m2 ) {  k2=0;  total1= f(n1-1, n2, k1+1, k2); }
    else{


        total1= f(n1-1, n2, k1+1, 0);

        total2= f(n1, n2-1, 0, k2+1);


    }

    return dp[n1][n2][k1][k2]=  (total1%mod+total2%mod)%mod;
}

int main()
{
    memset(dp,-1,sizeof(dp));
    long long n1,n2;
    cin>>n1>>n2>>m1>>m2;

    cout<<f(n1,n2,0,0);
    return 0;
}
