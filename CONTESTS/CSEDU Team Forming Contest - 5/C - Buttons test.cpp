#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
using namespace std;
int dp[1000][1000];

int f(int n, int k)
{
    if(n<=k) return 1;

    if(dp[n][k]!=-1) return dp[n][k];

    for(int i=1; i<=k; i++)
    {
        if(f(n-i,k)==0) return dp[n][k]=1;
    }

    return dp[n][k]=0;

}

int main()
{
    //freopen("output.txt", "w", stdout);
    freopen("output.txt", "w", stdout);
    ms(dp,-1);
    int n,k;

    for(int n=3; n<=100; n++)
    {

        //scanf("%d",&n);

        for(int k=2; k<=n-1; k++)
        {
            //scanf("%d",&k);

            if(f(n,k)==0)
            {
                printf("%d ->%d\n",n,k);
                break;
            }

        }

    }
    return 0;
}
