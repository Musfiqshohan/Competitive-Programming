#include<bits/stdc++.h>
using namespace std;


int power(int x,int n)
{
    if(n==0) return 1;
    if(n<0) return x*power(x,n+1);
    else
        return x*power(x,n-1);
}

int main()
{
    double x;
    int n;

    scanf("%lf %d",&x,&n);
    int sum=power(x,n);

    x=1*1.0/sum;
     cout<<x<<endl;
    if(n>=0)
        printf("%d\n",sum);
    else
        printf("%f\n",x+0.000000001);

    return 0;

}
