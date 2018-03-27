#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll base,k,n;
ll dp[(1<<18)+2][20];
string dig;
ll Set(ll N, ll pos) { return N=N|(1<<pos); }
bool check(ll N, ll pos) {  return N&(1<<pos); }

ll f(ll mask, ll mod)
{
    if(mask==(1<<n)-1)
    {
        if(mod==0) return 1;
        else return 0;
    }

    if(dp[mask][mod]!=-1) return dp[mask][mod];

    ll total=0,i,j;

    for(i=n-1;i>=0;i--)
    {

        if(check(mask,i)==0)
        {
            ll num;
            if(dig[i]>=65)
                num=(dig[i]-'A') + 10;
            else
             num=dig[i]-'0';

           // printf("%d\n",num);
            ll ret= (mod*base+num)%k;
            total+= f(Set(mask,i),ret);

        }
    }

    return dp[mask][mod]=total;

}
int main()
{

    memset(dp, -1, sizeof dp);
    ll num;
    scanf("%lld %lld",&base,&k);

    cin>>dig;
    n=dig.length();

    printf("%lld\n",f(0,0));

    return 0;
}

