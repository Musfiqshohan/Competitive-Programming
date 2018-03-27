#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define i64 long long
#define pii pair<i64,i64>
#define INF 1000000000000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
#define rep(i,n) for(i64 i=0;i<n;i++)
using namespace std;

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);


    int tw=1,cnt=0,res;
    while(n--)
    {
        tw*=2;
        if(tw>m)
            break;

    }


     res=m%tw;



    cout<<res<<endl;
}
