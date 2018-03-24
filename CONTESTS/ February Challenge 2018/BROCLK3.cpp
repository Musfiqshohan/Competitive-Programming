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


struct fii
{
    i64 p,q;
};


fii add(fii a, fii b)
{
    fii ret;
    i64 r1,r2;
    r1= (a.p*b.q)%mod;
    r2= (a.q*b.p)%mod;

    ret.p= ((r1+r2)%mod)%mod;
    ret.q= (a.q*b.q)%mod;
    return ret;
}

fii mul(fii a, fii b)
{
    fii ret;
    ret.p=((a.p*b.p)%mod)%mod;
    ret.q=((a.q*b.q)%mod)%mod;
    return ret;
}

fii AddCos(fii x, fii y)
{
    fii res1,res2,res3,res4,ret;

    res1= mul(x,y);

    res2= mul({-1,1}, mul(x,x));
    res2= add({1,1}, res2);

    res3= mul({-1,1}, mul(y,y));
    res3= add({1,1}, res3);

    res4=mul(res2,res3);

    res4.p=sqrt(res4.p);
    res4.q=sqrt(res4.q);

    res4= mul({-1,1},res4);
    ret= add(res1, res4);

   //  printf("%lld %lld , %lld %lld\n",res1.p,res1.q, res4.p,res4.q);

    return ret;

}


fii f(i64 n, fii w)
{
    if(n==1)
        return w;
    if(n==0){
       // printf("I got you\n");
    return {0,0};
    }

    fii ret,r;
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

//    fii rett=AddCos({4,8},{4,8});
//    cout<<rett.p<<" "<<rett.q<<endl;
//
//    return 0;
  //  out("brk1.txt");
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

        i64 gcd=__gcd(L,d);

        fii w= {d/gcd,L/gcd};

        fii ret= f(t,w);


        gcd=__gcd(ret.p,ret.q);
        ret.p/=gcd;
        ret.q/=gcd;

       // cout<<ret.p<<" "<<ret.q<<endl;

        i64 tot;
        ret.p=((ret.p*L)+mod)%mod;
        tot= pow1(ret.q,mod-2);

       // cout<<ret.p<<" "<<tot<<endl;

        tot= ((ret.p*tot)%mod+mod)%mod;

        double res=(ret.p*1.0)/ret.q;
       // cout<<tot<<" "<<res<<endl;
   //    printf("%lld %lld %lld=",L,d,t);
         cout<<tot<<endl;
        // cout<<res<<endl;



    }

}



