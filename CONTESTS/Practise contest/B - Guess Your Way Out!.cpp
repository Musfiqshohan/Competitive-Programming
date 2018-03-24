#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define pii pair<ll,ll>
#define ll long long
using namespace std;

ll pow1(ll x,ll n)
{
    if(n==0) return 1;

    if(n%2==0)
    {
        ll res= pow1(x,n/2);
        return res*res;
    }

    return x* pow1(x,n-1);
}


int main()
{
    ll h,n;
    scanf("%lld %lld",&h,&n);

    ll height=h;
    ll low,high;

    low=1;
    high= pow1(2,h);

  //  prllf("%d %d\n",low,high);
    ll flag=0,total=0,mid;

    while(high!=low)
    {
        mid= (low+high)/2;

        if( (n<=mid && flag==1) || (n>mid && flag==0))
        {
            total+= pow1(2,h)-1;
            total++;
           // printf("%lld %lld\n",h, pow1(2,h)-1);

            if(n<=mid)  high=mid;
            else if(n>mid) low=mid+1;

            h--;

            flag^=1;
        }
        else
        {
            h--;
            high=mid;
            total++;
           // printf("total=%lld\n",total);

        }

        flag^=1;


    }

//    if(n==1 && height==1) printf("0\n");
//    else
    printf("%lld\n",total);


    return 0;
}
