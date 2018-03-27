#include<bits/stdc++.h>
#define pi acos(-1)
#define ll long long
using namespace std;

double Calculate_distance(double x1,double y1, double x2, double y2)
{
    double d= (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
    return sqrt(d);
}

double Cosine_Rule(double a, double b, double c)
{
    return (a*a + b*b - c*c)/(2.0*a*b);
}

int check(double theta, double angle)
{
    double div=theta/angle;
    int div2= round(div);

    if( fabs(div-div2)<=0.00000001) return 1;

    return 0;
}

double calculate_area_polygon(int n, double angle, double thetaB, double b)
{
    //double full= (n-2)*180;
  //  cout<<angle<<" "<<full<<" "<<
    double side=( sin(angle)/sin(thetaB) )*b;
   //cout<<"side="<<side<<endl;

  //  double nn=n;
    double ap= 2*tan(pi/n);
    ap= side/ap;

 ///  printf("side=%.8f ap=%.8f  angle= %.6f\n",side, ap, 2*tan(pi/n));

    return 0.5 * side * n * ap;

}

int main()
{
    double x1,y1,x2,y2,x3,y3;

    cin>>x1>>y1>>x2>>y2>>x3>>y3;

    double a,b,c;
    c= Calculate_distance(x1,y1,x2,y2);
    a= Calculate_distance(x2,y2,x3,y3);
    b= Calculate_distance(x1,y1,x3,y3);

   // cout<<a<<" "<<b<<" "<<c<<endl;

    double thetaA,thetaB, thetaC;

    thetaA=Cosine_Rule(b,c,a);
    thetaA=acos(thetaA)*180/pi;

    thetaB=Cosine_Rule(c,a,b);
    thetaB=acos(thetaB)*180/pi;

    thetaC=Cosine_Rule(a,b,c);
    thetaC=acos(thetaC)*180/pi;

   //  cout<<thetaA<<" "<<thetaB<<" "<<thetaC<<endl;

    double angle=0;
    int i;
    for( i=3; i<=101; i++)
    {
        angle= (i-2)*(180);
        angle= angle/(i*(i-2));

       // cout<<"->"<<angle<<endl;

//        int sum= check(thetaA,angle) +  check(thetaB,angle) + check(thetaC,angle);
//        cout<<sum<<endl;

        if(check(thetaA,angle)==true && check(thetaB,angle)==true && check(thetaC,angle)==true)
            break;


    }


  //  cout<<i<<" "<<angle<<" "<<thetaB<<" "<<b<<endl;

    double area= calculate_area_polygon(i,angle,thetaB,b);

    printf("%.8f\n",area);


}
