#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<int,int>
#define inf 100000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

struct Point
{
    int x,y;
};

bool cmp1(Point a, Point b)
{
    return a.x<b.x;
}

bool cmp2(Point a, Point b)
{
    return a.y<b.y;
}

double dist(Point a, Point b)
{
    return sqrt( (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));

}


double stripClosest(Point strip[], double d, int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n && (strip[j].y - strip[i].y) <d; j++)
        {
            d=min(d,dist(strip[i], strip[j]));

        }
    }

    return d;
}

double bruteForce(Point Px[], int n)
{
    double mini=FLT_MAX;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            mini= min(mini,dist(Px[i],Px[j]))
            ;
        }
    }

    return mini;
}


double closestUtil(Point Px[], Point Py[], int n)
{
    if(n<=3)
        return bruteForce(Px,n);


    int mid= n/2;

    Point midpoint =Px[mid];

    Point Pyl[mid+1], Pyr[mid+1];

    int l=0,r=0;
    for(int i=0; i<n; i++)
    {
        if(Py[i].x<=midpoint.x)
            Pyl[l++]=Py[i];
        else Pyr[r++]=Py[i];

    }


    double d1= closestUtil(Px,Pyl,mid);
    double d2= closestUtil(Px+mid,Pyr, n-mid);

    double d= min(d1,d2);

    Point strip[n];
    int s=0;
    rep(i,n)
    {
        if(fabs(Px[i].x-midpoint.x)<d)
            strip[s++]=Px[i];
    }

    double ret= min(d, stripClosest(strip, d,n));


}

double closest(Point P[], int n)
{
    Point Px[n],Py[n];

    rep(i,n)
    {
        Px[i]=P[i];
        Py[i]=P[i];
    }

    sort(Px,Px+n,cmp1);
    sort(Py,Py+n,cmp2);


    return closestUtil(Px,Py,n);


}




int main()
{
    Point P[]= {{2,3}, {12,30}, {40,50},{5, 1}, {12, 10}, {3, 4} };
    int n= sizeof(P)/ sizeof(P[0]);


    cout<<"The smallest distance :"<<closest(P,n)<<endl;
    return 0;
}
