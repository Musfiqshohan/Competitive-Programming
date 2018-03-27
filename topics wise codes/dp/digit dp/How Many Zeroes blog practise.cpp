#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
using namespace std;

vector<int>v;
int lim,tt;

int dp[15][2][2][200],vis[15][2][2][200];

int DP(int pos, int isSmaller, int isStart, int value)
{

    if(pos==lim) return value;


    if(vis[pos][isSmaller][isStart][value]==tt)
        return dp[pos][isSmaller][isStart][value];

    vis[pos][isSmaller][isStart][value]=tt;

   // int ses= isSmaller?     9 : v[pos];
   int ses;
   if(isSmaller==1)
    ses=9;
   else ses=v[pos];

    int ret=0;

    if(isStart)
    {
        for(int i=1;i<=ses;i++)
        {
            ret+= DP(pos+1, isSmaller | i<v[pos] , 0 , (i==0)+value );
        }

        ret+= DP(pos+1,1,1,0);
    }
    else
    {
        for(int i=0;i<=ses;i++)
        {
            ret+= DP(pos+1, isSmaller | i<v[pos] ,0, (i==0)+value);
        }

    }

    return dp[pos][isSmaller][isStart][value]=ret;

}



int f(int n)
{

    if(n<0) return 0;
    if(n<=9) return 1;

    v.clear();

    while(n)
    {
        int rem=n%10;
        v.push_back(rem);
        n=n/10;
    }

    tt++;
    reverse(v.begin(), v.end());
    lim= v.size();


    return DP(0,0,1,0)+1;
}


int main()
{
    int m,n;

    scanf("%d %d",&n,&m);

    cout<<f(m)-f(n-1)<<endl;
}
