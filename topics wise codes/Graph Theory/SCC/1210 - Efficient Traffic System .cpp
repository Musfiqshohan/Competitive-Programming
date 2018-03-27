#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<int,int>

using namespace std;
int start=0,scc=0;

vector< pii > vec;
int outdegree[20009], indegree[20009],finish[20009], belong[20009], vis[20009];

void clearr()
{
    ms(outdegree,0);
    ms(indegree,0);
    ms(vis,0);
    scc=0;
    start=0;
}


void dfs1(int src, vector<int>adj[], int turn)
{

    ++start;

    for(int i=0; i<adj[src].size(); i++)
    {
        int node= adj[src][i];
        if(vis[node]==0)
        {
            vis[node]=1;
            dfs1(node,adj,turn);

            if(turn==2)
            {
                belong[node]=scc;
                //  printf("->%d== %d<-\n",src,scc);
            }

        }

    }

    finish[src]=++start;

}

void dfs2(int src, vector<int>adj[] )
{

    for(int i=0; i<adj[src].size(); i++)
    {
        int node= adj[src][i];

        if(belong[src]!=belong[node])
        {
            //  printf("%d -> %d\n",src,node);
            outdegree[belong[src]]++;
            indegree[belong[node]]++;
        }

        if(vis[node]==0)
        {
            vis[node]=1;
            dfs2(node,adj);

        }
    }

}

bool compare(pii a, pii b)
{
    return a.first>b.first;
}


int main()
{

    int t=0,test;
    cin>>test;

    while(t<test)
    {

        vector<int>adj1[20009], adj2[20009];
        int n,m,u,v;
        scanf("%d %d",&n,&m);

        for(int i=0; i<m; i++)
        {
            scanf("%d %d",&u,&v);
            adj1[u].push_back(v);
            adj2[v].push_back(u);
        }


        for(int i=1; i<=n; i++)
        {
            if(vis[i]==0)
            {
                dfs1(i,adj1,1);
            }
        }

        for(int i=1; i<=n; i++)
            vec.push_back({finish[i],i});

        sort(vec.begin(), vec.end(), compare);

        ms(vis,0);

        scc=0;

        for(int i=0; i<vec.size(); i++)
        {
            int src= vec[i].second;

            if(vis[src]==0)
            {
                vis[src]=1;
                scc++;
                belong[src]=scc;

                dfs1(src,adj2,2);
            }

        }


        ms(vis,0);

        for(int i=1; i<=n; i++)
        {
            if(vis[i]==0)
            {
                vis[i]=1;
                dfs2(i, adj1);
            }
        }



        int out=0,in=0;
        for(int i=1; i<=scc && scc>1 ; i++)
        {
            if(outdegree[i]==0) out++;
            if(indegree[i]==0) in++;

        }


        printf("Case %d: %d\n",++t, max(in,out));

        clearr();

        for(int i=0;i<=n;i++) { adj1[i].clear(); adj2[i].clear(); }
        vec.clear();

    }

    return 0;
}

