///http://codeforces.com/problemset/problem/60/B
#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<int,int>
#define inf 100000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;


char str [12][12][12];

struct node
{
    int h,r,c;
};

int dh[]= {0,0,0,0, 1, -1 };
int dr[]= {-1,0,1,0,0,  0  };
int dc[]= { 0,1,0,-1,0, 0  };

int vis[12][12][12];
int k,n,m;
int total=0;
void bfs(node src)
{
    vis[src.h][src.r][src.c]=true;

    total=1;
    queue<node>q;
    q.push(src);

    while(!q.empty())
    {
        node u=q.front();
        q.pop();

        for(int i=0; i<6; i++)
        {
            int x=u.h+ dh[i], y=u.r+dr[i], z=u.c+dc[i];

            if(vis[x][y][z]==false && x>=0 && x<k && y>=0 && y<n && z>=0 && z<m && str[x][y][z]=='.')
            {
                vis[x][y][z]=true;
                total++;
                q.push({x,y,z});

            }
        }

    }


}
int main()
{

    cin>>k>>n>>m;
    getchar();

    for(int i=0; i<k; i++)
    {
        for(int j=0; j<n; j++)
        {
            scanf("%s",&str[i][j]);
        }
    }

    int rr,cc;
    scanf("%d %d",&rr,&cc);

    bfs({0,rr-1,cc-1});

    cout<<total<<endl;



    return 0;
}
