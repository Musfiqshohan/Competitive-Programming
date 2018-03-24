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


int n;

int dp[32][32][32];

int f(int a, int b, int pos)
{
    if(pos==n)
    {
        if(a || b) return -10000000;
        return 0;
    }

    if(dp[a][b][pos]!=-1) return dp[a][b][pos];

    int res=0;

    int t1=(1<<(n-pos-1)) +f(a-1,b, pos+1);

    int t2=(1<<(n-pos-1))+f(a,b-1, pos+1);

    res=max(t1,t2);

    int t3= f(a-1,b-1, pos+1);

    int t4= f(a,b, pos+1);

    return dp[a][b][pos]=res=max(res, max(t3,t4));

}



int main()
{

    int tt;
    cin>>tt;

    while(tt--)
    {

        ms(dp,-1);
        int a,b;
        cin>>n>>a>>b;

        int b1=__builtin_popcount(a);
        int b2=__builtin_popcount(b);

        cout<<f(b1,b2,0)<<endl;

    }

}

