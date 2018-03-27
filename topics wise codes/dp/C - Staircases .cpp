#include<stdio.h>

long long a[501][501];
long long  f(long long last, long long n)
{
    long long i,countx=0;
    if(n<0) return 0;
    if(n==0) {  return 1; }
   // if(n-last-1<0) return ;

   if(a[last][n]!=-1) return a[last][n];

    for(i=last+1; i<=n; i++)
    {
       countx+= f(i, n-i);
    }

    a[last][n]=countx;
    return a[last][n];
}

int main()
{
   long long n,i,j;

    for(i=0;i<501;i++)
    {
        for(j=0;j<501;j++) a[i][j]=-1;
    }
    scanf("%lld",&n);
    printf("%lld\n",f(0,n)-1);

}
