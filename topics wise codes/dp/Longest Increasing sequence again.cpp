#include<bits/stdc++.h>
using namespace std;
int dir[1000],dp[1000];
int value[]={-100000,5,0,9,2,7,3,4};
int n=7;
int longest(int u)
{

    if(dp[u]!=-1) return dp[u];
    int mx=0,i;
    for(i=u+1;i<=n;i++)
    {
        if(value[u]<value[i])
        {
            if(longest(i)>mx)
            {
                mx=longest(i);
                dir[u]=i;
            }

        }
    }
    dp[u]=mx+1;
    return dp[u];
}

void solution(int start)
{
    while(dir[start]!=-1)
    {
        printf("index->%d  value->%d\n",start, value[start]);
        start=dir[start];
    }
    printf("index->%d  value->%d\n",start, value[start]);

}
int main()
{

    memset(dir,-1,sizeof dir);
    memset(dp,-1,sizeof dp);
    int LIS=0,i,start;

    for(i=1;i<=n;i++)
    {
        printf("Longest pathe from %d is %d\n",i, longest(i));
        if(longest(i)>LIS)
        {
            LIS=longest(i);
            start=i;
        }
    }

    printf("%d %d\n",LIS,start);

    solution(start);
}
