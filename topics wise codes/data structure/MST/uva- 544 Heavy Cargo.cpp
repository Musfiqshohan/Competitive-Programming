#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
#define ll long long
using namespace std;

map<string, int>mp;


vector<int>adj[20000];
vector<int>edge[20000];

int par[20000];
int minim[20000];
int vis[20000];
struct tripple
{
    int u, v, w;
} tra[20000];

void clearr()
{
    ms(vis,0);
    mp.clear();
    ms(par,-1);


}

bool compare(tripple a, tripple b)
{
        return a.w>b.w;
}

int findd(int r)
{
    if(par[r]==r) return r;

    return par[r]=findd(par[r]);
}


void unionn(tripple temp)
{
    int u= findd(temp.u);
    int v= findd(temp.v);

    if(u!=v)
    {
        par[u]=v;

      //  printf("%d %d\n",temp.u, temp.v);

        adj[temp.u].push_back(temp.v);
        edge[temp.u].push_back(temp.w);

        adj[temp.v].push_back(temp.u);
        edge[temp.v].push_back(temp.w);


    }

}

void bfs(int src)
{
    queue<int>q;
    q.push(src);
    vis[src]=1;


    while(!q.empty())
    {
        int u=q.front();
        q.pop();

        for(int i=0;i<adj[u].size();i++)
        {
            int node= adj[u][i];

            if(vis[node]==0)
            {
                vis[node]=1;

                minim[node]=min(minim[u],edge[u][i]);

            //    printf("node %d %d\n",node,edge[u][i]);
                q.push(node);

            }
        }
    }
}

int main()
{
    int test=0;
    while(1){


    int n,r;
    string s1,s2;

    scanf("%d %d",&n,&r);
    if(n==0 && r==0) break;


    int cnt=1;
    for(int i=0; i<r; i++)
    {

        int w;
        cin>>s1>>s2>>w;

        if(mp[s1]==0)
            {
                par[cnt]=cnt;
                mp[s1]=cnt++;
            }


        if(mp[s2]==0)
            {
                par[cnt]=cnt;
                mp[s2]=cnt++;
            }

        tra[i].u=mp[s1];    tra[i].v=mp[s2]; tra[i].w=w;

    }


    sort(tra,tra+r, compare);



    for(int i=0;i<r;i++)
    {
        unionn(tra[i]);
    }

    cin>>s1>>s2;

    for(int i=0;i<cnt;i++) minim[i]=10009;


    bfs(mp[s1]);

   // cout<<minim[mp[s2]]<<endl;
    printf("Scenario #%d\n",++test);
    printf("%d tons\n",minim[mp[s2]]);
    puts("");

    clearr();
    for(int i=0;i<cnt;i++) adj[i].clear();
    for(int i=0;i<cnt;i++) edge[i].clear();

    }

    return 0;
}



