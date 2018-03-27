///http://codeforces.com/problemset/problem/543/B
#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

vector<int>adj[3009];

int dis[3009][3009], vis[3009][3009];





void bfs(int root, int src)
{

    vis[root][src]=1;
    dis[root][src] = 0;
    queue<int>q;
    q.push(src);

    while(!q.empty())
    {

        int u= q.front();
        q.pop();

        for(int i = 0; i < adj[u].size(); i++)
        {
            int node= adj[u][i];

            if(vis[root][node]==0)
            {
                vis[root][node]=1;
                dis[root][node]= dis[root][u]+1;
                q.push(node);
            }

        }
    }
}

/*
6 5
1 2
2 3
3 4
3 5
2 6
1 4 3
5 6 3*/





int main()
{
    int n,m,u,v,s1,t1,s2,t2,l1,l2;
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cin>>s1>>t1>>l1;
    cin>>s2>>t2>>l2;

    // puts("Hi");


    for(int i=1; i<=n; i++)
    {
        bfs(i,i);
    }

    int mx=-1;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            int tot1= dis[s1][i] + dis[j][t1] + dis[i][j];
            int tot2= dis[s2][i] + dis[j][t2] + dis[i][j];

            if(tot1<=l1 && tot2<=l2)
            {
                int  total= dis[s1][i] + dis[s2][i] + dis[j][t1] + dis[j][t2]+  dis[i][j];

                mx= max(mx, m-total);
            }

            tot1= dis[s1][i] + dis[j][t1] + dis[i][j];
            tot2= dis[s2][j] + dis[i][t2] + dis[i][j];

            if(tot1<=l1 && tot2<=l2)
            {
                int  total= dis[s1][i] + dis[s2][i] + dis[j][t1] + dis[j][t2]+  dis[i][j];

                mx= max(mx, m-total);
            }



        }

    }



    if(dis[s1][t2]<=l1 && dis[s2][t2]<=l2)
    {
        int ret= dis[s1][t1]+ dis[s2][t2];
        mx= max(mx, m-ret);
    }



    cout<<mx<<endl;


    return 0;
}
