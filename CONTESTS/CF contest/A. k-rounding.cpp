#include<bits/stdc++.h>
using namespace std;

long long pow1(long long x, long long n)
{
    if(n==0) return 1;
    if(n%2==0)
    {
        long long ret= pow1(x,n/2);

        return ret*ret;
    }

    return x*pow1(x,n-1);

}
int main()
{

    long long n,k;
    scanf("%lld %lld",&n,&k);

    long long cnt=0,cnt2=0;
    while(n%2==0)
    {
        n/=2;
        cnt++;
    }

    while(n%5==0)
    {
        n/=5;
        cnt2++;
    }


    if(cnt>k) n*=pow1(2,cnt-k);

    if(cnt2>k) n*=pow1(5,cnt2-k);

    printf("%lld",n);

    for(long long i=0;i<k;i++) printf("0");
    puts("");

}
