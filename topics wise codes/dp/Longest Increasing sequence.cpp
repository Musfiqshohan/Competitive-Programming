#include<bits/stdc++.h>
#define mx 1000
using namespace std;
int n=7;
int value[]={ -100000, 3,3,3,3,4,5,6 };
int dp[mx], dir[mx];

int longest(int u)
{
    if(dp[u]!=-1) return dp[u];

    int maxi=0;

    for(int v=u+1; v<=n; v++)
    {
        if(value[v]>value[u])
        {
            if(longest(v)>maxi){
                maxi=longest(v);
                dir[u]=v;
            }
        }

    }
    dp[u]=maxi+1;
    return dp[u];
}

void solution(int start)
{
	while(dir[start]!=-1)
	{
		printf("index %d value %d\n",start,value[start]);
		start=dir[start];
	}

    printf("index %d value %d\n",start,value[start]);
}

int main()
{
    memset(dp,-1,sizeof(dp));
    memset(dir,-1,sizeof(dir));

    int LIS=0,start,cnt=0;
    for(int i=1;i<=n;i++)
    {
        printf("longest path from %d: %d\n",i, longest(i));
        if(longest(i)>LIS)
        {
            cnt=1;
            LIS= longest(i);
            start=i;
        }
        else if(longest(i)==LIS)
        {
            cnt++;

        }

    }

    printf("LIS= %d Starting from %d\n", LIS, start);
    printf("Number of longest path %d\n",cnt);

    solution(start);


    return 0;
}
