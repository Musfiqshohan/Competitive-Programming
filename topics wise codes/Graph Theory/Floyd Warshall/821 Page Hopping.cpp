#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define inf 1000099
using namespace std;

int ara[105][105], mark[105];
int main()
{
    int flag=0,test=0;
    while(1)
    {
        int n=0,u,v,mn=105,mx=1;
        while(1)
        {
            scanf("%d %d",&u,&v);
            if(u==0 && v==0 && flag==1)
            {
                flag=2;
                break;
            }
            if(u==0 && v==0)
            {
                flag=1;
                break;
            }
            else flag=0;
            ara[u][v]=1;
            mn=min(mn, min(u,v));
            mx=max(mx, max(u,v));
            mark[u]=1;
            mark[v]=1;

        }
        if(flag==2) break;

        for(int i=mn; i<=mx; i++)
            for(int j=mn; j<=mx; j++)
            {
                if(ara[i][j]==0 && i!=j)
                    ara[i][j]=10000009;

            }

        for(int k=mn; k<=mx; k++)
        {
            if(mark[k]==0) continue;
            for(int i=mn; i<=mx; i++)
            {
                if(mark[i]==0) continue;
                for(int j=mn; j<=mx; j++)
                {
                    if(mark[j]==0) continue;
                    //printf("%d->-> %d\n",i,j);
                    if(ara[i][k]+ara[k][j]<ara[i][j])
                    {
                        ara[i][j]=ara[i][k]+ara[k][j];
                       // printf("%d -> %d=%d  %d->%d=%d  %d->%d=%d\n",i,k,ara[i][k], k,j,ara[k][j], i,j,ara[i][j]);

                    }
                }
            }

        }

        int sum=0,cnt=0;

        for(int i=mn; i<=mx; i++){
            if(mark[i]==0) continue;
              //  printf("%d->\n",i);
            for(int j=mn; j<=mx; j++)
            {
                if(ara[i][j]<=100000 && i!=j && mark[j]==1)
                {
                  //  printf("%d ",ara[i][j]);
                    sum+=ara    [i][j];
                    cnt++;
                }

            }
           // puts("");
    }

        //  double avg= sum/(n*n-n)*1.0;
        printf("Case %d: average length between pages = %.3f clicks\n",++test,sum/(cnt*1.0));
        ms(ara,0);
        ms(mark,0);

    }
}
