#include<vector>
#include<list>
#include<map>
#include<set>
#include<deque>
#include<queue>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<iostream>
#include<sstream>
#include<iomanip>
#include<cmath>
#include<cstdlib>
#include<cctype>
#include<string>
#include<cstring>
#include<cstdio>
#include<ctime>
#include<climits>
#include<complex>
#include<cassert>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)((x).size())
#define all(x) x.begin(),x.end()
#define clr(x) memset((x),0,sizeof(x))
#define cdp(x) memset((x),-1,sizeof(x))
#define rep(i,n) for (i=0;i<n;i++)
#define Rep(i,a,b) for (i=a;i<=b;i++)
#define ff(i,x) for (i=start[x];i!=-1;i=a[i].next)
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
using namespace std;
const double eps=1e-8;
const double pi=acos(-1.0);
int dblcmp(double d){if (fabs(d)<eps)return 0;return d>eps?1:-1;}
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef vector<pii> vpi;
double dp[1111][1111][2];
bool vis[1111][1111][2];
double getdp(int w,int b,int who)
{
    if (vis[w][b][who])return dp[w][b][who];
    if (w+b==1)
    {
        if (w)return 1.0;
        else return 0.0;
    }
    if (!w)return 0.0;
    if (!b)return 1.0;
    if (who==0)//princess
    {
        double p=w*1.0/(w*1.0+b*1.0);
        double ans=p;
        ans+=(1-p)*(1-getdp(w,b-1,!who));
        vis[w][b][who]=1;
        return dp[w][b][who]=ans;
    }
    else //dragon
    {
        double p=w*1.0/(w*1.0+b*1.0);
        double ans=p;
        //draw black
        {
            //out white
            double p1=w*1.0/(w*1.0+b*1.0-1.0);
            ans+=(1-p)*p1*(1-getdp(w-1,b-1,!who));
            //out black
            ans+=(1-p)*(1-p1)*(1-getdp(w,max(0,b-2),!who));
        }
        vis[w][b][who]=1;
        return dp[w][b][who]=ans;
    }
}
int main()
{
    while(1){
    int i,j,k,w,b;
    cin>>w>>b;
    clr(vis);
    clr(dp);
    printf("%.12lf\n",getdp(w,b,0));
    }
    return 0;
}
