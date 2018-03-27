#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll ara[20024],a[20024],b[20024],fact[1000009];
ll mod =100000007;

ll pow2(ll i)
{
    if(i%2==0) return 1;
    else return -1;
}

ll pow1(ll x , ll n)
{
    if(n==0) return 1;
    if(n%2==0)
    {
        ll rem= pow1(x,n/2)%mod;
        return (rem%mod * rem%mod)%mod;
    }
    return (x%mod *  pow1(x,n-1)%mod)%mod;
}
ll nCr(ll n, ll r)
{
    ll total=0,total1;

    if(n<0 || n<r || r<0) return 0;


    total= fact[n];
    total1=  ( fact[r] * fact[n-r] )%mod;

    total = (total%mod * pow1( total1, mod-2 )%mod)%mod;

    return total;
}
int main()
{
    ll i;
    fact[0]=1;
    for(i=1;i<=1000009;i++) fact[i]= (i%mod*fact[i-1]%mod)%mod;


    int t,test;
    scanf("%d",&test);
    for(t=0;t<test;t++){

    getchar();

    ll k,n,num,sum=0,sum2=0,cnt,x,y,j,total=0,cube=1;
    scanf("%lld %lld",&k,&n);

    for(i=0;i<k;i++)
    {
        scanf("%lld %lld",&x,&y);
        b[i]= y-x;
        sum+=x;
        sum2+=y;
    }



    j=0;
    for(i=0;i<k;i++)
    {

            a[j]=b[i]+1;
            j++;

    }

    ll r=j;

    printf("Case %d: ",t+1);
    if(sum2<n) { printf("0\n"); continue;  }

    if(j==1 && b[0]==0 ) {  printf("1\n"); continue;  }


    n-=sum;

    for(i=1;i<=r;i++) cube*=2;

    for(i=0;i<cube;i++) ara[i]=i;

    for(i=0;i<cube;i++)
    {
        sum=0;
        cnt=0;
        for(j=0;j<r;j++)
        {
            if( (ara[i] & (1<<j)) !=0 )
            {
                sum+= a[j];

                cnt++;
            }

        }


        num =  n - sum  +k -1 ;
        num = nCr(num, k-1);
        total = (total %mod +  pow2(cnt) * num + mod )%mod;


    }

    printf("%lld\n",total);

    }
    return 0;

}
