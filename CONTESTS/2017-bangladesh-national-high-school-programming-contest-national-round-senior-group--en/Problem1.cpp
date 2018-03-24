#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll t=0,test;
    cin>>test;

    while(t++<test)
    {
        ll n,m,total=0,x;
        scanf("%lld %lld",&n,&m);

        for(int i=0;i<n;i++)
        {
            scanf("%lld",&x);
            if(x%m!=0)
            total+= m-x%m;
        }

        printf("%lld\n",total);
    }

    return 0;
}
