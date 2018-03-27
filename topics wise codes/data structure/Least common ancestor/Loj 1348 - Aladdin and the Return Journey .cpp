///http://www.lightoj.com/volume_showproblem.php?problem=1348
#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define i64 long long
#define pii pair<i64,i64>
#define inf 100000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
#define rep(i,n) for(i64 i=0;i<n;i++)
using namespace std;
const int maxL=18;  ///log2(2*1e5)
const int maxN=30009;

vector<int>adj[maxN];
int Level[maxN], par[maxN][maxL+9];
vector<int>vec;
int genie[maxN];
pii indx[maxN];

int T[maxN*8+9];

void clearr(int n)
{
    for(int i=0; i<n; i++)
        adj[i].clear();

    ms(Level,0);
    ms(par,-1);
    vec.clear();
    ms(genie,0);
    ms(indx,0);

    ms(T,0);

}

void dfs(int src, int pr)
{

    vec.push_back(+genie[src]);
    indx[src].first=vec.size()-1;

    for(int i=0; i<adj[src].size(); i++)
    {
        int node=adj[src][i];
        if(node!=pr)
        {
            Level[node]=Level[src]+1;
            par[node][0]=src;
            dfs(node,src);
        }
    }

    vec.push_back(-genie[src]);
    indx[src].second=vec.size()-1;
}


void precomputeSparse(int N)
{
    for(int i=1; i<=maxL; i++)
    {
        for(int u=0; u<N; u++)
        {
            if(par[u][i-1]!=-1)
            {
                par[u][i]= par[ par[u][i-1] ][i-1];
            }
        }
    }
}


int getLca(int u, int v)
{

    if(Level[u]<Level[v])
        swap(u,v);

    int dif=Level[u]-Level[v];

    for(int i=maxL; i>=0; i--)
    {
        int d=1<<i;
        if(dif>=d)
        {
            dif-=d;
            u=par[u][i];
        }
    }

    if(u==v)
        return u;


    for(int i=maxL; i>=0; i--)
    {
        if(par[u][i]!=par[v][i])
            u=par[u][i], v=par[v][i];
    }

    return par[u][0];
}


void build(int nd, int b, int e)
{
    if(b==e)
    {
        T[nd]=vec[b];
        return;
    }

    int mid=(b+e)/2;
    int lc=nd*2;
    int rc=(nd*2)+1;

    build(lc,b,mid);
    build(rc,mid+1,e);

    T[nd]=T[lc]+T[rc];
}

void update(int nd, int b, int e, int x, int pos, int v)
{
    if(b==e)
    {
        T[nd]=v;
        if(pos!=-1)
        genie[pos]=v;
        return ;
    }

    int mid=(b+e)/2;
    int lc=nd*2;
    int rc=(nd*2)+1;

    if(x<=mid)
        update(lc,b,mid,x, pos,v);
    else update(rc, mid+1,e, x, pos,v);

    T[nd]=T[lc]+T[rc];
}

int query(int nd, int b, int e, int l, int r)
{
    if(b>r || e<l)
        return 0;

    if(b>=l && e<=r)
    {
        return  T[nd];
    }

    int mid=(b+e)/2;
    int lc=nd*2;
    int rc=nd*2+1;

    int t1=query(lc,b,mid,l,r);
    int t2=query(rc,mid+1,e,l,r);

    return t1+t2;
}

int main()
{
    int tt=0,test;
    cin>>test;
    while(tt<test)
    {
        printf("Case %d:\n",++tt);

        int n,u,v,q,cs,x,y;
        scanf("%d",&n);
        for(int i=0; i<n; i++)
            scanf("%d",&genie[i]);

        for(int i=0; i<n-1; i++)
        {
            scanf("%d %d",&u,&v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        ms(par,-1);
        dfs(0,-1);   /// 1 no step
        precomputeSparse(n); /// 2 no step

        int vL=vec.size();
        build(1,0,vL-1);
        scanf("%d",&q);

        while(q--)
        {
            scanf("%d %d %d",&cs,&x,&y);
            if(cs==0)
            {
                int rt,r1,r2,r3,res;
                rt=getLca(x,y);
                r1=query(1,0,vL-1, indx[rt].first, indx[x].first);
                r2=query(1,0,vL-1, indx[rt].first, indx[y].first);
                r3=genie[rt];
                res= r1+r2-r3;
                printf("%d\n",res);

            }
            else
            {
                update(1,0,vL-1, indx[x].first, x, y);
                update(1,0,vL-1, indx[x].second, -1,-y);
            }
        }


        clearr(n);
    }
    return 0;
}
