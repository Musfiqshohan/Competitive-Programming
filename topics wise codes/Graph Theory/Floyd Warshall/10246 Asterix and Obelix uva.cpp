#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define inf 1000099
using namespace std;

int ara[100][100] ,feast[100], feasta[100][100];
int main()
{
    int c,r,q,u,v,w;
    scanf("%d %d %d",&c,&r,&q);

    for(int i=1;i<=c;i++)scanf("%d",&feast[i]);

    for(int i=0;i<r;i++)
    {
        scanf("%d %d %d",&u,&v,&w);
        ara[u][v]=ara[v][u]=w;
    }

    for(int i=1;i<=c;i++)
        for(int j=1;j<=c;j++)
           {
            if(ara[i][j]!=0) feasta[i][j]=feast[j];
            if(ara[i][j]==0 && i!=j) ara[i][j]=10000009;
           }


    for(int k=1;k<=c;k++)
        for(int i=1;i<=c;i++)
            for(int j=1;j<=c;j++)
                if( (ara[i][k]+feasta[i][k]) + (ara[k][j]+feasta[k][j])  < (ara[i][j]+feasta[i][j]) )
                    {ara[i][j]=ara[i][k]+ara[k][j];
                    feasta[i][j]= feasta[i][k]+ feasta[k][j];
                    }

    for(int i=0;i<q;i++)
    {
        scanf("%d %d",&u,&v);
        printf("%d\n",ara[u][v]);
    }


    return 0;
}
