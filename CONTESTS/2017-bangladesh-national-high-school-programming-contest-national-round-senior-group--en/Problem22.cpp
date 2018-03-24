#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,p,r,Total;
int main()
{
    int t=0,test;
    scanf("%d",&test);

    while(t<test){

    //scanf("%f %f %f",&p,&r,&Total);
    cin>>p>>r>>Total;

    double num= (p+Total);

    cout<<num<<endl;
    num/=p;

    cout<<num<<endl;

    double x= (r*1.0)/100;
    x++;
    int cnt=0;
    while(num>=1)
    {
       // num=num/x;
        cout<<num/x<<" "<<x<<endl;
        cnt++;

    }

    printf("%d\n",cnt);

    }



}
