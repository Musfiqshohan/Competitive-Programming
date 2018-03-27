#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<int,int>
#define inf 100000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
using namespace std;

int feast[100], ara[90][90];
int main()
{
    int C,R,Q,u,v,w;
    scanf("%d %d %d",&C,&R,&Q);

    for(int i=1; i<=C; i++)
        scanf("%d",&feast[i]);

    for(int i=1; i<=C; i++)
        for(int j=1; j<=C; j++)
            ara[i][j]= (i==j)?  0:100000;



    for(int i=1; i<=R; i++)
    {
        scanf("%d %d %d",&u,&v,&w);
        ara[u][v]=w;
        ara[v][u]=w;
    }


    for(int k=1; k<=C; k++)
        for(int i=1; i<=C; i++)
            for(int j=1; j<=C; j++)
            {
                if(ara[i][k]+ara[k][j]<ara[i][j])
                    {
                        ara[i][j]=ara[i][k]+ara[k][j];

                    }
            }




    for(int q=0; q<Q; q++)
    {
        scanf("%d %d",&u,&v);
        for(int i=1; i<=C; i++)
        {
            printf("(%d->%d=)%d + %d + (%d->%d)%d  sum=%d\n",u,i,ara[u][i], feast[i], i,v, ara[i][v], ara[u][i]+feast[i]+ara[i][v]);

        }

    }




    return 0;
}
