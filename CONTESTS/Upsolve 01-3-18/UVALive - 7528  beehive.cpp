#include<bits/stdc++.h>
using namespace std;


int ara[1000][1000];

int dirr[6]= {-1,-1,-2,+2,+1,+1};
int dirc[6]= {-1,+1, 0, 0,-1,+1};
vector<int>adj[100009];
void Build()
{

    int maxN=200;

    int mid=maxN/2;

    int cnt=1;

    int dis=1,st;

    int r=maxN, c=maxN/2;

    ara[r][c]=1;
    while(dis<mid)
    {
        r=maxN;
        c=maxN/2-dis;

        if(dis&1)
            st= 1;
        else st=0;

        int d=dis;

        r-=st;
        d-=st;
        while(1)
        {
            ara[r][c]=++cnt;
           // printf("1 %d\n",cnt);

            d-=2;
            if(d<0) break;

            r-=2;

        }

      //  printf("start =%d %d\n",r,ara[r][c]);

        d=dis;
        while(d--)
        {
            ara[--r][++c]=++cnt;
          //  printf("2 %d\n",cnt);
        }

        d=dis;
        while(d--)
        {
            ara[++r][++c]=++cnt;
           // printf("3 %d\n",cnt);
        }

       // printf("end =%d %d\n",r,ara[r][c]);
        d=dis;
        while(1)
        {
            d-=2;
            if(d<0) break;

            r+=2;

            ara[r][c]=++cnt;
          //  printf("4 %d\n",cnt);
        }


        dis++;


       // printf("dis=%d\n",dis);


    }


    for(int i=0; i<=maxN+5; i++)
    {
        for(int j=0; j<=maxN+5; j++)
        {
            int r=i,c=j;
            for(int k=0; k<6; k++)
            {
                if(r+dirr[k]<0 || c+dirc[k]<0) continue;
                int nd=ara[r+dirr[k]][c+dirc[k]];

                if(nd!=0)
                adj[ara[r][c]].push_back(nd);
            }
        }
    }


//    for(int i=0;i<maxN;i++)
//    {
//        printf("%d->",i);
//        for(int j=0;j<adj[i].size();j++)
//        {
//            printf("%d ",adj[i][j]);
//        }
//
//        puts("");
//
//    }



}

int dis[10009];
bool vis[10009];
void bfs(int src,int dest)
{
    dis[src]=0;
    vis[src]=1;

    if(src==dest) return;

    queue<int>q;
    q.push(src);

    while(!q.empty())
    {
        int u=q.front();
        q.pop();

        for(int i=0;i<adj[u].size();i++)
        {
            int nd=adj[u][i];

            if(vis[nd]==0)
            {
                vis[nd]=1;
                dis[nd]=dis[u]+1;


               // printf("%d %d= %d\n",u,nd,dis[nd]);

                if(nd==dest)
                    return ;
                q.push(nd);
            }
        }
    }
}

int main()
{

    Build();

    while(1){

    int a,b;
    cin>>a>>b;

    if(a==0 && b==0) break;

    dis[a]=0;
    bfs(a,b);

    cout<<dis[b]<<endl;

    memset(vis,0,sizeof vis);

    }

    return 0;

}
