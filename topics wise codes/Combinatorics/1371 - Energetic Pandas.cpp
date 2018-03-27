#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[1009],b[1009];
ll n, mod=1000000007;
ll srch(ll target)
{
    ll mid, low=0,high=n-1 ;

    while(low<=high)
    {
        mid=low + (high-low)/2;

        if(a[mid]>target)
            high=mid-1;
        else if(a[mid]<=target)
            low= mid+1;

    }


    if(a[mid]>target) return mid-1;

    if(a[mid]<=target) return mid;
}
int main()
{
    int t=0,test;

    cin>>test;


    while(t<test){

    ll x,i;
    scanf("%lld",&n);

    for(i=0;i<n;i++) scanf("%lld",&a[i]);
    sort(a+0,a+n);

    for(i=0;i<n;i++) scanf("%lld",&b[i]);
    sort(b+0,b+n);


    ll total=1;
    for(i=0;i<n;i++)
    {
        //printf("%d xx%d\n",b[i],srch(b[i]));
        total= ((total%mod)*((srch(b[i])+1-i)%mod))%mod;
    }

    printf("Case %d: %lld\n",++t,total);

    }

    return 0;
}
