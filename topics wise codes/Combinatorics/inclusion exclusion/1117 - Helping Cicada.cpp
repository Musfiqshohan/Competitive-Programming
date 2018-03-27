#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll ara[20],b[20], a[40100];

ll gcd(ll a, ll b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
ll lcm(ll a, ll b)
{
    return (a/gcd(a,b) ) * b;
}
int main()
{
    ll i;
    for(i=1; i<=40000; i++) a[i]=i;

    int t,test;
    scanf("%d",&test);
    for(t=0;t<test;t++){
    ll n,m,cnt,j,total=0;

    scanf("%lld %lld",&n,&m);

    ll cube=1;


    for(i=0; i<m; i++)
        scanf("%lld",&ara[i]);

    for(i=0; i<m; i++)
    {
        if(ara[i]==0) continue;
        for(j=i+1; j<m ; j++)
        {
            if(ara[j]%ara[i]==0) ara[j]=0;
        }
    }

    j=0;
    for(i=0; i<m; i++)
    {
        if(ara[i]!=0)
        {
            b[j]=ara[i];
            j++;
        }
    }

    m=j;
    for(i=1; i<=m; i++) cube*=2;
    ll sum;

    for(i=1; i<cube; i++)
    {
        sum=1;
        cnt=0;
        for(j=0; j<m; j++)
        {
            if( (a[i] & 1 << j )!=0)
            {
                cnt++;
                sum =lcm(sum, b[j] );
            }
        }

      //  printf("%d %d\n",sum, i);
        if(cnt%2==0)
            total-=  n/ sum;
        else total+= n/sum;

       //  printf("%d %d %d\n",sum, i,total);


    }

    printf("Case %d: %lld\n",t+1,n-total);

    }

    return 0;

}
