#include<bits/stdc++.h>
#define pii pair<int,int>
#define i64 long long
using namespace std;
const int MAXN=500009;

vector<int>g[MAXN];
vector<pii>query[MAXN];
int sz[MAXN],lvl[MAXN],mask[MAXN], letter[MAXN],res[MAXN];
bool big[MAXN];


void dfsSize(int v,int p)
{
    sz[v]=1;
    for(auto u:g[v])
        if(u!=p)
            dfsSize(u,v), sz[v]+=sz[u], lvl[u]=lvl[v]+1;
}


void add(int v, int p)
{

    mask[lvl[v]]^=(1<<letter[v]);

    for(auto u:g[v])
        if(u!=p && !big[u])
            add(u,v);

}

void calc_res(int nd)
{
    printf("Node=%d\n",nd);
    for(int i=0; i<query[nd].size(); i++)
    {
        int h=query[nd][i].first;
        int q=query[nd][i].second;

        printf("h=%d q=%d mask=%d\n",h,q,mask[h]);

        int ones=__builtin_popcount(mask[h]);
        if(ones==0 || ones==1)
            res[q]=1;
    }
}

void dfs(int v, int p, int keep)
{
    int mxx=-1,bigChild=-1;
    for(auto u: g[v])
        if(sz[u]>mxx && u!=p)
            mxx=sz[u],bigChild=u;

    for(auto u:g[v])
        if(u!=p && u!=bigChild)
            dfs(u,v,0);

    if(bigChild!=-1)
        dfs(bigChild,v,1),big[bigChild]=1;

    add(v,p);   ///this contains the result of the node
    calc_res(v);

    if(bigChild!=-1)
        big[bigChild]=0;

    if(keep==0)
        add(v,p);

}

int main()
{
    int n,m,p,v,h;
    cin>>n>>m;
    for(int i=2; i<=n; i++)
    {
        scanf("%d",&p);
        g[p].push_back(i);
    }

    string str;
    cin>>str;
    for(int i=0; i<n; i++)
        letter[i+1]=str[i]-'a';

    for(int i=0; i<m; i++)
    {
        cin>>v>>h;
        query[v].push_back({h,i});
    }

    lvl[1]=1;
    dfsSize(1,-1);

    dfs(1,-1,1);


    for(int i=0; i<m; i++)
        if(res[i]==1) printf("Yes\n");
        else printf("No\n");





    return 0;
}
