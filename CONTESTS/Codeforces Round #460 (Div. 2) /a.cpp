#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<int,int>
#define inf 100000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int main()
{

    int n,m,a,b;
    cin>>n>>m;

    double mn=100000000;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;

        mn= min(mn, (a*1.0)/b *m );

    }

    printf("%.10lf\n",mn);

}

