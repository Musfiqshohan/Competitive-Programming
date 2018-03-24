#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define inf 100000000000099
using namespace std;

int main()
{
    int test;
    cin>>test;
    while(test--){
    double a,b;
    cin>>a>>b;

    double res ;
  //  printf("%f %f\n",b, (a*a)/4);
    if(b>=a/4)
    res=  (a*b + a*a/8.0 )/(2*a*b);
    else
    res= (2*b*b + b*(a-4*b) + a*b)/(2*a*b);

    if(a==0 && b==0) printf("1\n");
    else if(a==0) printf("0.50000000\n");
    else if(b==0) printf("1\n");
    else
    printf("%0.10f\n",res);

    }
    return 0;
}
