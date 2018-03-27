#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long ara[15];
long long a[12][12];
long long f(long long i, long long countx)
{
    long long total=0,j;

    if(countx==0)
        return 1;


    if(a[i][countx]!=-1) return a[i][countx];

    for(j=0;j<n;j++)
    {
        if(abs(ara[j]-ara[i])<=2)
            total+= f(j,countx-1);
    }

    a[i][countx]=total;
    return total;
}
int main()
{
    int t,test;
    scanf("%d",&test);
    for(t=0;t<test;t++){
    long long total=0,i;
    scanf("%lld %lld",&n,&m);

    for(i=0;i<n;i++)
        scanf("%lld",&ara[i]);

    memset(a,-1,sizeof(a));
    for(i=0;i<n;i++)
        total+= f(i,m-1);

    printf("Case %d: %lld\n",t+1,total);

    }
    return 0;
}
