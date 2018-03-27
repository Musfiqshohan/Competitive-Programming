#include<bits/stdc++.h>
using namespace std;
int n,m;
int dr[] = { -1, 0, 1, 0 };
int dc[]=  { 0, 1, 0, -1};
struct node
{
    int x,y;
};
node Start, End;

int vis[1009][1009];
char grid[1009][1009];
int dfs(node src, int dir, int change)
{
    //printf("%d,%d  %d  %d\n",src.x, src.y, dir, change);

    if(src.x==End.x && src.y==End.y )
        return 1;

    vis[src.x][src.y]=1;


    int t=0;

    for(int i=0; i<4; i++)
    {
        int x=src.x+ dr[i];
        int y=src.y+ dc[i];

        if(vis[x][y]==0 && grid[x][y]!='*' && x>=0 && x<n && y>=0 && y<m)
        {
            int difr= abs(x- src.x);
            int difc= abs(y- src.y);



            if(difr==1 && dir%2==1  && dir!=-1)
                t|=dfs({x,y}, 0, change+1);
            else if(difc==1 && dir%2==0 && dir!=-1)
                t|=dfs({x,y}, 1, change+1);
            else t|=dfs({x,y}, difc, change);

        }
    }


    return t;

}

int main()
{

    cin>>n>>m;
    getchar();



    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            scanf("%c",&grid[i][j]);
            if(grid[i][j]=='S')
                Start= { i,j };
            else if(grid[i][j]=='T')
                End= {i,j};
        }
        getchar();
    }


    int t0=0;

    t0=dfs(Start, -1,0);


    if(t0>0) printf("YES\n");
    else printf("NO\n");



    return 0;
}
