#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define i64 long long
#define pii pair<i64,i64>
#define inf 100000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
#define rep(i,n) for(i64 i=0;i<n;i++)
using namespace std;


i64 n;

i64 dp[32][32][32];
i64 vis[32][32][32];

i64 f(i64 a, i64 b, i64 pos)
{
    //pri64f("%d %d %d\n",a,b,pos);
    if(pos==n)
    {
        if(a || b) return -1000000000000;
        return 0;
    }
    if(a<0 || b<0) return -1000000000000;

    if(vis[a][b][pos]==1) return dp[a][b][pos];
    vis[a][b][pos]=1;

    i64 res=0;


    i64 t1=(1<<(n-pos-1)) +f(a-1,b, pos+1);

    i64 t2=(1<<(n-pos-1))+f(a,b-1, pos+1);

    res=max(t1,t2);

    i64 t3= f(a-1,b-1, pos+1);

    i64 t4= f(a,b, pos+1);

    // cout<<

    return dp[a][b][pos]=max(res, max(t3,t4));

}



int main()
{
    i64 tt;
    cin>>tt;
    while(tt--)
    {
        ms(vis,0);
        i64 a,b;
        cin>>n>>a>>b;

        i64 b1=__builtin_popcount(a);
        i64 b2=__builtin_popcount(b);

        cout<<f(b1,b2,0)<<endl;
    }

}

