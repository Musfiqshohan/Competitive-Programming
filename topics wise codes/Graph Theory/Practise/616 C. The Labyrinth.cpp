#include<bits/stdc++.h>
using namespace std;


int dr[] = { -1, 0, 1, 0 };
int dc[]=  { 0, 1, 0, -1};
struct node
{
    int x,y;
};

vector<node>vec;
int vis[1009][1009], belongs[1009][1009], store[1000009];
char grid[1009][1009];
int n,m;

int dfs(node src, int com)
{
    vis[src.x][src.y]=1;
    belongs[src.x][src.y]=com;

    int tot=0;
    for(int i=0; i<4; i++)
    {
        int x=src.x+dr[i];
        int y=src.y+dc[i];

        if(vis[x][y]==0 && grid[x][y]=='.' && x>=0 && x<n && y>=0 && y<m)
        {
            tot+=dfs({x,y},com);
        }
    }
    return tot+1;
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

            if(grid[i][j]=='*')
                vec.push_back({i,j});

        }

        getchar();

    }



    int cnt=0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(vis[i][j]==0 && grid[i][j]=='.')
            {
                cnt++;
                store[cnt]=dfs({i,j}, cnt);
                //cout<<i<<" "<<j<< " "<<store[cnt]<<endl;

            }
        }
    }


    set<int>Set;
    set<int>::iterator it;
    for(int i=0; i<vec.size(); i++)
    {
        int x=vec[i].x, y= vec[i].y;

        if(x-1>=0)
        Set.insert(belongs[x-1][y]);
        if(y-1>=0)
        Set.insert(belongs[x][y-1]);
        if(x+1<n)
        Set.insert(belongs[x+1][y]);
        if(y+1<m)
        Set.insert(belongs[x][y+1]);

        int tot=1;
        for(it=Set.begin() ; it!=Set.end(); it++)
        {
            int com= (*it);
            tot+= store[com];
        }

        int res= tot%10;
        grid[x][y]=res+'0';

        Set.clear();
    }


    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            printf("%c",grid[i][j]);

        puts("");
    }


    return 0;
}
