#include<bits/stdc++.h>
using namespace std;

int dp[200][200];
int grundy(int m, int n)
{

    if(m<1 || n<1) return 0;
    //if(m==2 && n==2) return 0;
    if(m==1 || n==1) return 1;

    if(dp[m][n]!=-1) return dp[m][n];
    int xsum=0,g1,g2,g3,g4,i,j;

    int flag[1200];
    memset(flag, 0, sizeof flag);

    for(i=1; i<=m; i++)
    {
        for(j=1; j<=n; j++)
        {
            g1=grundy(i-1,j-1);
            g3=grundy(m-i,j-1);
            g2=grundy(i-1,n-j);
            g4=grundy(m-i, n-j);

             xsum=g1^g2^g3^g4;
            // printf("xsum= %d\n",xsum);

             flag[xsum]=1;

        }
    }

    for(int k=0;  ;k++)
    {
       // printf("flag i =%d ",flag[i]);
        if(!flag[k]){
                //printf("\nGrundy = %d\n",k);
                return dp[m][n]=k;
        }
    }



}


int main()
{
    memset(dp,-1,sizeof dp);
    int t=0,test;

    cin>>test;
    while(t++<test){

    int m,n;
    scanf("%d %d",&m,&n);

    //cout<<grundy(m,n)<<endl;
    if(grundy(m,n)==0) printf("2\n");
    else printf("1\n");

    }

    return 0;
}
