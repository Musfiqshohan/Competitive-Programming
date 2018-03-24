#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<ll,ll>
#define inf 100000000000
using namespace std;
ll n;
ll ara[100009], dp[100009][2];
ll f(ll pos, ll isOdd)
{
    if(pos==n)
    {
        if(isOdd==1) return 0;
        else return -1*inf;
    }

    if(dp[pos][isOdd]!=-1) return dp[pos][isOdd];

    ll t1; //= ara[pos];

    if(isOdd==0)
    {
        if( (ara[pos]%2 +2)%2==1) t1= ara[pos] + f(pos+1,1);
        else t1= ara[pos] +f(pos+1,0);
    }
    else
    {
        if((ara[pos]%2 +2)%2==1)
            t1= ara[pos]+  f(pos+1,0);
        else
            t1= ara[pos]+  f(pos+1,1);
    }


    ll t2= f(pos+1, isOdd);

    return dp[pos][isOdd]=max(t1,t2);

}

int main()
{
    ms(dp,-1);

    scanf("%lld",&n);

    for(ll i=0;i<n;i++)
    {
        scanf("%lld",&ara[i]);
    }

    cout<<f(0,0)<<endl;

    return 0;
}
