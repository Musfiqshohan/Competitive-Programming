#include<bits/stdc++.h>
using namespace std;

#define ll long long
ll gcd(ll a, ll b)
{
    return b==0? a : gcd(b,a%b);
}
ll f(ll k, ll a, ll b)
{
    ll low,high;

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


    if(a>b) return 0;
    else return  high/k -low/k +1;

}
int main()
{
    int t,test;
    scanf("%d",&test);
    for(t=0;t<test;t++){

   ll x1,y1,x2,y2,k,total;
    scanf("%lld %lld %lld %lld",&x1,&y1, &x2, &y2);

    if(x1==x2) total= abs(y1-y2)+1 ;
    else if(y1==y2) total= abs(x1-x2)+1;
    else{

    k= abs(y1-y2) / ( gcd( abs(y1-y2), abs(x1-x2)) );

    total=f(k,0 , y2-y1);




    }

    printf("Case %d: %lld\n", t+1,total);

    }

    return 0;
}
