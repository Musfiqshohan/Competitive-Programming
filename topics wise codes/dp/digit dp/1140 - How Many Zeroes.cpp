#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll mem[12];

ll pow1(ll x, ll n)
{
    if(n==0) return 1;

    if(n%2==0)
    {
        ll ret= pow1(x,n/2);
        return ret*ret;
    }

    return x*pow1(x,n-1);
}

ll dp(ll n)
{
    if(n==0) return 0;
    if(n==1) return 1;

    if(mem[n]!=-1) return mem[n];

    ll sum= pow1(10,n-1) + 10* dp(n-1);
    return mem[n]=sum;
}


vector<ll>v1;
ll reverss(ll cnt)
{
    ll sum=0;

    for(ll i=v1.size()-cnt ;i<v1.size();i++)
    {
        sum= sum*10+v1[i];
    }


    return sum;
}

ll makedig(ll n)
{
    while(n)
    {
        ll rem= n%10;

        v1.push_back(rem);
        n=n/10;
    }

    reverse(v1.begin(),v1.end());
}

ll f(ll n)
{
    if(n<0) return 0;
    if(n<=9) return 1;

    makedig(n);

    ll sum=0;
    ll cnt=0,nines=0,afterzero=0,rem=0;

    while(n>=10)
    {

        nines= nines*10+9;
        rem=n%10;
        sum+= rem* dp(cnt);

        if(rem==0) {sum+=reverss(cnt)+1;  }
        else
        sum += pow1(10,cnt);

        cnt++;
        n=n/10;

    }



    v1.clear();
    sum+= (n-1)*dp(cnt) + f(nines);
     v1.clear();

    return sum;
}
int main()
{

    memset(mem,-1,sizeof mem);

    int t=0,test;
    cin>>test;

    while(t<test){
    ll n,m;
    scanf("%lld %lld",&n,&m);


    printf("Case %d: %lld\n",++t,f(m)-f(n-1));

    }
    return 0;
}
