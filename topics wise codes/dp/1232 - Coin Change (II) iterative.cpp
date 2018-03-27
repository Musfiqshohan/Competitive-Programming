#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll value[101];
ll ara[10001];
ll n,k;
int main()
{
    ll mod=100000007;
    ll tt=0,test;
   scanf("%lld",&test );
    while(tt<test)
    {
        scanf("%lld %lld",&n,&k);
        memset(ara,0,sizeof ara);

        for(int i=0; i<n; i++)
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
