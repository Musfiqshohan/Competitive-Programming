#include<bits/stdc++.h>
typedef long long ll;
#define mod 100000007
using namespace std;

ll value[1000],ara[10009];

int main()
{
    ll tt=0,test;
   scanf("%lld",&test);
    while(tt<test)
    {
        ll n,k;
        scanf("%lld %lld",&n,&k);
        memset(ara,0,sizeof ara);

        for(int i=1; i<=n; i++)
            scanf("%lld",&value[i]);

        ara[0]=1;
        for(int i=0; i<n; i++)
        {
            for(int j=value[i]; j<=k; j++)
            {
                ara[j]=(ara[j]%mod) +  (ara[j-value[i]]%mod);

            }
        }

        printf("Case %lld: %lld\n", ++tt, ara[k]%mod);


    }


    return 0;

}
