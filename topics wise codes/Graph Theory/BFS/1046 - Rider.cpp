#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<int,int>
#define inf 100000000000
using namespace std;
int R,C, tot=0;
struct par
{
    int r,c;
};

int dirr[8]= { +2, -2, +1, -1, +2,  -2, +1, -1};
int dirc[8]= { +1, +1, +2, +2, -1,  -1, -2, -2};

int dis[21][21], vis[21][21];
char ara[21][21];
vector<par>vec;

void clearr()
{
    vec.clear();
    ms(dis,0);
    ms(vis,0);
}



void bfs(par src)
{
    queue<par>q;
    q.push(src);

    if(ara[src.r][src.c]!='.') tot++;
    dis[src.r][src.c]=0;
    vis[src.r][src.c]=1;


    while(!q.empty())
    {
        par t= q.front();
        q.pop();

        int r=t.r;
        int c=t.c;

        for(int i=0; i<8; i++)
        {

            int  r1=r+dirr[i];
            int  c1=c+dirc[i];

            if(r1>=1 && r1<=R && c1>=1 && c1<=C && vis[r1][c1]==0)
            {


                vis[r1][c1]=1;

                if(ara[r1][c1]!='.') tot++;

                dis[r1][c1]=dis[r][c]+1;
                q.push({r1,c1});

//                printf("%d %d ->%d %d\n",r,c,r1,c1);
//
//                if(ara[r1][c1]!='.')
//                {
//                    printf("here= %d %d = %d\n",r1,c1, dis[r1][c1]);
//                }

            }
        }


    }


}

int f()
{
    int sum=0;
    for(int i=0; i<vec.size(); i++)
    {
        par t= vec[i];
        sum+=ceil( ((dis[t.r][t.c])*1.0)/(ara[t.r][t.c]-'0') );
    }

    return sum;

}


int main()
{
    int tt=0,test;
    cin>>test;
    getchar();
    while(tt<test)
    {

    scanf("%d %d",&R,&C);
    getchar();

    int cnt=0;
    par t;

    for(int i=1; i<=R; i++)
    {
        for(int j=1; j<=C; j++)
        {
            scanf("%c",&ara[i][j]);
            if(ara[i][j]!='.')
            {
                vec.push_back({i,j});

            }

        }
        getchar();
    }


    int mn=10000000;



        for(int i=1; i<=R; i++)
        {
            for(int j=1;j<=C;j++)
            {
                tot=0;
                ms(dis,0);
                ms(vis,0);
                bfs({i,j});

                if(tot==vec.size())
                {
                   // cout<<f()<<endl;
                    mn= min (mn, f());
                }

            }


        }

    printf("Case %d: ",++tt);

    if(mn==10000000) printf("-1\n");
    else printf("%d\n",mn);


    clearr();

      }

    return 0;
}

