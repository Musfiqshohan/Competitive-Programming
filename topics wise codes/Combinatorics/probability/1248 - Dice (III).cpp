#include<bits/stdc++.h>
#define ll long long
using namespace std;


double m,cnt=0;
double f(double n)
{
    if(n==0) return 0;
    return f(n-1)+ m/n;

}

int main()
{
    int tt=0,test;
    cin>>test;
    while(tt<test)
    {
        cin>>m;

        printf("Case %d: %.10f\n",++tt, f(m));
    }
}
