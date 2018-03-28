#include<bits/stdc++.h>
#define pii pair<int,int>
#define i64 long long
using namespace std;
const int MAXN=100009;

map<string,int>mp1;
map<pii,int>mp2;
map<int,int>uniqmp;
vector<int>g[MAXN],root;
vector<pii>query[MAXN];
set<int>Uniq[MAXN];
int sz[MAXN],lvl[MAXN],col[MAXN],res[MAXN];
bool big[MAXN];

void dfsSize(int v,int p)
{
    sz[v]=1;
    for(auto u:g[v])
        if(u!=p)
            lvl[u]=lvl[v]+1, dfsSize(u,v), sz[v]+=sz[u];
}


void update(int v, int x)
{
    pii t= {lvl[v],col[v]};
    mp2[t]+=x;

    if(mp2[t]==1 && x==1)
        uniqmp[lvl[v]]++;
    if(mp2[t]==0 && x==-1)
        uniqmp[lvl[v]]--;



//    printf("nd=%d  h=%d col=%d  isthere=%d tot=%d\n",v,lvl[v],col[v], mp2[t], uniqmp[lvl[v]]);

}

void add(int v,int p, int x)
{
    update(v,x);

    for(auto u:g[v])
        if(u!=p && !big[u])
            add(u,v,x);
}


void calc_res(int v)
{
    for(auto u:query[v])
    {
        res[u.second]=uniqmp[{u.first}];
       // printf("nd=%d  h=%d  res=%d\n",v,u.first,res[u.second]);
    }

}

void dfs(int v, int p, int keep)
{
    int mxx=-1,bigChild=-1;
    for(auto u:g[v])
        if(u!=p && sz[u]>mxx)
            mxx=sz[u], bigChild=u;

    for(auto u: g[v])
        if(u!=p && u!=bigChild)
            dfs(u,v,0);
    if(bigChild!=-1)
        dfs(bigChild,v,1), big[bigChild]=1;

   // printf("start adding for nd %d\n",v);
    add(v,p,1);   /// this is result for node v

    calc_res(v);

    big[bigChild]=0;

    if(keep==0){
      //  printf("start removing for nd=%d\n",v);
        add(v,p,-1);
    }
}
int main()
{
    int n,p;
    cin>>n;

    string str;
    int cnt=0;
    for(int i=1; i<=n; i++)
    {
        cin>>str>>p;
        if(mp1.find(str)==mp1.end())
            mp1[str]=++cnt;

        col[i]=mp1[str];

        g[p].push_back(i);
        if(p==0)
            root.push_back(i);
    }

    for(int i=0; i<root.size(); i++)
    {
        lvl[root[i]]=1;
        dfsSize(root[i],-1);
    }


    int m,v,k;
    cin>>m;
    for(int i=0; i<m; i++)
    {
        cin>>v>>k;
        query[v].push_back({lvl[v]+k,i});
    }


    for(int i=0; i<root.size(); i++)
    {
      //  printf("STARTING FROM ANOTHER ROOT\n");
        dfs(root[i],-1,0);

    }

    for(int i=0; i<m; i++)
        printf("%d\n",res[i]);

    return 0;
}

