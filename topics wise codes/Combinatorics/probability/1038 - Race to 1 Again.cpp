#include<bits/stdc++.h>
using namespace std;

int vis[101009];
double dp[101009];
double f(int n)
{
    if(n==1)  return 0;

    if(vis[n]!=-1) return dp[n];

    int i;
    double root,cnt=0,total=0;
    root= sqrt(n);
    for(i=1;i<=root; i++)
    {
        if(n%i==0)
        {
            total+=  f(i);
            cnt++;
            if( i !=(n/i)  && i!=1) { total+= f(n/i); cnt++; }
        }
    }

    total+= cnt +1;
    total/= (cnt);

    dp[n]=total;
    vis[n]=1;

    return total;
}
int main()
{
    memset(vis,-1,sizeof(vis));
    int t=0,test;
    scanf("%d",&test);
    while(t<test){
    int n;
    cin>>n;

    printf("Case %d: %.10f\n", ++t, f(n));
    }

    return 0;
}
