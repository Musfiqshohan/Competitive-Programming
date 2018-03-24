///https://www.codechef.com/FEB18/problems/CARPTUN
#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define i64 long long
#define pii pair<int,int>
#define inf 10000000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int ara[100009];
int main()
{

    int tt;
    cin>>tt;

    while(tt--)
    {
        int n,c,d,s;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            scanf("%d",&ara[i]);
        }

        cin>>c>>d>>s;

        i64 mx=0;
        for(int i=0; i<n; i++)
        {
            mx=max(mx,(i64)ara[i]);
        }

        i64 res=mx*(c-1);
        cout<<res<<endl;


    }


    return 0;
}
