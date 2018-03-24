#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

struct info
{
    int l,r;
    double v;
};


bool cmp(info a, info b)
{
    if(a.l==b.l)
        return a.r<b.r;
    return a.l<b.l;

}


vector<info>vec;

int main()
{
    int X;
    int n,l,r;
    double vx,v,V;

    cin>>n>>X>>V;

    for(int i=0; i<n; i++)
    {
        cin>>l>>r>>vx;

        if(i==0)
            vec.push_back({0,l,0});
        if(i>0)
        {
            int ll=vec.size();
            vec.push_back({vec[ll-1].r, l, 0});
        }
        vec.push_back({l,r,vx});


        if(i==n-1)
            vec.push_back({r,X,0});
    }

    sort(vec.begin(),vec.end(),cmp);

    double rhs=0,lhs=0;
    for(int i=0; i<vec.size(); i++)
    {

        l=vec[i].l, r=vec[i].r, v=vec[i].v;

        lhs+=(r-l);

        rhs= rhs+(-v/V)*(r-l);
    }

    double rat=rhs/lhs;

    if(rat>1)
    {
        printf("Too hard\n");
        return 0;
    }

    double ang=acos(rat);
    double res=lhs/(V*sin(ang));

    double lim=(2*X)/V;


    if(res>lim)
        printf("Too hard\n");
    else
    {
        cout<<fixed<<setprecision(3)<<res<<endl;
    }


//    double tot=0;
//    for(int i=0;i<vec.size();i++)
//    {
//        l=vec[i].l, r=vec[i].r, v=vec[i].v;
//
//        //cout<<"->"<<l<<" "<<r<<" "<<v<<endl;
//
//        double res=0;
//        res=(r-l)/(V*sin(ang));
//
//        res*= (v*cos(ang)+v);
//        tot+=res;
//        //cout<<"res="<<res<< " tot="<<tot<<endl;
//    }


    return 0;
}
