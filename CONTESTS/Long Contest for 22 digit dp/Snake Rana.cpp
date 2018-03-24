///https://vjudge.net/contest/212862#problem/L
#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define i64 long long
#define pii pair<int,int>
#define inf 100000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
#define rep(i,n) for(i64 i=0;i<n;i++)
#define mod 1000000007
using namespace std;


pii cells[25];
int n,m;
void TOT(int N,int M)
{
    int tot=0;
    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=M; j++)
        {

            int en=(M-j+1)*(N-i+1);
            // cout<<en<<endl;
            tot+=en;
        }
    }

    cout<<tot<<endl;
}

i64 f(int mask,int k)
{
    int mnr,mnc,mxr,mxc;
    mnr=mnc=INT_MAX;
    mxr=mxc=0;
    for(int i=0; i<k; i++)
    {
        if(mask&(1<<i))
        {
            mnr=min(mnr,cells[i].first);
            mnc=min(mnc,cells[i].second);

            mxr=max(mxr,cells[i].first);
            mxc=max(mxc,cells[i].second);
        }
    }

    i64 res=(1LL*mnr*mnc)* (1LL*n-mxr+1)*(1LL*m-mxc+1);

    return res;
}


int main()
{
    int tt=0,test;
    cin>>test;

    while(tt++<test)
    {

        cin>>n>>m;

        int k;
        i64 tot=0,res=0;
        //TOT(n,m);
        tot= n*(1LL*n+1) *  m*(1LL*m+1);
        tot/=4;
        //cout<<tot<<endl;
        cin>>k;

        for(int i=0; i<k; i++)
        {
            scanf("%d %d",&cells[i].first,&cells[i].second);
        }

        for(int i=0; i<=(1<<k); i++)
        {
            i64 ret=f(i,k);
            if(__builtin_popcount(i)&1)

                res+=ret;
            else res-=ret;
        }


        //cout<<res<<endl;
        cout<<tot-res<<endl;

        ms(cells,0);


    }

    return 0;
}
