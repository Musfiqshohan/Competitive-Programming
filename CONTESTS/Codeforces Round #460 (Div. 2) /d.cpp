#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<ll,ll>
#define inf 100000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
using namespace std;


ll fact[2000009];
ll mod=1000000007;

ll pow1(int x, int n)
{
    if(n==0) return 1;
    if(n%2==0)
    {
        ll ret= pow1(x,n/2);
        return (ret*ret)%mod;
    }

    return (x* pow1(x,n-1))%mod;

}

ll nCr(int n, int r)
{

    if(r==0 || n==r) return 1;
    if(r==1) return n;

   ll num= fact[n];

   ll den=( fact[n-r] * fact[r] )%mod;

   ll res= (num * pow1(den, mod-2)   )%mod;

    return res;
}




int main()
{
    fact[0]=1;
    for(ll i=1;i<=2000005;i++)
    {
        fact[i]= (fact[i-1]*i)%mod;
    }


    int tt=0,test;
    cin>>test;
    while(tt<test)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        printf("Case %d: %lld\n",++tt,nCr(a+b-1,b-1));


    }


    return 0;
}
