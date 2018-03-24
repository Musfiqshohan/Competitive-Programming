#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<ll,ll>
#define inf 100000000000
using namespace std;

int ara[11];

int f(int v)
{
    if(v<0) return -10000;
    if(v==0) return 0;
    int t1=0;

    int mx= -100000;
    for(int i=9;i>=1;i--)
    {
        t1= i*10+ f(v-ara[i]);

        mx= max(mx,t1);
    }

    return mx;

}

int main()
{
    int v;
    scanf("%d",&v);

    for(int i=1;i<=9;i++) scanf("%d",&ara[i]);

    cout<<f(v)<<endl;

    return 0;
}
