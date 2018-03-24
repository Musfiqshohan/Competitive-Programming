#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define i64 long long
#define pii pair<i64,i64>
#define inf 1000000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
#define rep(i,n) for(i64 i=0;i<n;i++)
using namespace std;

i64 cat,last;
i64 ara[28][1009];
i64 dp[28][1009][3];
i64 f(i64 r, i64 c, i64 dir)
{
    // pri64f("%lld %lld %lld\n",r,c,dir);

    if(r>cat+1 || c>last || c<0) return inf;

    if(r==cat+1 && c==last)
    {
        return 0;
    }

    if(dp[r][c][dir]!=-1) return dp[r][c][dir];

    i64 t1,t2,t3,t4;
    t1=t2=t3=t4=inf;

    if(ara[r][c]!=0)
    {
        t3=ara[r][c] + f(r+1,c,1);
        t4=ara[r][c] + f(r+1,c,0);
        t3=min(t3,t4);
    }

    if(dir==1)
        t1=1+f(r,c+1,1);

    if(dir==0)
        t2=1+f(r,c-1,0);




    return dp[r][c][dir]= min(t1,min(t2,t3));
}



int main()
{

    int tt;
    cin>>tt;

    while(tt--)
    {

        ms(dp,-1);
        i64 t,x,y;
        scanf("%lld %lld %lld",&cat,&t,&last);


        for(i64 i=0; i<cat; i++)
        {
            for(i64 j=0; j<t; j++)
            {
                scanf("%lld %lld",&x,&y);
                ara[i+1][x]=y;
            }
        }

        printf("%lld\n",f(1,0,1));

    }

}
