#include<bits/stdc++.h>
#define ll long long
#define pi acos(-1)
using namespace std;

int main()
{


    int t=0,test;
    cin>>test;
    while(t<test){

    double a,b;
    scanf("%lf : %lf",&a,&b);

    double theta= 180- (90-atan(b/a))*2;

    double x= (2*a)+ sqrt( a*a + b*b )*theta;
    x= 400/x;

    //cout<<setprecision(12)<<a*x<<" "<<b*x<<endl;
    printf("Case %d: %.10f %.10f\n",++t,a*x, b*x);

    }

}
