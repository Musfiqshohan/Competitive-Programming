#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<int,int>
#define inf 100000000000
using namespace std;

ll ara[100009];
int main()
{
    ll test;
    cin>>test;

    while(test--)
    {

        ll n,cnt=0;
        scanf("%lld",&n);

        for(ll i=0; i<n; i++) scanf("%lld",&ara[i]);

        cnt=0;
        for(ll i=1; i<n; i++)
        {
            if(ara[i]==ara[i-1]) cnt++;
        }

        if(cnt==n-1)
        {
            printf("neutral\n");
            continue;
        }


        cnt=0;
        for(ll i=1; i<n; i++)
        {
            if(ara[i]>=ara[i-1]) cnt++;
        }

        if(cnt==n-1)
        {
            printf("allGoodDays\n");
            continue;
        }

        cnt=0;
        for(ll i=1; i<n; i++)
        {
            if(ara[i]<=ara[i-1]) cnt++;
        }

        if(cnt==n-1)
        {
            printf("allBadDays\n");
            continue;
        }


        ll mx=-1;

        for(ll i=1; i<n-1; i++)
        {
            if(ara[i-1]<ara[i] && ara[i]>ara[i+1])
            {

                for(ll j=i+2; j<n-1; j++)
                {
                    if(ara[j-1]<ara[j] && ara[j]>ara[j+1])
                    {
                        //printf("%lld %lld\n",j,i);
                        mx= max(mx, j-i -1);
                        break;
                    }
                }
            }
        }

        if(mx<=0)
        {
            printf("none\n");
            continue;
        }
        printf("%lld\n",mx);

    }

    return 0;
}
