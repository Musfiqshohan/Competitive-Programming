#include<bits/stdc++.h>
using namespace std;
int MX=10000000;
int a[511100];
int prime[700000];

bool check(int N, int pos) { return (bool)(N&(1<<pos)); }
int setx(int N, int pos){ return N= N|(1<<pos);  }
void sieve()
{
    int root,i,j;
    root=sqrt(MX);
    for(i=3;i<=root;i+=2)
    {
        if( check(a[i>>5], i&31)==false )
        {
            for(j=i*i;j<=MX;j+=2*i)
                a[j>>5]= setx(a[j>>5], j&31);
        }
    }

    prime[0]=2;
    j=1;
    for(i=3;i<=MX;i+=2)
    {
        if ( check(a[i>>5], i&31)  ==false)
        {
            prime[j]=i;
            j++;
        }
    }

}
int main()
{

    sieve();

   int t,test;
   scanf("%d",&test);
   for(t=0;t<test;t++){
    int cnt=0,i,n;

    scanf("%d",&n);

    for(i=0; prime[i]<= n-prime[i]; i++)
    {
        int x=n-prime[i];
        if(check( a[x>>5] , x&31)==false  )
        {
            if( x%2!=0)
            cnt++;
           if(x==2) cnt++;

        }
    }
    printf("Case %d: %d\n",t+1,cnt);
   }
}
