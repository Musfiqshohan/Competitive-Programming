#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define inf 1000099
using namespace std;


int main()
{
    double n,r,R;
    cin>>n>>R>>r;

    double sum= acos(-1)/n;

    sum=sin(sum);

    if((n==1 && r<=R) || sum*(R-r)-r>=0 || fabs(sum*(R-r)-r)<=0.000000001 ) printf("YES\n");
    else printf("NO\n");
}
