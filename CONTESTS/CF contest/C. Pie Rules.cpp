#include<bits/stdc++.h>
using namespace std;

struct info
{
    int fpl,spl;
};

int pie[60];
info dp[60][3];

int n;
info f(int i, int turn)
{

    if(i==n) return {0,0};

    if(dp[i][turn].fpl!=-1) return dp[i][turn];
    info t1,t2;

    if(turn==1)
    {

        t1=  f(i+1,2);
        t1.fpl+= pie[i];

        t2= f(i+1,1);
        t2.spl+=pie[i];

        if(t1.fpl>t2.fpl) return dp[i][turn]=t1;
        else return dp[i][turn]=t2;
    }
    else
    {
        t1= f(i+1,1);
        t1.spl+=pie[i];

        t2=f(i+1,2);
        t2.fpl+=pie[i];

        if(t1.spl>t2.spl) return dp[i][turn]=t1;
        else return dp[i][turn]=t2;
    }

}

int main()
{
    memset(dp,-1,sizeof dp);
    scanf("%d",&n);

    for(int i=0; i<n; i++)
        scanf("%d",&pie[i]);

    info ret= f(0,2);

    cout<<ret.fpl<<" "<<ret.spl<<endl;

}
