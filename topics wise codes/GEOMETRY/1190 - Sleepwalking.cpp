#include<bits/stdc++.h>
#include<iostream>
#include<complex>
#define ll long long
using namespace std;
typedef complex<double> vctor ;
#define rl real()
#define img imag()
struct point
{
    ll x,y;
};


ll Black_box(point st, point endd, point q)
{
    vctor a(st.x,st.y);
    vctor b(endd.x, endd.y);
    vctor c(q.x, q.y);

    ll num=  (conj(b-a)*(c-a)).img;

    if(num>0) return 1;
    else if(num<0) return -1;
    else return 0;


}


ll intersect(point pos, point inf, point con1, point con2)
{

    if( (Black_box(pos,inf,con1) == -1*Black_box(pos,inf,con2))  && (Black_box(con1,con2,pos)== -1*Black_box(con1,con2,inf)) )
        return 1;

    return 0;
}


ll check(point st, point endd, point q)
{
    ll mnx,mny,mxx,mxy;
    mnx=min(st.x, endd.x);
    mny=min(st.y, endd.y);

    mxx= max(st.x, endd.x);
    mxy= max(st.y, endd.y);

    if(q.x>=mnx && q.x<=mxx && q.y>=mny && q.y<=mxy )
        return 1;
    else return 0;

}


int main()
{
//    cout<<Black_box({0,0}, {5,0}, {2,0})<<endl;
//    cout<<intersect( {5,0} , {100000,100001} , {0,0}, {10,0} )<<endl;
    ll t=0,test;
    cin>>test;

    while(t<test)
    {

        printf("Case %lld:\n",++t);
        point p[200];

        point pos,inf;


        ll n,i,total=0;
        scanf("%lld",&n);

        for(i=0; i<n; i++)
            scanf("%lld %lld",&p[i].x,&p[i].y);


        ll query;
        scanf("%lld",&query);

        for(ll k=0; k<query; k++)
        {
            scanf("%lld %lld",&pos.x, &pos.y);

            inf.x= 1000000+ pos.x;
            inf.y= 1000001 + pos.y;


            total=0;
            for(i=0; i<n-1; i++)
            {
                if(Black_box( p[i], p[i+1],pos)==0  && check(p[i],p[i+1],pos)==1 )
                {
                    total=1;
                    break;
                }
                total+=intersect(pos,inf, p[i], p[i+1]);
            }


            if(i==n-1){
            if(Black_box( p[0], p[n-1],pos)==0  && check(p[0],p[n-1],pos)==1 )
                total=1;
            else
                total+=intersect(pos,inf, p[0], p[n-1]);
            }


            if(total%2==1) printf("Yes\n");
            else printf("No\n");
        }

    }

    return 0;
}
