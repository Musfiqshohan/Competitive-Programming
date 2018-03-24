#include<bits/stdc++.h>
using namespace std;
int n;
double a[500], b[500];
double f(double x)
{
    double total=0;
    int i;
    for(i=0;i<n-1;i++)
    {
        if(x>b[i])
        total= total- (x-b[i]);
        else
            total+= b[i]-x;
       /// cout<<b[i]<<" "<<total<<endl;
    }

   cout<<x<<" "<<total<<endl;
    return total;

}

double ternary(double  high, double low)
{
    double t=0,mid1,mid2,x,y;

    while(t<=64)
    {
        t++;
        mid1=  (2*low+high)/3;
        mid2= ( low + 2*high)/3;

        x=f(mid1);
        y=f(mid2);

        if(x<y)
        {
            high=mid2;
        }
        else if(x>y)
        {
            low=mid1;
        }
        else
        {
            high=mid1;
            low=mid2;
        }

    }
}
int main()
{
    int i;
    double high,low;
    scanf("%d",&n);
    for(i=0; i<n; i++)
        cin>>a[i];


    for(i=0;i<n-1;i++)
    {
        b[i]=fabs(a[i+1]-a[i]);

    }



    high=10009;
    low=-10009;

  //  f(3.6666667);

    cout<<ternary(high,low)<<endl;


    return 0;
}
