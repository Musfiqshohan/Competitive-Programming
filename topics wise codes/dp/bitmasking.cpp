#include<bits/stdc++.h>
using namespace std;
int w[20][20];
int n;
int dp[1<<15+2];

int call(int mask)
{
    if(mask==(1<<n)-1) return 0;
    int i,j;
    for(i=0;i<n;i++)
    {
        if(check(mask,i)==0)
        {
            int price=w[i][i];
            for(j=0;j<n;j++)
            {
                if(i!=j && check(mask,j)!=0)
                {
                    price+=w[i][j];
                }

            }

            int ret= price+ call((set(mask,i))
        }
    }
}

int main()
{
    memset(dp,-1,sizeof dp);
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&w[i][j]);
        }
    }

    int ret=call(0);
    printf("%d\n",ret);

    return 0;
}
