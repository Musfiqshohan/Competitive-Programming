#include<bits/stdc++.h>
#define print(ara,n) for(long long i=0;i<n;i++)printf("%lld ",ara[i]); puts("");
#define  ll long long
using namespace std;

ll ara[100009],sum[100009];

ll search1(ll a[],ll n, ll q)
{
    ll high=n-1, low=0, mid=0,cnt=0;

    while(cnt++<=100)
    {
        mid= low + (high-low)/2;

        if(a[mid]>=q)
            high=mid;
        else if(a[mid]<q)
            low=mid;


    }

    if(a[mid+1]<q) mid++;
    else if(a[mid]>=q) mid--;

    return mid;
}

ll result(ll n, ll mid, ll q)
{
    ll t1= (n-mid+1)*q;
    if(t1-(sum[mid]-sum[n+1])>mid) return -1;
    else if(t1-(sum[mid]-sum[n+1])<=mid) return 1;
}

ll search2(ll s[], ll n, ll q)
{
    ll low=0, high=n, mid, cnt=0;

    while(cnt++<100)
    {
        mid= low + (high-low)/2;

        if(result(n,mid,q)==-1)
            low=mid+1;
        else if(result(n,mid,q)==1)
            high=mid;


    }

    if(result(n,mid-1,q)==1) return mid-1;
    if(result(n,mid,q)==1) return mid;
    if(result(n,mid+1,q)==1) return mid+1;




}
int main()
{
    int tx=0;
    cin>>tx;


    while(tx--)
    {
        ll n,q;

        scanf("%lld %lld",&n,&q);

        for(ll i=0; i<n; i++)
            scanf("%lld",&ara[i]);

        sort(ara,ara+n);



        for(ll i=n-1; i>=0; i--)
            sum[i]=sum[i+1]+ara[i];

        for(ll k=0; k<q; k++)
        {

            ll q1;
            scanf("%lld",&q1);

            ll maxhigh= search1(ara,n,q1);

            ll total= n - maxhigh -1 ;
            // cout<<"hi"<<total<<" "<<maxhigh<<endl;

            ll t=0;
            if(maxhigh>=0)
                t=search2(sum,maxhigh,q1);

           // cout<<t<<" "<<maxhigh<<endl;


            total+= maxhigh-t+1;

            //cout<<"ans"<<total<<endl;

            printf("%lld\n",total);


        }

        memset(sum,0,sizeof sum);
        memset(ara,0,sizeof ara);

    }

    return 0;
}
