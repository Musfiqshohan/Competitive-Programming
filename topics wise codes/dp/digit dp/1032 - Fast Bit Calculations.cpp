#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
#define ll long long
using namespace std;
vector<ll>bits;

ll lim;

ll pow1(ll x,ll n)
{
    if(n==0) return 1;

    if(n%2==0)
    {
        ll ret= pow1(x,n/2);
        return ret*ret;
    }

    return x* pow1(x,n-1);
}

ll evaluate(ll pos,ll isSmaller)  // let, 1011xxxx   here i have calculated: for how many time this 11 will be calculated for xxxx
{

     ll total=1,num=1;

    if(isSmaller==1) total= pow1(2,lim-pos);
    else
    {
        for(ll i=bits.size()-1; i>=pos; i--)
        {
            total+= bits[i]*num;
            num*=2;
        }
    }
     if(total==0) total=1;

    return total;
}

ll dp[31][3][3];        // cz, 2^31   so 31 binary digits is needed!!! :p :D :o

ll DP(ll pos, ll isOne,ll  isSmaller)
{
    if(pos>=lim)
    {

        return 0;
    }

    if(dp[pos][isOne][isSmaller]!=-1) return dp[pos][isOne][isSmaller];

    ll ses= isSmaller?     1:bits[pos];

    ll ret=0;                       // this is digit dp
    for(ll i=0; i<=ses; i++)
    {

        if(isOne==1 && i==1)
        {
            ret+= evaluate(pos+1,isSmaller| i<bits[pos]);


        }
        ret+= DP(pos+1,i, isSmaller| i<bits[pos]);
    }

    return dp[pos][isOne][isSmaller]=ret;
}
ll f(ll n)
{

    bits.clear();

    while(n)
    {
        bits.push_back(n%2);
        n=n/2;
    }

    reverse(bits.begin(), bits.end());
    lim= bits.size();


    return DP(0,0,0);

}
int main()
{

    int t=0,test;
    cin>>test;

    while(t<test){
    ms(dp,-1);
    ll n;
    scanf("%lld",&n);

    printf("Case %d: %lld\n",++t,f(n));

    }
    return 0;
}
