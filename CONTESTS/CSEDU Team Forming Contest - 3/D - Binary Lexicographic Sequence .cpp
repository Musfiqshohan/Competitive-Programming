#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
using namespace std;

ll dig[50];
ll dp[45][2][2];
ll n;
vector<ll>v;
ll DP(ll pos, ll isSmaller, ll last)
{
    if(pos==n+1)
    {
        return 1;
    }

    if(dp[pos][isSmaller][last]!=-1) return dp[pos][isSmaller][last];

    ll ses= isSmaller? 1: dig[pos];

    ll res=0;

    for(ll i=0; i<=ses; i++)
    {
        if(last==1 && i==1) continue;
        res+= DP(pos+1, isSmaller | i<dig[pos],  i);
    }


    return dp[pos][isSmaller][last]=res;
}


int main()
{


        ms(dig,0);
        ms(dp,-1);
        ll k;
        scanf("%lld %lld",&n,&k);

//    dig[2]=1;
//    dig[4]=1;
//    cout<<DP(1, 0, 0,0)<<endl;

        for(ll i=1; i<=n; i++)
        {
            ms(dp,-1);
            if(dig[i-1]==1 && i>0)
            {
                v.push_back(0);      //
                continue;
            }
            dig[i]=1;



            if(DP(1, 0, 0)>k)
            {

                dig[i]=0;
                v.push_back(dig[i]);
            }

            else
            {
                v.push_back(dig[i]);
            }
        }

        if(DP(1,0,0)<k)  printf("-1");
        else
        {
            for(ll i=0; i<v.size(); i++) printf("%lld",v[i]);
        }
        puts("");

        v.clear();


    return 0;
}
