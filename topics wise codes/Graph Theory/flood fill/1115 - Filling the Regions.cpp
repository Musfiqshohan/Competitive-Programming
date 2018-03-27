#include<bits/stdc++.h>
using namespace std;
char str[60][60];
int vis[60][60];
int ara[200];
int dir_row[8]= {-1,1,0,0,-1,1, 1,-1};
int dir_col[8]= {0,0,-1,1, 1,1, -1,-1};
int m,n;

struct data
{
    int row,col;
};
void BFS(data source,char target)
{
    queue<data>q;
    q.push(source);
    vis[source.row][source.col]=1;

    while(!q.empty())
    {
        data u=q.front();
        q.pop();

        for(int i=0; i<8; i++)
        {
            data node= {u.row+dir_row[i], u.col+ dir_col[i]};
            if(node.row>=0 && node.row<m && node.col>=0 && node.col<n && vis[node.row][node.col]==0 && str[node.row][node.col]!=target)
            {
                vis[node.row][node.col]=1;
                q.push(node);
            }
        }
    }

}
void print_map()
{
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
            printf("%c",str[i][j]);
        puts("");
    }
    //printf("Fuck\n");
}

void bfs_from_border(char target)
{
    int i;
    for(i=0; i<n; i++)
    {
        if(vis[0][i]==0 && str[0][i]!=target)
        {
            //  printf("from 0 %d\n",i);
            BFS({0,i},target);
        }
    }
    for(i=0; i<n; i++)
    {
        if(vis[m-1][i]==0 && str[m-1][i]!=target)
            BFS({m-1,i},target);
    }

    for(i=0; i<m; i++)
    {
        if(vis[i][0]==0 && str[i][0]!=target)
            BFS({i,0},target);
    }
    for(i=0; i<m; i++)
    {
        if(vis[i][n-1]==0 && str[i][n-1]!=target)
            BFS({i,n-1},target);
    }
}

void change_unvisited(char target)
{
    int i,j;
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {

            if(vis[i][j]==0)
                str[i][j]=target;
        }
    }

}
int main()
{
    int t=0,test;
    cin>>test;

    while(t<test){
    int i,j;

    scanf("%d %d",&m,&n);
    getchar();
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            scanf("%c",&str[i][j]);
            ara[str[i][j]]=1;
        }
        getchar();
    }


    for(i=65; i<=90; i++)
    {

        if(ara[i]==1)
        {
            bfs_from_border(i);
            change_unvisited(i);
            memset(vis,0,sizeof(vis));
           //  print_map();
        }
    }

    printf("Case %d:\n",++t);
    print_map();
    memset(vis,0,sizeof(vis));
    memset(str,0,sizeof(str));
    memset(ara,0,sizeof ara);

    }

    return 0;
}
