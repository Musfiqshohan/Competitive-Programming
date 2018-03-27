#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ull unsigned long long
#define pii pair<ll,ll>
#define inf 100000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
using namespace std;


ull dp[29][200];

ull pow1(int x, int n)
{
    if(n==0) return 1;
    if(n%2==0)
    {
        ull ret= pow1(x,n/2);
        return (ret*ret);
    }

    return (x* pow1(x,n-1));

}



ull f(int n, int rem)
{

    if(n==0 && rem==0) return 1;
    if(n<0 || rem<0) return 0;

    if(dp[n][rem]!=-1) return dp[n][rem];

    ull ret=0;
    for(int i=1;i<=6;i++)
    {
        ret+= f(n-1,rem-i);

    }

    return dp[n][rem]=ret;

}



int main()
{
    ms(dp,-1);

    for(int i=1;i<=24;i++)
    {
        for(int j=0;j<=150;j++)
        {
            f(i,j);
        }
    }

    while(true){

    int n,x;

    scanf("%d %d",&n,&x);

    if(n==0 && x==0) break;

    ull deno=pow1(6,n);

    ull numo=0;

    for(int i=x;i<=n*6;i++)
    {
        numo+= f(n,i);
    }

  //  cout<<numo<< " " <<deno<<endl;

    ull gcd= __gcd(deno,numo);
    deno/=gcd;
    numo/= gcd;

    if(numo==0) printf("0\n");
    else if(numo==deno) printf("1\n");
    else
    printf("%llu/%llu\n",numo, deno);

    }

    return 0;
}
