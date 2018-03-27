#include<bits/stdc++.h>
using namespace std;

int  ara[109], dp[109][109];
int n;

struct data{
    int till, ammount;
};

data dirt[109];
int f (int index, int moves)
{
    if(moves<=0) return 0;
    if(index==n) return 0;

    if(dp[index][moves]!=-1) return dp[index][moves];

    int res1,res2;
    res1= dirt[index].ammount  +  f(dirt[index].till+1, moves-1);
    res2= f(index+1,moves);

    return dp[index][moves]=max(res1,res2);
}

int main ()
{

    int t=0,test;
    cin>>test;

    while(t<test)
    {
        memset(dp,-1 , sizeof dp);
        int w,k,dummy,i;
        scanf("%d %d %d",&n,&w,&k);

        for(i=0; i<n; i++)
        {
            scanf("%d %d",&dummy,&ara[i]);
        }

        sort(ara,ara+n);

        for(i=0; i<n; i++)
        {
            int j=i, sum=0;
            while(ara[j]<=ara[i]+w && j<n)
            {
                sum++;
                j++;
            }

            dirt[i].ammount=sum;
            dirt[i].till=j-1;

        }

        printf("Case %d: %d\n",++t, f(0,k));

    }
    return 0;
}
