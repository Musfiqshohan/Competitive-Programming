#include<bits/stdc++.h>
using namespace std;
long long sievex[1010009], prime[1010009],memo[1010009];
long long MX=1010009,  mod=1000000007;
void sieve()
{
    long long i,j,root;
    root=sqrt(MX);
    for(i=3; i<=root; i+=2)
    {
        if(prime[i]==0)
        {
            for(j=i*i; j<=MX; j+=i)
                sievex[j]=1;

        }
    }

    j=1;
    prime[0]=2;
    for(i=3; i<=MX; i+=2)
        if(sievex[i]==0)
        {
            prime[j]=i;
            j++;
        }
}

long long pow1(long long x, long long n)
{
    long long num;

    if(n==0) return 1;

    if(n%2==0)
    {
        num= pow1(x,n/2)%mod;
     return (num*num)%mod;

    }
    else
    {
        return  ((x%mod)*(pow1(x,n-1)%mod))%mod;

    }
}

long long cal(long long total, long long i, long long cnt, long long n)
{

    total=  (total%mod) * (pow1( (memo[i]+1) , mod-2 )%mod ) ;
    total%=mod;



    if(n>0)
        memo[i]+=cnt;
    else
        memo[i]-=cnt;

    if(memo[i]<0) memo[i]=0;

    total = ( (total%mod) * ( memo[i]+1 )%mod )%mod;

    return total;

}

long long f(long long total, long long n)
{
    long long k=n,root,i,cnt;
    n=abs(n);

    root=sqrt(n);
    for(i=0; prime[i] <= root ; i++)
    {
        if(n% prime[i]==0)
        {
            cnt=0;
            while(n%prime[i]==0)
            {
                n/=prime[i];
                cnt++;
            }

            total= cal(total, prime[i], cnt,k);
        }
        root= sqrt(n);

    }

    if(n!=1)
        total = cal(total, n , 1, k);


    return total;

}
int main()
{   sieve();

    long long t,test;
    scanf("%lld",&test);

    for(t=0;t<test;t++){
    long long i,num;
    memset(memo,0,sizeof(memo));

    long long divisors=1;
    long long n;
   long long total=0;

    scanf("%lld",&n);


    for(i=0; i<n; i++)
    {
        scanf("%lld",&num);



        divisors= f(divisors,num);
        total= ((total%mod) + (divisors%mod) )%mod;
    }

    printf("Case %lld: %lld\n",t+1,total);

    }

    return 0;
}
