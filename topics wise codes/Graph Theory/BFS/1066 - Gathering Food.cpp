#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<int,int>
#define inf 100000000000
using namespace std;

struct par
{
    int r,c;
};

int n;
int dirr[4]={ 0, 0, 1, -1 };
int dirc[4]={ 1, -1,0,  0 };
char ara[12][12];
int dis[15][15], vis[15][15];
par vec[30];

void clearr()
{
    ms(vec,0);
    ms(dis,0);
    ms(vis,0);
}
void bfs(par src, char L)
{
    queue<par>q;
    q.push(src);


    dis[src.r][src.c]=0;
    vis[src.r][src.c]=1;

    while(!q.empty())
    {
        par t= q.front();
        q.pop();

        int r=t.r;
        int c=t.c;

        for(int i=0;i<4;i++)
        {
            int  r1=r+dirr[i];
            int  c1=c+dirc[i];


            if(r1>=1 && r1<=n && c1>=1 && c1<=n && vis[r1][c1]==0 && ( ara[r1][c1] =='.'  || (ara[r1][c1]<=L && ara[r1][c1]>=65) ) )
            {

                    vis[r1][c1]=1;
                    dis[r1][c1]=dis[r][c]+1;
                    q.push({r1,c1});


            }
        }


    }


}



int main()
{
    int t=0,test;
    cin>>test;
    getchar();
    while(t<test){

    scanf("%d",&n);
    getchar();

    int cnt=0;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            scanf("%c",&ara[i][j]);
            if(ara[i][j]>=65 && ara[i][j]<=90)
            {
                vec[ ara[i][j]-'A' ]={i,j};
                cnt++;
            }
        }
            getchar();
    }




    int tot=0,flag=0;
    for(int i=0; i< cnt;i++)
    {
        ms(vis,0);

        bfs( vec[i], i+66 );
        int res= dis[ vec[i+1].r ][ vec[i+1].c ];
        if(res==0 && i<cnt-1) flag=1;
        tot+=res;
    }

    printf("Case %d: ",++t);

    if(flag==1) printf("Impossible\n");
    else
        printf("%d\n",tot);
    getchar();

    clearr();

    }

    return 0;
}
