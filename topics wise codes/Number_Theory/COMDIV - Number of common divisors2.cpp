#include<stdio.h>
#include<bits/stdc++.h>
long long a[1100009];
long long gcd(long long a,long long b)
{
   if(b==0) return a;
   else return gcd(b,a%b);
}

int main()
{
    long long i,j;

    long long t,test;
    scanf("%lld",&test);

    for(t=0; t<test; t++)
    {
        long long n,m,total=1,cnt;
        scanf("%lld %lld",&n,&m);
       int x= gcd(n,m);

       int root=sqrt(x);

       for(i=2;i<=root;i++)
       {
           if(x%i==0)
           {    cnt=0;
               while(x%i==0)
               {
                   x=x/i;
                   cnt++;
               }

               total*= (cnt+1);
           }
       }
       if(x!=1) total*=2;
       printf("%lld\n",total);
    }

    return 0;
}

