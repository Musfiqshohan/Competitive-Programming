#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
using namespace std;

int main()
{
    int a,b;
    scanf("%d %d",&a,&b);

    int t1= 40 + b*2;
    int t2= 40 + 39*2 + (a-40)*2  +1 ;

    printf("%d\n", max(t1,t2));
}
