///http://codeforces.com/problemset/problem/793/B
#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
int n,m;
int dr[] = { -1, 0, 1, 0 };
int dc[]=  { 0, 1, 0, -1};
char grid[1009][1009];
int T[1009][1009];

struct node
{
    int x,y,turn,dir;


    bool operator < (const node &n) const
    {

        return turn > n.turn;
    }
};
node Start, End;


void dijkstra(pii src)
{

    for(int i = 0; i <n; i++)
        for(int j=0; j<m; j++) T[i][j] = 100;

    T[src.first][src.second] = 0;

    priority_queue <node> pq;
    pq.push({src.first, src.second,0,0});
    pq.push({src.first,src.second,0,1});

    while(!pq.empty())
    {
        node u= pq.top();
        pq.pop();
        //if(vis[u.city]==1) continue;
        for(int i = 0; i < 4; i++)
        {



            int x=u.x+ dr[i];
            int y=u.y+ dc[i];
            int cturn= u.turn;

            if(grid[x][y]!='*' && x>=0 && x<n && y>=0 && y<m)
            {
                if(u.dir==0 && abs(dc[i])==1)
                {
                    cturn++;
                    if(cturn<=T[x][y])
                    {
                        T[x][y]=cturn;
                        pq.push({x,y,cturn, 1});
                    }

                }
                else if(u.dir==1 && abs(dr[i])==1)
                {
                    cturn++;
                    if(cturn<=T[x][y])
                    {
                        T[x][y]=cturn;
                        pq.push({x,y,cturn, 0});
                    }

                }
                else
                {
                    if(cturn<T[x][y])
                    {
                        T[x][y]=cturn;
                        pq.push({x,y,cturn, abs(dc[i])});
                    }
                }
            }

        }
    }
}

void print()
{
     for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]!='*')
                printf("%d ",T[i][j]);
            else printf("-1 ");

        }
        puts("");
    }

}

int main()
{

    cin>>n>>m;
    getchar();

    pii temp, dst;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            scanf("%c",&grid[i][j]);
            if(grid[i][j]=='S')
                temp= {i,j};
            else if(grid[i][j]=='T')
                dst= {i,j};
        }
        getchar();
    }




    dijkstra(temp);

    //print();

    if(T[dst.first][dst.second]<=2) printf("YES\n");
    else printf("NO\n");



    return 0;
}
