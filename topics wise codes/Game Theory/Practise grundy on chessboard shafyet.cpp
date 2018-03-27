#include<bits/stdc++.h>
using namespace std;
int a[20][29];
int grundy(int x, int y)
{
    printf("x=%d y=%d\n",x,y);
    if(x<=0 || y<=0 || x>8 || y>8) return -1;

    if(a[x][y]!=-1) return a[x][y];

   int ara[10];
   memset(ara, 0,sizeof ara);


    int g1=grundy(x-2,y+1); if(g1!=-1) ara[g1]=1;
    int g2=grundy(x-2,y-1); if(g2!=-1) ara[g2]=1;
    int g3=grundy(x-1,y-2); if(g3!=-1) ara[g3]=1;
    int g4=grundy(x+1,y-2); if(g4!=-1) ara[g4]=1;




    for(int i=0; ;i++)
        if(ara[i]==0) return a[x][y]=i;



}

int main()
{
    memset(a,-1,sizeof a);

  //  a[1][1]=grundy(1,1);

    for(int i=1;i<=8;i++)
    {
        for(int j=1;j<=8;j++)
        {
           a[i][j]=grundy(i,j);
        }
    }

    for(int i=1;i<=8;i++)
    {
        for(int j=1;j<=8;j++)
            printf("%d ",a[i][j]);
        puts("");
    }

    return 0;

}
