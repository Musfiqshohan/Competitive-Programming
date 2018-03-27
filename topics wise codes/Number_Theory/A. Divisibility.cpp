#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long k,a,b,low,high;


    scanf("%lld %lld %lld",&k,&a,&b);

    if(a>b) swap(a,b);

    if(b>=0)
    {
        high=(b/k)*k;
    }
    if(a<0)
    {
        low= (a/k)*k;
    }
    if(a>=0)
    {

        low= k* (a/k + (bool)(a%k!=0));
    }
    if(b<=0)
    {
        high= k* ( b/k - (bool)(b%k!=0) );
    }


    if(a>b) printf("0\n");
    else printf("%lld\n", high/k -low/k +1);

    return 0;

}
