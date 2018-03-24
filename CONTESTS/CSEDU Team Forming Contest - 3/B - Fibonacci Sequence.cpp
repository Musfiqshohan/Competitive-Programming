#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
using namespace std;

ll dp1[20009], dp2[20009],dp3[20009];
bool vis1[20009], vis3[20009], vis2[20009];

//map<ll, ll>dp2;
//map<ll, ll>dp3;
ll fib(ll n)
{
    if(n==0) return 0;
    if(n==1) return 1;

    if(vis1[n+1009]==true) return dp1[n+1009];

    vis1[n+1009]=true;
    return dp1[n+1009]=fib(n-1)+fib(n-2);
    //return fib(n-1)+fib(n-2);
}

ll fib1(ll n, ll F0, ll  F1)
{
    if(n==0) return F0;
    if(n==1) return F1;

    if(vis2[n+1009]==true) return dp2[n+1009];

    vis2[n+1009]=true;
    return dp2[n+1009]=fib1(n-1, F0,F1)+fib1(n-2, F0,F1);
    // return fib1(n-1, F0,F1)+fib1(n-2, F0,F1);

}

ll fib3(ll n, ll F0, ll  F1)
{
    // prllf("%lld %lld %lld\n",n,F0,F1);
    if(n==0) return F0;
    if(n==1) return F1;

    if(vis3[n+1009]==true) return dp3[n+1009];

    vis3[n+1009]=true;
    return dp3[n+1009]=fib3(n+2, F0,F1)- fib3(n+1, F0,F1);
    //return fib3(n+2, F0,F1)- fib3(n+1, F0,F1);

}


int main()
{
//    ms(dp1,-1);
////    ms(dp2,-1);
//    ms(dp3,-1);

    ms(vis1,0);
    ms(vis3,0);
    ms(vis2,0);

    ll i,Fi, j,Fj;
    ll n;
    scanf("%lld %lld %lld %lld %lld",&i,&Fi, &j, &Fj, &n);
    // scanf("%d %d",&j,&i);

    if(i>j)
    {
        swap(i,j);
        swap(Fi,Fj);
    }
    ll t1;
    t1= fib(j-i);

   // cout<<t1<<endl;

    ll t2=fib(j-i+1);

    // dp1.clear();

    ll total=0;
    total= Fj- t2*Fi;

    total/=t1;

    if(n<i)
    {
        printf("%lld\n",fib3(n-i+1,total,Fi));
    }
    else
        printf("%lld\n",fib1(n-i+1, total, Fi ));

    return 0;
}
