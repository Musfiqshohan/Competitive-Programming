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

pii ara[40];


i64 f(i64 L, i64 n)
{
    i64 tot=0;

    while(L>0)
    {
        i64 mn=INF,mnL;
        for(i64 i=0; i<n; i++)
        {
            i64 div=L/ara[i].second;
            if(div==0) div++;
            if(div*ara[i].first<mn)
            {
                mn=div*ara[i].first;
                mnL=L-(div*ara[i].second);
               // pri64f("%lld %lld div=%lld frs=%lld\n",mn,mnL,div, ara[i].first);
            }
        }

        tot+=mn;
        L=mnL;

    }

    return tot;

}
int main()
{
    i64 n,L,x;
    scanf("%lld %lld",&n,&L);

    for(i64 i=0; i<n; i++)
    {
        scanf("%lld",&x);
        ara[i]={x,1<<i};
        comp[i]=i;
    }

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int res=(1<<j)/(1<<i);

            if(res*ara[i]<=ara[j])
                ara[j]=res*ara[i];
        }
    }






    return 0;
}

