#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll zero(ll n)
{
    ll cnt=0;
    while(n)
    {
        ll rem=n%10;
        if(rem==0) cnt++;
        n=n/10;

    }
    return cnt;
}
int main()
{
    ll n,total=0;
    scanf("%lld",&n);


    for(ll i=0;i<=n;i++)
    {
        total+= zero(i);
        //printf("%d %d\n",i, zero(i));
    }

    cout<<total+1<<endl;
}
