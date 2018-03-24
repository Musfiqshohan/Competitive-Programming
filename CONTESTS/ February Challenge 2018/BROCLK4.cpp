#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define i64 long long
#define pii pair<i64,i64>
#define inf 100000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
#define rep(i,n) for(i64 i=0;i<n;i++)
#define mod 1000000007
using namespace std;


i64 AddCos(i64 x, i64 y)
{
    i64 res1,res2,res3,res4,ret;

    res1= (x*y)%mod;

    res2= ((1-(x*x)%mod)+mod)%mod;


    res3= ((1-(y*y)%mod)+mod)%mod;


    res4=(res2*res3);

    res4=sqrt(res4);
    printf("res2=%lld res3=%lld res4=%lld\n",res2,res3,res4);

    ret= ((res1-res4)+mod)%mod;

   //  printf("%lld %lld , %lld %lld\n",res1.p,res1.q, res4.p,res4.q);

    return ret;

}


i64 f(i64 n, i64 w)
{
    if(n==1)
        return w;
    if(n==0){
       // printf("I got you\n");
    return {0};
    }

    i64 ret,r;
    if(n&1)
    {
        r=f(n-1,w);
        ret=AddCos(r,w);
    }
    else
    {
        r=f(n/2,w);
        ret=AddCos(r,r);
    }

   //   printf("n=%d ->%lld/%lld\n",n,ret.p,ret.q);

    return ret;
}



i64 pow1(i64 x,i64 n)
{
    if(n==0) return 1;

    if(n%2==0)
    {
        i64 ret=pow1(x,n/2);
        return  (ret*ret)%mod;
    }
    return (x*pow1(x,n-1))%mod;
}

int main()
{


    int tt;
    cin>>tt;

    while(tt--)
    {

        i64 L,d,t;
        cin>>L>>d>>t;
        //t=3;

        if(t==0)
        {
            printf("%lld\n",L);
            continue;
        }

        i64 para= (d* pow1(L,mod-2))%mod;

        i64 ret= f(t,para);


        i64 tot;
        ret=(ret*L)%mod;


      //  double res=(ret.p*1.0)/ret.q;
       // cout<<tot<<" "<<res<<endl;
   //    printf("%lld %lld %lld=",L,d,t);
         cout<<ret<<endl;
        // cout<<res<<endl;



    }

}




