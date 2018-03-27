#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
long long ara[101][101];
long long a[101][101];
long long f(long long i, long long j)
{

    long long total;
    if(i<0 || j<0) return 0;
    if(i==0 && j==0) return ara[0][0];

    if(a[i][j]!=-1) return a[i][j];

    a[i][j]=ara[i][j] + max( f(i-1,j) , f(i, j-1) );

    return a[i][j];

}
int main()
{
    int t,test;
    scanf("%d",&test);
    for(t=0;t<test;t++){
    long long n,i,j,k;
    scanf("%lld",&n);

    for(i=0;i<n;i++)
    {
        for(j=i,k=0;j>=0; j--, k++)
        {
            scanf("%lld",&ara[j][k]);
        }
    }



    for(i=1;i<n;i++)
    {
        for(j=n-1, k=i; k<n ; j--, k++)
            scanf("%lld",&ara[j][k]);
    }



    memset(a,-1,sizeof(a));
    printf("Case %d: %lld\n",t+1,f(n-1,n-1));

    }
    return 0;
}
