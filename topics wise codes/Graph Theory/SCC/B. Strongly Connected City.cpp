///http://codeforces.com/problemset/problem/475/B
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

char dirR[22], dirC[22];
vector<int>adj[500], Radj[500];
int n,m;
int vis[500];
stack<int>stk;

void make_graph1(int row, int type)
{
    int init=row*m;
    if(type==-1)
    {
        for(int i=m-1; i>0; i--)
        {
            adj[init+i].push_back(init+i-1);
            Radj[init+i-1].push_back(init+i);
        }
    }
    else if(type == 1)
    {
        for(int i=0; i<m-1; i++)
        {
            adj[init+i].push_back(init+i+1);
            Radj[init+i+1].push_back(init+i);

        }
    }

}

void make_graph2(int col, int type)
{

    int init=col;

 //   printf("%d %d %d\n",col, type, init);
    if(type==-1)
    {
        int last=col+(n-1)*m;
        for(int i=col; i<last; i+=m)
        {
            adj[i].push_back(i+m);
            Radj[i+m].push_back(i);
        }

    }
    else
    {
        int last=col+(n-1)*m;
        for(int i=last; i>col; i-=m)
        {
            adj[i].push_back(i-m);
            Radj[i-m].push_back(i);
        }
    }
}

void dfs(int src, vector<int>edge[])
{
    vis[src]=1;
    for(int i=0; i<edge[src].size(); i++)
    {
        int node= edge[src][i];
        if(vis[node]==0)
        {
           // printf("%d -> %d\n",src,node);
            dfs(node,edge);
        }
    }

    stk.push(src);

}


int main()
{

    scanf("%d %d",&n,&m);

    getchar();
    scanf("%s",&dirR);

    scanf("%s",&dirC);






    for(int i=0; i<n; i++)
    {
        if(dirR[i]=='<')
            make_graph1(i,-1);
        else make_graph1(i,1);
    }

    for(int i=0; i<m; i++)
    {
        if(dirC[i]=='v')
            make_graph2(i,-1);
        else
            make_graph2(i,1);
    }

//    for(int i=0;i<26;i++)
//    {
//        printf("%d ->",i);
//        for(int j=0;j<adj[i].size();j++)
//            printf("%d ",adj[i][j]);
//        puts("");
//    }

    int cnt=0;

   // dfs(0,adj);
    for(int i=0; i<(n*m)-1; i++)
    {
        if(vis[i]==0)
        {
            dfs(i,adj);
            cnt++;

            if(cnt>1)
            {
                printf("NO\n");
                return 0;
            }
        }

    }


    ms(vis,0);
    cnt=0;
    stack<int>stk2;
    stk2=stk;

    while(!stk2.empty())
    {
        int src= stk2.top();
        stk2.pop();

        if(vis[src]==0)
        {
            dfs(src,Radj);
            cnt++;

            if(cnt>1)
            {
                printf("NO\n");
                return 0;
            }

        }
    }

    printf("YES\n");





    return 0;
}

