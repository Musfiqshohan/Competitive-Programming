#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,p,r,Total;
double pow1(double x, ll n)
{
    if(n==0) return 1.0;
    else if(n%2==0)
    {
        double ret= pow1(x,n/2);
        return ret*ret;
    }

    return x* pow1(x,n-1);
}

ll f(ll year)
{
   // printf("year=%lld\n",year);
    double num= pow1(1+ (r*1.0)/100, year);
    cout<<num<<endl;
    num= num*p ;

    return (ll)num;
}
int main()
{
    int t=0,test;
    scanf("%d",&test);

    while(t<test){

    scanf("%lld %lld %lld",&p,&r,&Total);


    ll cnt, low, high, mid;
    cnt=0;
    low=0;
    high=100;
    while(cnt<=100)
    {
        cnt++;
        mid= low+ (high-low)/2;

      //  printf("%lld\n",mid);
        if(f(mid)<Total)
            low=mid+1;

        else high=mid-1;
    }

    printf("Case %d: %lld\n",++t,mid);

    }
    return 0;

}
