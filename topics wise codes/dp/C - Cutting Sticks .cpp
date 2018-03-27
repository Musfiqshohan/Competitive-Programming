#include<bits/stdc++.h>
#define  ms(a,b) memset(a,b,sizeof a);
#define mod  1000000
#define ll long long
#define print(a,b) printf("%d %d\n",a,b);
#define test() printf("I am here\n");
using namespace std;

int cut[10000],vis[10000];
int n;
int dp[1009][1009];
int f(int i, int j)
{

    if(i==j) return 0;

    if(dp[i][j]!=-1) return dp[i][j];

    int res=0,mn=INT_MAX;

    for(int k=0; k<n; k++)
    {
        if(cut[k]>=i && vis[k]==0 &&cut[k]<=j)
        {

            vis[k]=1;
            res= (j-i) + f(i,cut[k]) + f(cut[k],j);
            vis[k]=0;


            mn= min(mn,res);
        }
    }

    if(mn==INT_MAX) mn=0;

    return dp[i][j]=mn;

}

int main()
{
    //freopen("Cutting Sticks.txt", "w", stdout);

    while(1)
    {
        ms(dp,-1);
        int l;
        scanf("%d",&l);
        if(l==0) return 0;
        scanf("%d",&n);

        for(int i=0; i<n; i++)
        {
            scanf("%d",&cut[i]);
        }

        printf("The minimum cutting is %d.\n",f(0,l));
        ms(vis,0);

    }
    return 0;
}
