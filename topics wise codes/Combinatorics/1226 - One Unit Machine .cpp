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

vector<int>adj[1009];
ll dp[1009][1009], ara[1009], fact[1000009];
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

ll f1(int m, int n)
{
    return nCr(m+n-1, n-1);
}


int main()
{
    fact[0]=1;
    for(ll i=1;i<=1000009;i++)
    {
        fact[i]= (fact[i-1]*i)%mod;
    }

  //  cout<<fact[50000]<<endl;

    ms(dp,-1);
    for(int i=1; i<=1006; i++)
    {
        for(int j=1; j<=i; j++)
            dp[i][j]= nCr(i,j);
    }

    int tt=0,test;
    cin>>test;

    while(tt<test)
    {

        int n;
        scanf("%d",&n);

        ll sum=0,total=1;
        for(int i=0; i<n; i++)
        {
            scanf("%d",&ara[i]);

            if(sum!=0)
                total= (total* f1(sum, ara[i]))%mod;
            sum= (sum+ara[i])%mod;
        }


        printf("Case %d: %lld\n",++tt, total);

    }



    return 0;
}
