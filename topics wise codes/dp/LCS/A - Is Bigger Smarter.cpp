
#include<bits/stdc++.h>
using namespace std;

int LIS(int u)
{
    if(dp[u]!=-1) return dp[u];
    int mx=0;
    for(int i=u+1; i<n; i++)
    {
         int weight=v[i].w;
        if(v[u].iq>v[i].iq && vis[weight]==0)
        {

            vis[weight]==1;
            if(LIS(i)>mx  )
            {

                mx=LIS(i);
                vis[weight]==0;
                dir[u]=i;
            }
        }
    }

    return dp[u]=mx+1;

}
void printLIS(int i)
{
    while(dir[i]!=-1)
    {
        printf("%d ",i);
        i=dir[i];
    }
    printf("%d \n",i);
}

int main()
{
    data temp;
    int i,x,y;
    scanf("%d",&n);

    for(i=0; i<n; i++)
    {

    }


    memset(dp,-1,sizeof dp);
    memset(dir,-1,sizeof dir);

    cout<<LIS(1)<<endl;

    return 0;
}

