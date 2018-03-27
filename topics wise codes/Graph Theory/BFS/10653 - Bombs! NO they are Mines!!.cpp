#include<bits/stdc++.h>
using namespace std;
int vis[1009][1009], level[1009][1009], adj[1009][1009];
int dirx[4]={0, 0, -1, 1};
int diry[4]={-1,1,  0,  0};
int r,c;
struct cell
{
    int xpos, ypos;

};
void bfs(cell source)
{
    queue<cell>q;

    vis[source.xpos][source.ypos]=1;
    level[source.xpos][source.ypos]=0;
    q.push(source);

    while(!q.empty())
    {
        cell u=q.front();
        q.pop();

        for(int i=0;i<4;i++)
        {

            cell node= {u.xpos+diry[i] , u.ypos+dirx[i]};
            //printf("(%d,%d) -> (%d,%d)  %d %d\n\n",u.xpos,u.ypos,node.xpos,node.ypos,dirx[i],diry[i]);

            if(adj[node.xpos][node.ypos]==0 && vis[node.xpos][node.ypos]==0 && (node.xpos>=0 && node.xpos<r) && (node.ypos>=0 && node.ypos<c))
            {
                vis[node.xpos][node.ypos]=1;
                level[node.xpos][node.ypos]=level[u.xpos][u.ypos]+1;
                q.push(node);
            }
        }
    }

}

void init()
{
    memset(vis,0,sizeof vis);
    memset(level,0,sizeof level);
    memset(adj,0,sizeof adj);
}
int main()
{


    while(1){

    int i,j,bombs,x,num,sx,sy,ex,ey,y;

    scanf("%d %d",&r,&c);
    if(r==0 && c==0) break;

    scanf("%d",&bombs);

    for(i=0;i<bombs;i++)
    {
        scanf("%d %d",&x,&num);

        for(j=0;j<num;j++)
        {
            scanf("%d",&y);
            adj[x][y]=1;
        }
    }

    scanf("%d %d",&sx, &sy);
    scanf("%d %d",&ex, &ey);

    cell start={sx,sy};

    bfs(start);

    cout<<level[ex][ey]<<endl;

    init();


    }

    return 0;

}
