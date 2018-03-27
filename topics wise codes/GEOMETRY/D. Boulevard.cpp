#include<bits/stdc++.h>
#include<iostream>
#include<complex>
using namespace std;
typedef complex<double>vctor;
#define rl real()
#define img imag()
#define ll long long
struct point{
    ll x,y;
};

struct info
{
    ll time,start,endd;
};
info data[2000];
int meet[2000];


int blackbox(point st, point endd, point q)
{
    vctor a(st.x,st.y);
    vctor b(endd.x, endd.y);
    vctor c(q.x,q.y);

    ll num= (conj(b-a)*(c-a)).img;
     if(num>0) return 1;
    else if(num<0) return -1;
    else return 0;

}
int check_in_segment(point st, point endd, point q)
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

int intersect(point pos, point inf, point con1, point con2)
{
    if(blackbox(pos,inf,con1)== -1* blackbox(pos,inf,con2)  && blackbox(con1,con2,pos)==-1*blackbox(con1,con2,inf) )
        {
           //printf("Fuck1\n");
            return 1;

        }

  //  if( (  &&  )  || (   ) )

    if( ( blackbox(pos,inf,con1)==0 && check_in_segment(pos,inf,con1)==1 )  || ( blackbox(pos,inf,con2)==0 && check_in_segment(pos,inf,con2)==1 ) || ( blackbox(con1,con2,pos)==0 && check_in_segment(con1,con2,pos)==1 )  ||
        (blackbox(con1,con2,inf)==0 && check_in_segment(con1,con2,inf)==1) )
        {
          //  printf("Fuck2\n");
            return 1;


        }

//cout<<blackbox(pos,inf,con1)<<" "<<blackbox(pos,inf,con2)<<" "<<blackbox(con1,con2,pos)<<" "<<blackbox(con1,con2,inf)<<endl;
    return 0;

}

int main()
{
    ll n,i,j;
    scanf("%lld",&n);

    for(i=0;i<n;i++)
    {
        scanf("%lld %lld %lld",&data[i].time, &data[i].start, &data[i].endd);
    }




    for(i=0;i<n;i++)
    {
        point pos={data[i].time,data[i].start};
        point inf={data[i].time+(abs(data[i].endd-data[i].start)+0),data[i].endd };
        ll cnt=0;
        for(j=i+1;j<n;j++)
        {
            if(i==j) continue;

            point con1={data[j].time,data[j].start};
            point con2={data[j].time+(abs(data[j].endd-data[j].start)+0),data[j].endd };

            if(intersect(pos,inf,con1,con2)==1)
               {
                    meet[i]++;
                    meet[j]++;

               }
        }

        //printf("%d ",cnt);
    }

    for(i=0;i<n;i++) printf("%d ",meet[i]);



    return 0;
}
