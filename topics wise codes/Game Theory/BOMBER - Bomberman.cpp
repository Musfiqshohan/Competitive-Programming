#include<bits/stdc++.h>
using namespace std;
int g[110][110],n,m;

int grundy(int i, int j)
{
    if(i<=0 || j<=0) return 0;
    else if(i==1 || j==1) return 1;

   else if( g[i][j] !=-1) return g[i][j];
   else{

    int flag[1200];
    memset(flag,0,sizeof(flag));

    for(int x=0;x<i;x++)
    {
        for(int y=0;y<j;y++)
        {
            int v1,v2,v3,v4;
            v1=grundy(x,y);
            v2=grundy(x,j-y-1);
            v3=grundy(i-x-1,y);
            v4=grundy(i-x-1, j-y-1);

            int sum= v1^v2^v3^v4;
          // printf("sum=%d\n",sum);
            flag[sum]=1;

        }
    }

    for(int k=0; ; k++)
    {
        if(!flag[k]) {
               // printf("Grundy = %d\n",k);
                return g[i][j]=k;
        }
    }

   }
}



int main()
{
    memset(g,-1,sizeof g);

    int T;
    cin>>T;
    while(T--){
    int n,m;
    scanf("%d %d",&n,&m);

  //  cout<<grundy(m,n)<<endl;
    if(grundy(n,m)==0) printf("2\n");
    else printf("1\n");
    }

    return 0;
}
