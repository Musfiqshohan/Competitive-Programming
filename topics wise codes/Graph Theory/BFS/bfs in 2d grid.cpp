#include<bits/stdc++.h>
#define pii pair<int , int>
using namespace std;
int fx[]= {1,-1,0,0};
int fy[]= {0, 0,1,-1};
int cell[100][100], vis[100][100], d[100][100];
int row,col;


void bfs(int sx, int sy)
{
    queue<pair<int, int>>q;
    pair<int, int> src = pair<int, int> (sx,sy);
    q.push(src);

    while(!q.empty())
    {
        pair<int, int> top;
        top= q.front();
        q.pop();

        for(k=0; k<4; k++)
        {
            sx= top.first + fx[k] ;
            sy= top.second+  fy[k];

            if(vis[sx][sy]==-1)
            {
                d[sx][sy] =
                vis[sx][sy]=1;
                q.push( pair<int, int>(sx,sy));

            }

        }
    }

}
int main()
{
    int n;
    cin>>n;

    row=n, col=n;
    bfs(1,1);

    return 0;
}
