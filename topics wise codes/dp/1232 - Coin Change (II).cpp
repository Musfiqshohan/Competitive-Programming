#include<stdio.h>
#include<bits/stdc++.h>
long long n,m=100000007;
long long rem[55], coin[55];
long long a[1000];
long long f(long long y, long long countx, long long k)
{
// printf("i=%lld k=%lld\n ",countx,k);

    long long total=0,j,x,t;

    if(k==0) return 1;
    if(countx==5) return 0;

    if(k<0) return -1;
    t=k;

   if(a[t]!=-1) {   return a[t];  }

    for(j=y;j<n;j++)
    {

        countx++;
      //  printf("j=%d ",coin[j]  );
        x=f(j, countx, k-coin[j]);
        countx--;

        if(x==-1) break;
        total+=x;
        printf("total = %lld k=%lld\n",total, k-coin[j]);

    }

    //return total;
    a[t] = total;
    return a[t];
}
int main()
{
    long long t,test;
    scanf("%lld",&test);
    for(t=0;t<test;t++){
    long long k,i;
    scanf("%lld %lld",&n,&k);

    memset(a,-1,sizeof(a));
    for(i=0;i<n;i++) scanf("%lld",&coin[i]);


    printf("Case %lld: %lld\n",t+1,f(0,0,k));
    }

    return 0;
}
