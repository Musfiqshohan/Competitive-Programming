#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<int,int>
#define inf 100000000000
using namespace std;

int R,C,Q, tot;

struct par
{
    int r,c;
};

int dirr[4]= { 0, 0, 1, -1 };
int dirc[4]= { 1, -1,0,  0 };

int dis[505][505], vis[505][505];
char ara[505][505];
vector<par>vec;

void clearr()
{
    ms(vis,0);
    ms(dis,0);
}

void bfs(par src)
{
    queue<par>q;
    q.push(src);
    tot=0;

    //dis[src.r][src.c]=0;
    vis[src.r][src.c]=1;
     vec.push_back({src.r,src.c});

    if(ara[src.r][src.c]=='C') tot++;


    while(!q.empty())
    {
        par t= q.front();
        q.pop();

        int r=t.r;
        int c=t.c;

        for(int i=0; i<4; i++)
        {
            int  r1=r+dirr[i];
            int  c1=c+dirc[i];

            if(r1>=1 && r1<=R && c1>=1 && c1<=C && ara[r1][c1] !='#'  && vis[r1][c1]==0)
            {

                vec.push_back({r1,c1});
                if(ara[r1][c1]=='C') tot++;

                vis[r1][c1]=1;

                q.push({r1,c1});


            }
        }


    }


}


int main()
{
    int tt=0,test;
    cin>>test;

    while(tt<test){

    scanf("%d %d %d",&R,&C,&Q);
    getchar();

    int cnt=0;
    par t;

    for(int i=1; i<=R; i++)
    {
        for(int j=1; j<=C; j++)
        {
            scanf("%c",&ara[i][j]);

        }
        getchar();
    }

    for(int i=1; i<=R; i++)
    {
        for(int j=1; j<=C; j++)
        {
            if(vis[i][j]==0 && ara[i][j]!='#')
            {
                vec.clear();
                bfs({i,j});



                for(int k=0; k<vec.size(); k++)
                {
                    dis[ vec[k].r ][ vec[k].c ]=tot;

                }

            }



        }

    }

    int x,y;
    printf("Case %d:\n",++tt);

    for(int i=0;i<Q;i++)
    {
        scanf("%d %d",&x,&y);

        printf("%d\n",dis[x][y]);
    }

    clearr();

    }

    return 0;
}
