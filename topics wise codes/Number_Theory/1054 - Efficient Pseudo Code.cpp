#include<bits/stdc++.h>
using namespace std;

long long a[1000009], b[1000009];
long long mod=1000000007;
void sieve()
{
    long long i,j;
    for(i=3; i<=1009; i+=2)
    {
        if(a[i]==0)
        {
            for(j=i*i; j<=1000009; j+=2*i)
                a[j]=1;
        }
    }

    b[0]=2;
    j=1;
    for(i=3; i<=1000009; i+=2)
    {
        if(a[i]==0)
        {
            b[j]=i;
            j++;
        }
    }




}
long long pow1(long long x, long long n)
{
    if(n==0) return 1;

    if(n%2==0)
    {
        long long num= pow1(x,n/2)%mod;
        return (num*num)%mod;
    }

    return ((x%mod)*(pow1(x,n-1)%mod))%mod;


}
int main()
{
     sieve();

    int t,test;
    scanf("%d",&test);
    for(t=0;t<test;t++){
    long long n,m,k,i,cnt,total=1;
    scanf("%lld %lld",&n,&m);

    long long root=sqrt(n);


    for(k=0; b[k]<=root ; k++)
    {
        i=b[k];
        if(n%i==0)
        {
            cnt=0;
            while(n%i==0)
            {
                n=n/i;
                cnt++;
            }

            cnt*=m;


            total= ((total%mod) *  ((pow1(i, cnt+1)%mod -1)%mod * pow1(i-1, mod-2)%mod)%mod )%mod;
        }

        root= sqrt(n);
    }


    if(n!=1)
    {
        cnt=m;

        total= ((total%mod) *  ((pow1(n, cnt+1)%mod -1)%mod * pow1(n-1, mod-2)%mod)%mod)%mod;
    }

    printf("Case %d: %lld\n",t+1,(total+mod)%mod);
    }

    return 0;

}
