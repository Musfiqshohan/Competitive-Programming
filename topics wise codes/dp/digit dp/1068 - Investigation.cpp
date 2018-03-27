#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
using namespace std;

vector<ll>digs;
ll lim,k,tt;

ll dp[13][90][90][2], vis[13][90][90][2];

ll DP(ll pos , ll rem1, ll rem2, ll  isSmaller)
{

    if(pos==lim)
    {

        if(rem1%k==0 && rem2%k==0)
            return 1;
        else return 0;

    }

    if(vis[pos][rem1][rem2][isSmaller]==tt) return dp[pos][rem1][rem2][isSmaller];

    vis[pos][rem1][rem2][isSmaller]=tt;

    ll ret=0;
    ll ses= isSmaller? 9:digs[pos];

    for(int i=0;i<=ses;i++)
    {
        ret+= DP(pos+1, (10*rem1+ i)%k , (rem2+i)%k,  isSmaller| i<digs[pos] );
    }

    return dp[pos][rem1][rem2][isSmaller]=ret;

}
ll f(ll n)
{

    if(n<0) return 0;
    if(n==0) return 1;


    digs.clear();

    while(n)
    {
        int rem=n%10;
        digs.push_back(rem);
        n=n/10;
    }

    reverse(digs.begin(), digs.end());
    lim= digs.size();


    tt++;

   return DP(0,0,0,0);

}



int main()
{
    int t=0,test;

    cin>>test;

    while(t<test){
    ll a,b;

    scanf("%lld %lld %lld",&a,&b,&k);


    ll res;
    if(k>81) res=0;
    else
        res=f(b)-f(a-1);
    printf("Case %d: %lld\n",++t, res);

    }
    return 0;
}
