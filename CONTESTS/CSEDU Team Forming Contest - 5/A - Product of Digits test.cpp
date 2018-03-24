#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
using namespace std;

ll mn=1000000000000000;
void f(ll n, ll mul)
{
    if(n==1)
    {
       // prllf("res= %d\n",mul);
        mn=min(mn,mul);
        return;
    }


    ll  res=0;

    for(ll i=2;i<=9;i++)
    {
        if(n%i==0)
        {
            f( n/i, mul*10+i );
        }
    }


}

int main()
{
    ll n;
//    freopen("output.txt", "w", stdout);
//    for(ll i=2;i<=1000;i++){
//    mn=1000000000000000;
    scanf("%lld",&n);
    f(n,0);

   // printf("%lld ",i);
    if(mn==1000000000000000) printf("-1\n");
    else printf("%lld\n",mn);

   // }
    return 0;
}
