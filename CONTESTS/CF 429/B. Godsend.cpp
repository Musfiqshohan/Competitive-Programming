#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<ll,ll>
#define inf 100000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
using namespace std;

ll ara[1000009];
int main()
{
    ll n,flag=0;
    scanf("%lld",&n);

    ll sum=0,x;
    for(ll i=0;i<n;i++)
    {
        scanf("%lld",&ara[i]);
        sum+=ara[i];

        if(ara[i]%2==1)
            flag=1;
    }


    if(sum%2==1) printf("First\n");
    else
    {
        if(flag==1)
            printf("First\n");
        else printf("Second\n");

    }

}
