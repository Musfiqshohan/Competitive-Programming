#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;


struct info
{
    int l,r;
    double v;
};

vector<info>vec;

int X;
double V;




double f(double angle)
{

    double curpos=0, tottime=0;;

    for(int i=0;i<vec.size();i++)
    {


        //cout<<vec[i].l<< " ->"<<vec[i].r<<"-> "<<vec[i].v<<endl;

       double vy,vx;

        vy= V* sin(angle);
        vx= V*cos(angle)+vec[i].v;

        double  t=(vec[i].r-vec[i].l)/vy;

        //cout<<"time ="<<t<<" vx ="<<vx<<" vy ="<<vy<<endl;
        tottime+=t;

        double pos=vx*t;

        curpos+=pos;
       // cout<<"curpos =" <<curpos<<" pos="<<pos<<endl;
    }


    cout<<"time="<<tottime<<" + curpos="<<curpos<<endl;

    if(fabs(curpos)<2)  ///here's a problem
        return tottime;
    else return 1000000;   /// here's a problem

}



bool cmp(info a, info b)
{
    if(a.l==b.l)
        return a.r<b.r;
    return a.l<b.l;

}


int main()
{
  //  cout<<sin(acos(-1)/2)<<endl;

    int n,l , r;

    double vx;

    cin>>n>>X>>V;

    for(int i=0; i<n; i++)
    {
        cin>>l>>r>>vx;

        if(i==0)
        {
            vec.push_back({0,l,0});
           // printf("->%d %d\n",0,l);
        }

        if(i>0)
        {
            int ll=vec.size();
            vec.push_back({vec[ll-1].r, l, 0});
          //  printf("xi=%d->%d %d\n",i,vec[ll-1].r, l);
        }

        vec.push_back({l,r,vx});
       // printf("->%d %d\n",l,r);

    }


  //  return 0;
    sort(vec.begin(),vec.end(),cmp);


//    for(int i=0;i<vec.size();i++)
//    {
//        cout<<vec[i].l<< " ->"<<vec[i].r<<" "<<vec[i].v<<endl;
//    }
//
//    return 0;


    double pi=acos(-1);
    double lo=pi/2, hi= pi ,mid1,mid2 ;   /// here is a problem
    int cnt=32;



   // cout<<f(pi/2)<<endl;
    while(cnt--)
    {
        mid1=(hi+2*lo)/3;
        mid2=(2*hi+lo)/3;

        double t1=f(mid1);
        double t2=f(mid2);

        cout<<"mid1 ="<<mid1<<" mid2 ="<<mid2<<endl;

        if(t1<t2)
        hi=mid2;
        else lo=mid1;

    }



    cout<<f(mid1)<<endl;



    return 0;
}
