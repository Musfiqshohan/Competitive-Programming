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
int tot_idx;

vector<int>adj[maxN];
int Level[maxN], par[maxN][maxL+9];
vector<int>vec;
int genie[maxN];
pii indx[maxN];

int Bit[maxN*2+10];

void clearr(int n)
{
    for(int i=0; i<n; i++)
        adj[i].clear();

    ms(Level,0);
    ms(par,-1);
    vec.clear();
    ms(genie,0);
    ms(indx,0);

    ms(Bit,0);

}

void dfs(int src, int pr)
{
    update(tot_idx,2*n,genie[src]);
    indx[src].first=tot_idx++;

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

    update(tot_idx,2*n,-genie[src]);
    indx[src].second=tot_idx++;
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


void update(int idx, int n ,int v)
{
    while(idx<=n)
    {
        bit[idx]+=v;
        idx+=(idx&-idx);
    }
}

void query(int idx, int n)
{
    int sum=0;
    while(idx>0)
    {
        sum+=Bit[idx];
        idx-=(idx&-idx);
    }
    return sum;
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

        tot_idx=0;
        for(int i=0; i<=maxN*2+5; i++)
            Bit[i]=INT_MAX;

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
                r1=query(indx[x].first,2*n);
                r2=query(indx[y].first, 2*n);
                r3=query(indx[rt].first, 2*n);
                res= r1+r2-2*r3+genie[rt];
                printf("%d\n",res);

            }
            else
            {




                update(indx[x].first, x*2, y);
                update(indx[x].second, -1,-y);
            }
        }


        clearr(n);
    }
    return 0;
}

