#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<int,int>
#define inf 100000000000
using namespace std;
int R,C;
struct par
{
    int r,c;
};

int dirr[4]={ 0, 0, 1, -1 };
int dirc[4]={ 1, -1,0,  0 };
int disf[201][201], disj[201][201], visj[201][201];
char ara[201][201];
vector<par>vec;
int mn=100000;


void clearr()
{
    mn=100000;
    ms(disf,0);
    ms(disj,0);
    ms(visj,0);
//    ms(visf,0);
    vec.clear();

}
void bfs1(par src,int num)
{
    queue<par>q;
    q.push(src);

    disf[src.r][src.c]=0;
  //  visf[src.r][src.c][num]=1;

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

            if(r1>=1 && r1<=R && c1>=1 && c1<=C && ara[r1][c1] !='#') // && visf[r1][c1][num]==0
            {
                //visf[r1][c1][num]=1;

                if(disf[r][c]+1 <disf[r1][c1])
                {
                    disf[r1][c1]=disf[r][c]+1;
                    q.push({r1,c1});
                }

            }
        }


    }


}

void bfs2(par src)
{
    queue<par>q;

    q.push(src);
    disj[src.r][src.c]=0;
    visj[src.r][src.c]=1;

    while(!q.empty())
    {
        par t=q.front();
        q.pop();

        int r=t.r;
        int c=t.c;

        for(int i=0;i<4;i++)
        {
            int r1=r+dirr[i];
            int c1=c+dirc[i];


            if(r1>=1 && r1<=R && c1>=1 && c1<=C && ara[r1][c1] =='.' && visj[r1][c1]==0 && disj[r][c]+1< disf[r1][c1])
            {
                visj[r1][c1]=1;
                disj[r1][c1]=disj[r][c]+1;

                q.push({r1,c1});

                if(r1==1 || r1==R || c1==1 || c1==C)
                {
                    mn=min(mn,disj[r1][c1]);
                }
            }
        }
    }


}

int main()
{
    int tt=0,test;
    cin>>test;

    while(tt<test){


    scanf("%d %d",&R,&C);
    getchar();
    par src;
    for(int i=1; i<=R; i++)
    {
        for(int j=1; j<=C; j++)
        {
            disf[i][j]=500000;
            scanf("%c",&ara[i][j]);
            if(ara[i][j]=='F')
                vec.push_back({i,j});
            if(ara[i][j]=='J')
                src= {i,j};
        }
        getchar();
    }



    for(int i=0; i<vec.size(); i++)
    {
        bfs1(vec[i],i);
    }

//    for(int i=1;i<=R;i++)
//    {
//        for(int j=1;j<=C;j++)
//            printf("%d ",disf[i][j]);
//
//        puts("");
//    }

    bfs2(src);

//      for(int i=1;i<=R;i++)
//    {
//        for(int j=1;j<=C;j++)
//            printf("%d ",disj[i][j]);
//
//        puts("");
//    }


    printf("Case %d: ",++tt);
    if(src.r==1 || src.r==R || src.c==1 || src.c==C) printf("1\n");
    else if(mn==100000) printf("IMPOSSIBLE\n");
    else printf("%d\n",mn+1);

    clearr();
    }
    return 0;
}

