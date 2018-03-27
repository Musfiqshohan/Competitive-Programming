#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<int,int>
#define inf 100000009
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

bool Check(int N, int pos)
{
    return (bool)(N&(1<<pos));
}
int Set(int N, int pos)
{
    return N|(1<<pos);
}

int n,m;
int ara[16][16], dp[16][32868];

int DP(int prevI,int mask)
{

    if(__builtin_popcount(mask)==n)
        return 0;

    if(dp[prevI][mask]!=-1) return dp[prevI][mask];

    int mn= inf, flag=0,mn2=0;
    for(int i=0; i<n; i++)
    {
        if(Check(mask,i)==false && ara[prevI][i]==1)
        {
            int ret= DP(i, Set(mask,i));
            mn=min(mn,ret);
            flag=1;
        }
    }

    if(flag==0 )
    {
        mn2=inf;
        for(int i=0; i<n; i++)
        {
            if(Check(mask,i)==false)
            {
                int ret= 1+ DP(i, Set(mask,i));
                mn2=min(mn2,ret);
            }
        }

        if(mn2>=inf)
            mn2=0;

    }

    return dp[prevI][mask]=mn+mn2;


}
int main()
{
    int t=0,test;
    cin>>test;

    while(t<test)
    {

        ms(dp,-1);

        scanf("%d %d",&n,&m);
        int u,v;


        for(int i=0; i<m; i++)
        {
            scanf("%d %d",&u,&v);
            u--;
            v--;
            ara[u][v]=1;
        }






    int mn=inf;
    for(int i=0; i<n; i++)
    {
        int res= 1+ DP(i, Set(0,i));
        cout<<res<<endl;
        mn= min(mn,res);
    }


         printf("Case %d: %d\n",++t,mn);
        t++;


    }


    return 0;
}
