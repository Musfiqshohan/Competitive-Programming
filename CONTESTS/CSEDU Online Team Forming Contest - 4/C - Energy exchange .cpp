#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
using namespace std;

double ara[10009];
 double n,k;
double f(double avg)
{
    double t1=0,t2=0;

    //cout<<"ho"<<avg<<endl;
    for(int i=0;i<n;i++)
    {
        if(ara[i]>avg)
        t1+= (ara[i]-avg);
        else
        t2+= (avg-ara[i]);
    }

    double last= t1*(1-k/100);
  //  printf("%f %f %f\n",t1,t2,last);

    if(last>=t2)
        return 1;
    else
        return -1;


}

int main()
{

    cin>>n>>k;

    double mx=0;
    for(int i=0;i<n;i++)
    {
        cin>>ara[i];
        mx= max(mx,ara[i]);
    }

    double low=0,high=mx,mid;

    int cnt=0;

    //f(2);
    while(cnt++<32)
    {
        mid=(low+high)/2;

        if(f(mid)>0)
            low=mid;
        else
            high=mid;
    }

    printf("%.8f\n",mid);

    return 0;
}
