#include<bits/stdc++.h>
#define i64 long long
#define pii pair<i64,i64>
using namespace std;


struct Point
{
    i64 x,y;
} p0;



Point nextToTop(stack<Point>&S)
{
    Point p=S.top();
    S.pop();
    Point res= S.top();
    S.push(p);

    return res;
}


pii calc_dist(Point p1, Point p2)
{
    i64 dx=abs(p1.x-p2.x);
    i64 dy=abs(p1.y-p2.y);

    i64 mn=min(dx,dy);
    i64 mx=max(dx,dy);

    pii ret= {mx-mn, mn};

    return ret;
}

int orientation(Point p, Point q, Point r)
{
    i64 res= (q.y-p.y)*(r.x-q.x) - (r.y-q.y)*(q.x-p.x);

    if(res==0) return 0;

    return (res>0)? 1:2 ;/// cw or ccw
}


bool compare(Point a, Point b)
{
    int o=orientation(p0,a,b);

    if(o==0)
    {
        pii r1= calc_dist(p0, a);
        pii r2= calc_dist(p0, b);

        double t1=r1.first+ r1.second*sqrt(2.0);
        double t2=r2.first+ r2.second*sqrt(2.0);

        if(t1<t2)
            return 1;
        else return 0;

    }

    if(o==2)
        return true;
    else return false;
}


pii convexHull(Point points[], int n)
{


    int miny=1e9, mini=0;

    for(int i=0; i<n; i++)
    {
        int y=points[i].y;
        if((y<miny) || (y==miny && points[i].x < points[mini].x))
        {
            miny=y;
            mini=i;
        }
    }

    swap(points[0],points[mini]);

    p0=points[0];

    sort(points+1,points+n, compare);

    int m=1;


    for(int i=1; i<n; i++)
    {
        while(i<n-1 && orientation(p0,points[i],points[i+1])==0)
            i++;

        points[m]=points[i];
        m++;
    }

    if(m<3)
    {
        if(m==1)
        {
            return {1,0};
        }


        pii rr= calc_dist(points[0], points[1]);
        return {rr.first*2, rr.second*2};
    }
    stack<Point>S;

    S.push(points[0]);
    S.push(points[1]);
    S.push(points[2]);

    for(int i=3; i<m; i++)
    {
        while(orientation(nextToTop(S),S.top(), points[i])!=2)
            S.pop();
        S.push(points[i]);
    }

    pii res= {0,0};

    //Point last=S.top();
    S.push(p0);

    while(1)
    {
        Point p1=S.top();
        S.pop();
        if(S.empty()==1) break;


        Point p2=S.top();
        //  printf("%d,%d  %d,%d\n",p1.x,p1.y, p2.x, p2.y);
        pii r=calc_dist(p1,p2);

        res= {res.first+r.first, res.second+r.second};
    }





    return res;


}

Point points[10009];

int main()
{




    while(1)
    {
        int n;
        cin>>n;
        if(n==0) break;





        for(int i=0; i<n; i++)
        {
            scanf("%lld %lld",&points[i].x, &points[i].y);
        }

        pii res= convexHull(points,n);

        cout<<res.first<<" "<<res.second<<endl;

        memset(points,0,sizeof points);

    }

}
