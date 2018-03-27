#include<bits/stdc++.h>
using namespace std;

int dp(int index, int curmask, int prvmask)
{

    if(index>=r)
    {
        if(prvmask==(1<<c)-1) return 0;
        else return INT_MAX;
    }

    int &v= vis[index][curmask][prvmask];
    int &ret=dp[index][curmask][prvmask];

    ret= INT_MAX;

    for(int i=0;i<(1<<c);i++)
    {
        int cnt=0;
        int row[3]={prvmask,curmask, save[index+1]};

        for(int j=0;j<c;j++)
        {
            if(!(i&&(1<<j))) continue;
        }


    }




}
int main()
{
    scanf("%d %d",&r,&c);

    for(int i=0;i<r;i++)
    {
        scanf("%s",&str);
        int mask=0;

        for(j=0;j<c;j++)
        {
            if(str[j]=='*')  mask= mask|(1<<j);
        }

        save[i]=mask;       //save the current condition

    }

    int ans= dp(0,save[0],0);
    cout<<ans<<endl;


    return 0;
}
