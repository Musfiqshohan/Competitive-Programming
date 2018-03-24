#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define i64 long long
#define pii pair<int,int>
#define inf 10000000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;


double Dist(int ax, int ay, int bx, int by)
{
    double x,y;
    x=(ax-bx)*(ax-bx);
    y=(ay-by)*(ay-by);

    return sqrt(x+y);

}

double dist1[100009];

pii ara[100009];

bool isT[100009];


int main()
{

	//cout<<Dist(3,1,1,1)<<endl;
    int ax,ay, bx,by,tx,ty;
    cin>>ax>>ay>>bx>>by>>tx>>ty;

    int n,x,y;
    cin>>n;

    double mn11,mn12,mn21,mn22, mn11x,mn12x,mn21x,mn22x;
    int mn11i,mn12i,mn21i,mn22i;
    mn11=mn12=mn21=mn22=inf;

    double d1,d2,d3;
    for(int i=0; i<n; i++)
    {
        cin>>x>>y;
        ara[i]={x,y};
        d1=Dist(tx,ty,x,y);
        dist1[i]=d1;
    }


    for(int i=0; i<n; i++)
    {
        d2=Dist(ax,ay,ara[i].first, ara[i].second) +dist1[i];
        d3=Dist(bx,by,ara[i].first, ara[i].second) +dist1[i];

    //    printf("%d,%d ->%d,%d=%f  %d,%d->%d,%d=%f\n",ax,ay,ara[i].first,ara[i].second, d2, bx,by,ara[i].first,ara[i].second,d3);



        if( d2-dist1[i]*2<=mn11)
        {
            mn12=mn11;
            mn12x=mn11x;
            mn12i=mn11i;

            mn11=d2-dist1[i]*2;
            mn11x=d2;
            mn11i=i;
        }

        else if(d2-dist1[i]*2 <mn12)
        {
            mn12=d2-dist1[i]*2;
            mn12x=d2;
            mn12i=i;
        }

        if(d3-dist1[i]*2<mn21)
        {
            mn22=mn21;
            mn22x=mn21x;
            mn22i=mn21i;

            mn21=d3-dist1[i]*2;
            mn21x=d3;
            mn21i=i;
        }
        else if(d3-dist1[i]*2<mn22)
        {
            mn22=d3-dist1[i]*2;
            mn22x=d3;
            mn22i=i;
        }

    }

    double tot=0;
    //sort(dist1,dist1+n,cmp);


    //cout<<mn11<<","<<mn11i<<" "<<mn12<<","<<mn12i<<" "<<mn21<<","<<mn21i<<" "<<mn22<<","<<mn22i<<endl;
    if(mn11i!=mn21i)
    {
        tot=mn11x+mn21x;
        isT[mn11i]=isT[mn21i]=1;
    }
    else
    {
        if(mn11<mn21)
        {
            tot=mn11x+mn22x;
            isT[mn11i]=isT[mn22i]=1;
        }
        else
        {
            tot=mn12x+mn21x;
            isT[mn12i]=isT[mn21i]=1;
        }
    }

  //  cout<<tot<<endl;

    for(int i=0; i<n; i++)
    {
        if(isT[i]==0)
        {
        //	printf("i=%d\n",i);
            tot+=dist1[i]*2;
        }
    }


    printf("%.10f\n",tot);
}

