#include<bits/stdc++.h>
#define ms(a,b) memset((a),(b),sizeof(a))
#define llu unsigned long long
#define pii pair<double,double>
#define inf 1000000000000.0
using namespace std;


struct point
{
    double x,y;
};
double dist(point a, point b)
{
    double res= (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
    res= sqrt(res);
    return res;
}


double f(point a, point b, double mid)
{
    double num=a.y-b.y;
    double den=a.x-b.x;

    double res=num/den;
    res*=(mid-a.x);

    res+=a.y;
    return res;

}


int main()
{
    double R,x1,y1,x2,y2;
    cin>>R>>x1>>y1>>x2>>y2;

    double l=dist({x1,y1}, {x2,y2});

    double dif=max(0.0,R-l);


    double r=R-dif;

    if(fabs(r-R)<0.0000000001)
    {
        cout<<x1<<" "<<y1<<" "<<R<<endl;
        return 0;
    }


    double low,high,mid,xx,yy;

    if(fabs(x1-x2)<0.000000001)
    {
        xx=x1;

        if(y2>y1)
        {
            yy=y1-dif;
        }
        else
        {
            yy=y1+dif;
        }
    }
    else if(x1<x2)
    {
        high=x2;
        low=-inf;

        int cnt=100;
        while(cnt--)
        {
            mid=(low+high)/2;

            double y=f({x1,y1}, {x2,y2}, mid);
            double dis=dist({mid,y}, {x2,y2});
            if(dis>=r)
                low=mid;
            else high=mid;
        }
        xx=mid;
        yy= f({x1,y1}, {x2,y2},mid);

    }
    else if(x2<x1)
    {
        low=x2;
        high=inf;

        int cnt=100;
        while(cnt--)
        {
            mid=(low+high)/2;

            double y=f({x1,y1}, {x2,y2}, mid);
            printf("x=%.2lf y=%.2lf r=%.2lf\n",mid,y,r);
            double dis=dist({mid,y}, {x2,y2});

            if(dis>=r)
                high=mid;
            else low=mid;
        }

        xx=mid;
        yy= f({x1,y1}, {x2,y2},mid);
    }



    cout<<xx<<" "<<yy<<" "<<r<<endl;


}
