#include<bits/stdc++.h>
using namespace std;
int a[4006],prime[600];
void sieve()
{
    int i,j;

    for(i=3;i<=65;i+=2)
    {
        if(a[i]==0)
        {
            for(j=i*i;j<=4000;j+=2*i)
                a[j]=1;
        }
    }

    prime[0]=2;
    j=1;
    for(i=3;i<=4000;i+=2)
    {
        if(a[i]==0)
        {
            prime[j]=i;
            j++;
        }
    }

    printf("%d\n",j);

}
int sum=0,P,K;
void f(int index, int prm, int cnt, int total )
{
    printf("%d %d %d %d\n",prime[index],prm, cnt ,total);
    if(prm==P && cnt==K)
    {
        sum+=total;
        return;
    }
    else if(prm>P || cnt>K) return ;

   // if(dp[P][K])

   // dp[P][K]=total;

    f(index, prm, cnt+1 , total * prime[index]);

    f(index+1, prm+1, cnt+1, total * (prime[index+1]-1) ) ;

}
int main()
{

    sieve();
    int i;

    scanf("%d %d",&K,&P);



        f(0,1,1,prime[0]-1);
     printf("%d\n", sum );




}
