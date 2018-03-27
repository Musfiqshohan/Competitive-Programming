#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[4000],prime[600], dp[502][502];
void sieve()
{
    ll i,j;

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



}
ll P,K;
ll mod=1000000007;
ll f(ll index, ll prm, ll cnt )
{

    ll total1=1, total2=1;


    if(prm==0 && cnt==0)
        return 1;

    else if(prm<0 || cnt<0) return 0;


    if(dp[prm][cnt]!=-1) return dp[prm][cnt];

    total1= (prime[index]%mod * f(index, prm, cnt-1 )%mod)%mod;

    total2= ( (prime[index+1]-1)%mod * f(index+1, prm-1, cnt-1 )%mod)%mod ;

    return dp[prm][cnt]=(total1%mod+total2%mod)%mod;

}
int main()
{

    sieve();


    int t,test;
    scanf("%d",&test);


    for(t=0;t<test;t++){

    scanf("%lld %lld",&K,&P);

      memset(dp,-1,sizeof(dp));
     printf("Case %d: %lld\n",t+1, f(0,P-1,K-1) );

    }

    return 0;
}

