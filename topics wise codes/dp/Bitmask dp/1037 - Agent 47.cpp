#include<bits/stdc++.h>
using namespace std;
int n;
int dp[(1<<15)+5], life[20], w[20][20];
bool check(int N, int pos) { return N&(1<<pos); }
int Set(int N, int pos) {  return N=N|(1<<pos);  }
int f(int mask)
{
    if(mask==(1<<n)-1) return 0;

    if(dp[mask]!=-1) return dp[mask];

    int mn=INT_MAX,i,j;

    for(i=0;i<n;i++)
    {
        if(check(mask,i)==0)
        {
            int shots=1;

            for(j=0;j<n;j++)
            {
                if(check(mask,j)==1)
                shots= max(shots,w[j][i]);
            }

            int ret=ceil((life[i]*1.0)/shots)+ f(Set(mask,i));

            mn=min(mn,ret);
        }
    }

    return dp[mask]=mn;


}
int main()
{
    int t=0,test;

    scanf("%d",&test);

    while(t<test){
    memset(dp,-1,sizeof dp);
    int i,j;
    scanf("%d",&n);

    for(i=0;i<n;i++) scanf("%d",&life[i]);

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%1d",&w[i][j]);

    printf("Case %d: %d\n",++t,f(0));


    }

    return 0;
}
