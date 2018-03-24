#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define inf 1000099
using namespace std;
ssssssssssssssxxxxxxxxxxxxxxxxxxxxxxxx
int main()
{
    double n,r,R;
    //scanf("%f %d %d",&n,&R,&r);
    cin>>n>>R>>r;
    double sum= r/(R-r);

    sum=asin(sum)*2;

    //cout<<sum<<endl;

    cout<<-(n*sum) <<" "<<2*acos(-1)<<endl;
    if((n==1 && r==R) || fabs(2*acos(-1)-(n*sum))>=0.000001) printf("YES\n");
    else printf("NO\n");

    return 0;
}
