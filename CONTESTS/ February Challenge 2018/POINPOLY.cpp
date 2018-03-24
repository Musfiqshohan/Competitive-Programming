///https://www.codechef.com/FEB18/problems/POINPOLY

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

struct point
{
    int x,y;
} ara[5*100009];


vector<point>vec,answer;


float sign (point p1, point p2, point p3)
{
    return (p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y);
}

bool PointInTriangle (point pt, point v1, point v2, point v3)
{
    bool b1, b2, b3;

    b1 = sign(pt, v1, v2) < 0.0f;
    b2 = sign(pt, v2, v3) < 0.0f;
    b3 = sign(pt, v3, v1) < 0.0f;

    return ((b1 == b2) && (b2 == b3));
}

void find_P(point root, point slope, point a, point b, point c)
{

    point p=root;
    while(PointInTriangle(p,a,b,c)==true)
    {
        printf("%d %d\n",p.x,p.y);
        answer.push_back(p);
        p.x+=slope.x;
        p.y+=slope.y;
    }

    p=root;
    while(PointInTriangle(p,a,b,c)==true)
    {
        printf("%d %d\n",p.x,p.y);
        answer.push_back(p);
        p.x-=slope.x;
        p.y-=slope.y;
    }



}



void make_list(point a, point b, point c) /// base ab
{
    if(a.x>b.x)
        swap(a,b);

    int x=b.x-a.x;
    int y=b.y-a.y;

    x/=__gcd(x,y);
    y/=__gcd(x,y);

    point slope= {y,x};
    point perslope= {-x,y};

    printf("s=%d,%d p=%d,%d\n",slope.x, slope.y, perslope.x, perslope.y);



    point p=a;
    vector<point>lst;
    while(p.x<=b.x)
    {
        lst.push_back(p);
        p.x+=x;
        p.y+=y;
    }

    for(int i=0; i<lst.size(); i++)
    {

        printf("->%d %d perslope=%d %d\n",lst[i].x, lst[i].y,perslope.x,perslope.y);
        find_P(lst[i], perslope, a,b,c);
    }




}

void make_tri(point a, point b, point c) ///ab base
{






}

int main()
{


    int a,b,c;

    make_list({0,0},{4,0},{2,2});
    //find_P({2,0}, {0,0},{4,0},{2,2});
    return 0;


    int n;
    scanf("%d",&n);

    for(int i=0; i<n; i++)
    {
        scanf("%d %d",&ara[i].x,&ara[i].y);
    }





    for(int i=1; i<=n; i++)
        vec.push_back(ara[i]);

    vector<point>temp;
    int tot=0;
    while(vec.size()>=3)
    {
        for(int i=0; i<vec.size(); i+=2)
        {
            if(i+2<vec.size())
                make_tri(vec[i],vec[i+1],vec[i+2]);
            temp.push_back(vec[i]);
        }

        vec.clear();
        vec=temp;
        temp.clear();
    }







}
