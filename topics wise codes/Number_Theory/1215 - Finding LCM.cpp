#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[1000009];
ll prime[1000009];

ll gcd(ll a, ll b)
{
    return b==0? a : gcd(b,a%b);
}

void sieve()
{
    ll i,j;

    for(i=3; i<=1009; i+=2)
    {
        for(j=i*i; j<=1000009; j+=2*i)
            a[j]=1;
    }

    prime[0]=2;
    j=1;
    for(i=3; i<=1000009; i+=2)
    {
        if(a[i]==0)
        {
            prime[j]=i;
            j++;
        }
    }

}
ll fact(ll &n, ll i)
{
    ll  cnt=0;
    while(n%i==0)
    {
        n=n/i;
        cnt++;
    }

    return cnt;
}
ll pow1(ll x,ll n)
{
    if(n==0) return 1;
    if(n%2==0)
    {
      int  num= pow1(x,n/2);
        return num*num;
    }

    return x* pow1(x,n-1);
}
int main()
{
    sieve();

    int t,test;
    scanf("%d",&test);
    for(t=0;t<test;t++){
    ll a,b,L,c,d,cnt1,cnt2,cnt3,cnt4,root,i,total=1;
    scanf("%lld %lld %lld",&a,&b,&L);

    printf("Case %d: ",t+1);
    c= (a/ gcd(a,b)) *b;

    //printf("%lld %lld %lld\n",c, gcd(a,b), a/gcd(a,b));
    if(L%c!=0) {  printf("impossible\n"); continue; }
    d= L/c;

    if(c>d) root=sqrt(c);
    else root= sqrt(d);

    //printf("%d %d\n",c,d);
    for(i=0; prime[i]<= root; i++)
    {
        if(c%prime[i]==0 &&  d% prime[i]==0)
        {
            cnt1=fact(c, prime[i]);
            cnt2= fact(d,prime[i]);
            total *= pow1(prime[i],cnt1+cnt2);

        }
        else if(d%prime[i]==0)
        {
            cnt3= fact(d, prime[i]);
            total*= pow1(prime[i],cnt3);
        }

    }
    if(d!=1)
    {
        cnt4= fact(c,d);
        total*= pow1(d,cnt4+1);
    }

    printf("%lld\n",total);

    }
    return 0;
}
