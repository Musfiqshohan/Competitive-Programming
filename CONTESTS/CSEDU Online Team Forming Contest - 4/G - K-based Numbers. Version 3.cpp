#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
using namespace std;

vector<ll>digs;

ll n,k,m;
ll dp[500009][3][3];
ll DP(ll pos, ll isStart, ll last)  //, ll num
{
    if(pos==n+1) {  return 1;   }  // prllf("num= %d\n",num);

    if(dp[pos][isStart][last]!=-1) return dp[pos][isStart][last];

    ll res=0;

    if(!isStart)
    {
        for(ll i=0; i<k; i++)
        {
            if(last==0 && i==0) continue;
            res= (res+ DP(pos+1, 0, i))%m;  //, num*10+i
        }
    }
    else
    {
        for(ll i=1; i<k; i++)
        {
            if(last==0 && i==0) continue;
            res= (res+ DP(pos+1, 0, i))%m; //,num*10+i
        }

        //res+= DP(pos+1, 1, 1,0);
    }


    return dp[pos][isStart][last]=res;
}


int main()
{
    ms(dp,-1);
    scanf("%lld %lld %lld",&n,&k,&m);

    cout<<DP(1,1,1)%m<<endl;

    return 0;
}
