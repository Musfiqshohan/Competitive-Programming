#include<bits/stdc++.h>
using namespace std;
pair<int, int> a[2000];
int dp[1000][1000];

int grundy(int x,int y)
{
    //printf("%d %d\n",x,y);
    if(x<0 || y<0) return -1;

    if(dp[x][y]!=-1) return dp[x][y];

    int flag[2000];

    memset(flag,0, sizeof flag);


    if(x-2>=0)
    {
        int g1=grundy(x-2,y+1);
        if(g1!=-1) flag[g1]=1;
    }
    if(x-3>=0 && y-1>=0)
    {
        int g2=grundy(x-3,y-1);
        if(g2!=-1) flag[g2]=1;
    }
    if(x-2>=0 && y-1>=0)
    {
        int g3= grundy(x-2,y-1);
        if(g3!=-1) flag[g3]=1;
    }
    if(x-1>=0 && y-2>=0)
    {
        int g4=grundy(x-1,y-2);
        if(g4!=-1) flag[g4]=1;
    }
    if(x-1>=0 && y-3>=0)
    {
        int g5= grundy(x-1,y-3);
        if(g5!=-1) flag[g5]=1;
    }
    if(y-2>=0)
    {
        int g6=grundy(x+1,y-2);
        if(g6!=-1) flag[g6]=1;
    }

    for(int i=0; ; i++)
        if(flag[i]==0)
        {
            //printf("nim value of %d,%d= %d \n",x,y,i);
            return dp[x][y]=i;
        }


}

int main()
{
    memset(dp, -1, sizeof dp);

    int i,j;

    for(i=0; i<=510; i++)
    {
        for(j=0; j<=510; j++)
        {
            dp[i][j]=grundy(i,j);
        }
    }


    int t=0, test;
    cin>>test;

    while(t<test)
    {

        int n,xsum=0;
        scanf("%d",&n);



        for(i=0; i<n; i++)
            scanf("%d %d",&a[i].first, & a[i].second);

        for(i=0; i<n; i++)
        {
            xsum^=dp[a[i].first][a[i].second];
        }

        printf("Case %d: ",++t);
        if(xsum==0) printf("Bob\n");
        else printf("Alice\n");

    }


}
