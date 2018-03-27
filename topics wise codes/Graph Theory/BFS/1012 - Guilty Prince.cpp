#include<bits/stdc++.h>
#define par pair<int,int>
#define ms(a,b) memset(a,b,sizeof a);
using namespace std;
int w,h;
int dirr[]={-1, 1, 0, 0};
int dirc[]={ 0, 0, 1,-1};
int vis[23][23],mat[23][23];
int bfs(pair<int,int>src)
{

    queue<pair<int,int> >q;

    q.push(src);

    vis[src.first][src.second]=1;
    int total=1;

    while(!q.empty())
    {
        par u= q.front();
        q.pop();

        for(int i=0;i<4;i++)
        {
            par node;
            node= { u.first+dirr[i] , u.second+dirc[i] };

            if(vis[node.first][node.second]==0 && mat[node.first][node.second]=='.' &&  node.first<=h && node.first>=1 && node.second>=1 && node.second<=w)
            {
                vis[node.first][node.second]=1;
                total++;
                q.push(node);
            }
        }

    }

    return total;

}

int main()
{
    int t=0,test;
    cin>>test;

    while(t<test){


    scanf("%d %d",&w,&h);

    getchar();
    pair<int,int>store;
    for(int i=1;i<=h;i++)
    {
        for(int j=1;j<=w;j++)
        {
            scanf("%c",&mat[i][j]);
            if(mat[i][j]=='@')
            store= {i,j};
        }
        getchar();
    }

    printf("Case %d: %d\n",++t,bfs(store));
    ms(vis,0);
    ms(mat,0);

    }
    return  0;
}
