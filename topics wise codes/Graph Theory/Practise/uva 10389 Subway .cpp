///https://uva.onlinejudge.org/external/103/10389.pdf
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

double g[250][250];
struct Point
{
    int x,y;
} p[250];

double dist(Point a, Point b)
{
    double res=  (a.x-b.x)*(a.x-b.x)  + (a.y-b.y)*(a.y-b.y);
    return sqrt(res);
}

int main()
{
    Point src, dest;
    scanf("%d %d %d %d",&src.x, &src.y, &dest.x, &dest.y);
    getchar();


    p[0]=src, p[1]=dest;


    string line;
    int n=2;
    while(getline(cin,line))
    {
        if(line=="") break;

        stringstream sin;
        sin<<line;

        sin>>p[n].x>>p[n].y,n++;
       //  cout<<p[n].x<<" -> "<<p[n].y<<endl;
        while(sin>>p[n].x>>p[n].y)
        {
            cout<<p[n].x<<" "<<p[n].y<<endl;
            if(p[n].x<0) {  break;  }


            g[n-1][n]= dist(p[n-1], p[n]);
            g[n][n-1]=g[n-1][n];
            n++;

        }

    }




//
//    for(int i=0; i<n; i++)
//    {
//        for(int j=0; j<n; j++)
//        {
//            if(g[i][j]==0)
//            {
//                g[i][j]= dist(p[i], p[j]);
//                g[i][j]= (g[i][j]*60)/1000;
//            }
//            else
//                g[i][j]= (g[i][j]*60)/(4*1000);
//        }
//    }
//
//    for(int k=0; k<n; k++)
//        for(int i=0; i<n; i++)
//            for(int j=0; j<n; j++)
//                g[i][j]= min (g[i][j],  g[i][k]+ g[k][j]);
//
//
//    printf("%.0lf\n",g[0][1]);





    return 0;
}
