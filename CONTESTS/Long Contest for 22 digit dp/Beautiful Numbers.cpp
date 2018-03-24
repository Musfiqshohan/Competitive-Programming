///https://vjudge.net/contest/212862#problem/F

#include<bits/stdc++.h>
#define i64 long long
#define pii pair<i64,i64>
#define mod 1000000007
using namespace std;

int dp[105][10][3][1026];
int f(int pos, int prev, int isStart, int mask,int m,int base)
{

    // printf("%d %d %d %d\n",pos,prev,isStart,mask);
    if(pos==m)
    {
//        bitset<10>bset(mask);
//        cout<<bset<<endl;
        if(__builtin_popcount(mask)==base)
            return 1;
        return 0;
    }

    if(dp[pos][prev][isStart][mask]!=-1) return dp[pos][prev][isStart][mask];
    int st,en=base-1;
    if(isStart)
        st=1;
    else st=0;

    i64 tot=0;
    for(int i=st; i<=en; i++)
    {
        if(abs(i-prev)==1 || isStart==1)
            tot=(tot+f(pos+1,i,0, mask|(1<<i),m,base))%mod;
    }


    return dp[pos][prev][isStart][mask]=tot;
}


int main()
{

    int tt;
    scanf("%d",&tt);
    while(tt--)
    {
        int n,m;
        scanf("%d %d",&n,&m);

        i64 tot=0;
        while(m>0)
        {
            memset(dp,-1,sizeof dp);
            tot=(tot+f(0,10,1,0,m,n))%mod;
            m--;
        }

        printf("%lld\n",tot);
    }
}
