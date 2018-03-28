///https://vjudge.net/contest/217872#problem/C
#include<bits/stdc++.h>
#define pii pair<int,int>
#define i64 long long
using namespace std;
const int MAXN=100009,maxL=20;

vector<int>g[MAXN],root;
vector<pii>query[MAXN];
int sz[MAXN],lvl[MAXN],pr[MAXN][32],ara[MAXN],res[MAXN];
bool big[MAXN];

void dfsSize(int v,int p)
{
    sz[v]=1;
    for(auto u: g[v])
        if(u!=p)
            lvl[u]=lvl[v]+1, dfsSize(u,v), sz[v]+=sz[u];
}




int getPpr(int v,int d)
{
    for(int i=maxL;i>=0;i--)
    {
        int r=1<<i;
        if(r<=d)
            v=pr[v][i], d-=r;
    }
    return v;
}


void add(int v,int p,int x)
{
    ara[lvl[v]]+=x;

    for(auto u:g[v])
        if(u!=p && !big[u])
            add(u,v,x);

}


void calc_res(int v)
{
    for(auto u:query[v])
    {
        res[u.second]=ara[u.first]-1;
        //printf("nd= %d  lvl=%d res=%d\n",v, u.first, res[u.second] );
    }
}
void dfs(int v,int p ,int keep)
{
    int mxx=-1,bigChild=-1;
    for(auto u:g[v])
        if(u!=p && sz[u]>mxx)
            mxx=sz[u], bigChild=u;

    for(auto u:g[v])
        if(u!=p && u!=bigChild)
            dfs(u,v,0);

    if(bigChild!=-1)
        dfs(bigChild,v,1), big[bigChild]=1;


    add(v,p,1); /// calc result for node v
    calc_res(v);

    big[bigChild]=0;

    if(keep==0)
        add(v,p,-1);

}



int main()
{


    int n,p,v;
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        cin>>p;
        g[p].push_back(i);
        pr[i][0]=p;
        if(p==0)
            root.push_back(i);
    }


    for(int i=1;i<=maxL;i++)
    {
        for(int u=1;u<=n;u++)
            pr[u][i]=pr[ pr[u][i-1] ][i-1];
    }

    for(int i=0;i<root.size();i++)
    {
        lvl[root[i]]=1;
        dfsSize(root[i],-1);
    }

    int m;
    cin>>m;

    for(int i=0;i<m;i++)
    {
        cin>>v>>p;
        v=getPpr(v,p);
//        if(v==0)
//            res[i]=-1;
       // printf("v=%d\n",v);

        query[v].push_back({lvl[v]+p,i});
       // printf("v=%d h= %d \n",v,lvl[v]+p);
    }


    for(int i=0;i<root.size();i++)
    {
        dfs(root[i],-1,0);
    }


    for(int i=0;i<m;i++)
        printf("%d ",res[i]);

    puts("");



    return 0;

}
