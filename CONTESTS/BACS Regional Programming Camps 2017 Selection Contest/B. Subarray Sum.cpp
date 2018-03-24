#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<ll,ll>
#define inf 100000000000
using namespace std;
ll n,k;
ll ara[5009], dp[5009][5009][2];
ll f(ll  pos, ll k, ll isStart)
{
    if(pos==n && isStart==0) return -1*inf;
    if(pos==n) return 0;

    ll t1=-1*inf, t2=-1*inf ,t3=-1*inf;

    if(dp[pos][k][isStart]!=-1 ) return dp[pos][k][isStart];

    if(isStart==0)      //nei nai ekhono
    {
        //nibo
        if(ara[pos]<0)
        {
            if(k>0)
                t1= f(pos+1,k-1,1);

            t2= ara[pos] + f(pos+1, k, 1);
        }
        else
            t1= ara[pos]+ f(pos+1,k,1);

        t3= f(pos+1,k,0);

    }


    else if(isStart==1)
    {

        if(ara[pos]<0)
        {
            if(k>0)
                t1= f(pos+1,k-1,1);

            t2= ara[pos]+ f(pos+1,k,1);
        }
        else
            t1= ara[pos]+ f(pos+1,k,1);
        t3=0;

    }

    return dp[pos][k][isStart]=max(t1, max(t2,t3));




}


int main()
{
    ll t=0,test;
    scanf("%lld",&test);

    while(t<test) {
    ms(dp,-1);
    scanf("%lld %lld",&n,&k);

    for(ll i=0; i<n; i++) scanf("%lld",&ara[i]);

    printf("Case %lld: %lld\n",++t, f(0,k,0));

    }

    return 0;
}
