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

int mark[15];
bool dp[15][15][1005];
bool f(int prev, int extra, int rem)
{
   // printf("%d %d\n",extra, rem);
    if(rem==0)
        return true;

    if(dp[prev][extra][rem]==true) return dp[prev][extra][rem];

    bool t=0;
    for(int i=extra+1;i<=10;i++)
    {
        if(mark[i]==1 && i!=prev)
        {
            t|= f(i,i-extra , rem-1);
        }
    }

    return dp[prev][extra][rem]=t;

}


void print(int prev, int extra, int rem)
{

    if(rem==0)
        return ;

    int t=0,res=0;
    for(int i=extra+1;i<=10;i++)
    {
        if(mark[i]==1 && i!=prev)
        {
            t= f(i,i-extra , rem-1);
            if(t==1)
                res=i;
        }
    }

    printf("%d ",res);
    print(res, res-extra, rem-1);

    return;

}

int main()
{
    memset(dp,0,sizeof dp);
    int x,m;
    for(int i=1; i<=10; i++)
    {
        scanf("%1d",&x);
        if(x==1)
        mark[i]=1;

    }
    cin>>m;


    int res=f(11,0,m);
    if(res==0) printf("NO\n");
    else
    {
        printf("YES\n");
        print(15,0,m);
        puts("");
    }



    return 0;
}
