#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<int,int>
#define inf 100000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
#define rep(i,a,n) for(int i=a;i<n;i++)
#define mod 1000000000;

using namespace std;

ll dp[1000005];

int main()
{

        int n;
        scanf("%d",&n);

        for(int i=0;i<=n;i++)
        dp[i]=1;

        int p2=2;
        for(int i=p2; p2<=n;i++)
        {

            int j=p2;

            while(j<=n)
            {
                dp[j]+=dp[j-p2];
                dp[j]%=mod;
                j++;
            }

            p2=p2*2;
        }

       printf("%lld\n",dp[n]);



          return 0;
}
