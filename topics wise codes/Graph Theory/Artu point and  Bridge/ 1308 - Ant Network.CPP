#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define llu unsigned long long
#define pii pair<llu,llu>
#define inf 100000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
using namespace std;

vector<llu>adj[10009];
llu discTime=0, low[10009], disc[10009],connectedAp,numberofcomp, cnt=0, used[10009];
bool isAp[10009];

void clearr(int n)
{
    for(int i=0;i<n;i++) adj[i].clear();
    ms(low,0);
    ms(disc,0);
    cnt=0;
    ms(used,0);
    ms(isAp,0);
}

void dfs_findAp(llu src, llu parent)
{
    low[src]= disc[src]= ++ discTime;

    llu child=0;

    for(llu i=0;i<adj[src].size();i++)
    {
        llu node= adj[src][i];

        if(!disc[node])
        {
            child++;

            dfs_findAp(node, src);

            low[src]= min(low[src], low[node]);

            if(parent==-1 && child>1)    isAp[src]=true;
            if(parent!=-1 && low[node]>=disc[src])  isAp[src]=true;


        }
        else if( node!=parent)
        {
            low[src]= min(low[src], disc[node]);
        }

    }
}

void dfs_traverse(llu src)
{
    ++cnt;
    used[src]=1;
    for(llu i=0;i<adj[src].size();i++)
    {
        llu node = adj[src][i];

        if(used[node]==0 && !isAp[node])
        {
            dfs_traverse(node);
        }
        else if(isAp[node] && used[node]!=numberofcomp)
        {
            ++connectedAp;
            used[node]=numberofcomp;
        }
    }
}

int main()
{
     llu tt=0,test;
    cin>>test;

    while(tt<test) {


    llu n,m,u,v;
    scanf("%lld %lld",&n,&m);

    for(llu i=0;i<m;i++)
    {
        scanf("%lld %lld",&u,&v);

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs_findAp(0,-1);


    llu total=1,shaft=0;
    numberofcomp=0;


    for(llu i=0;i<n;i++)
    {
        if(used[i]==0 && !isAp[i])
        {
            cnt=0,connectedAp=0;
            ++numberofcomp;
            dfs_traverse(i);

            if(connectedAp<2)
            {
                shaft++;
                total*= cnt;
            }

        }
    }

  //  cout<<shaft<<endl;
    if(shaft==1)
    {
        ++shaft;

        total= (n*(n-1)) /2;
    }

    printf("Case %lld: %llu %llu\n",++tt,shaft,total);
    clearr(n);

    }
    return 0;
}
