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

int cost[89];
struct info
{
    int dis,mx;
} ara2[89][89];
//ara2[89][89];
int dist[89][89];
int main()
{
    int C,R,Q,u,v,w;

    scanf("%d %d %d",&C,&R,&Q);

    for(int i=1; i<=C; i++)
    {
        scanf("%d",&cost[i]);
        ara2[i][i].mx=cost[i];

    }

    for(int i=1; i<=C; i++)
        for(int j=1; j<=C; j++)
        {
            dist[i][j]= (i==j)?  0:100000;

            ara2[i][j].dis=(i==j)?  cost[i]:100000;
        }

    for(int i=1; i<=R; i++)
    {
        scanf("%d %d %d",&u,&v,&w);

        dist[u][v]=w;
        dist[v][u]=w;

        ara2[u][v].mx= max(cost[u], cost[v]);
        ara2[v][u].mx= max(cost[u], cost[v]);
    }

    for(int k=1; k<=C; k++)
    {
        for(int i=1; i<=C; i++)
        {
            for(int j=1; j<=C; j++)
            {
                if(dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j]=dist[i][k] + dist[k][j] ;
                }
            }
        }
    }

    for(int k=1; k<=C; k++)
    {
        for(int i=1; i<=C; i++)
        {
            for(int j=1; j<=C; j++)
            {

                if( ara2[i][k].mx > ara2[k][j].mx)
                {
                    printf("%d > %d\n",ara2[i][k].mx, ara2[k][j].mx);
                    if(ara2[i][k].dis + dist[k][j]  < ara2[i][j].dis )
                    {
                        printf("1->  dist(%d,%d)=%d  ara2(%d,%d)=%d  ara2(%d,%d)=%d\n",i,k,dist[i][k], k,j,ara2[k][j].dis, i,j,ara2[i][j].dis);
                        ara2[i][j].dis= ara2[i][k].dis + dist[k][j];
                        ara2[i][j].mx=ara2[i][k].mx;
                        printf("->ara2[%d][%d]= %d\n",i,j,ara2[i][j].dis);

                    }

                }

                else
                {
                    printf("%d < %d\n",ara2[i][k].mx, ara2[k][j].mx);
                    if(dist[i][k] + ara2[k][j].dis < ara2[i][j].dis)
                    {
                        printf("2->  ara2(%d,%d)=%d  dist(%d,%d)=%d    ara2(%d,%d)=%d\n",i,k,ara2[i][k].dis, k,j,dist[k][j], i,j,ara2[i][j].dis);
                        ara2[i][j].dis= dist[i][k] + ara2[k][j].dis;
                        ara2[i][j].mx= ara2[k][j].mx;
                          printf("->ara2[%d][%d]= %d\n",i,j,ara2[i][j].dis);
                    }

                }

            }
        }
    }


    for(int i=0; i<Q; i++)
    {
        scanf("%d %d",&u,&v);

        printf("%d\n",ara2[u][v]);
    }






    return 0;
}
