#include <iostream>
#include <cassert>
#define ll long long
#define mod 10007
using namespace std;

int a,b,c;
int f(int n)
{
    if(n<=2) return 0;

    return a*f(n-1) + b*f(n-3) + c;

}

/// 1 2 3

int main()
{
    int  n;
    a=1,b=2,c=3;
    cin>>n;

    cout<<f(n)<<endl;

}
