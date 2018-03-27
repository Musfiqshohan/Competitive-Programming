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

const int MAXN=100009,maxL=20;
vector<int>adj[MAXN],dist[MAXN];
int cnt[MAXN],vis[MAXN], spent,Level[MAXN], par[MAXN][maxL+5],start[MAXN];

void print(vector<int>vec)
{
    puts("Start");
    for(int i=0; i<vec.size(); i++)
        printf("%d ",vec[i]);

    puts("End");
}


int dfs(int src)
{
    vis[src]=1;

    start[src]=++spent;
    dist[Level[src]].push_back(start[src]);

    int tot=0;
    for(int i=0; i<adj[src].size(); i++)
    {
        int node=adj[src][i];

        if(vis[node]==0)
        {
            par[node][0]=src;
            Level[node]=Level[src]+1;
            tot+=dfs(node);
        }
    }

    return cnt[src]=tot+1;
}

void precomputeSparse(int N)
{
    for(int i=1; i<=maxL; i++)
    {
        for(int u=1; u<=N; u++)
        {
            if(par[u][i-1]!=-1)
            {
                par[u][i]= par[ par[u][i-1] ][i-1];

                //printf("u=%d %dth= par=%d\n",u,i,par[u][i]);
            }
        }
    }
}


int f(int u,int dif)
{

    for(int i=maxL; i>=0; i--)
    {
        int d=1<<i;
        if(dif>=d)
        {
            dif-=d;
            u=par[u][i];
            //  printf("->%d %d\n",i,u);
        }
    }

    return u;

}

int Find1(int i, int lo, int hi, int val)
{
    int cntt=0,mid;
    while(cntt++<32)
    {
        mid=(hi+lo)/2;
        // printf("%d %d %d , %d %d\n",lo,hi,mid, dist[i][mid],val);
        if(dist[i][mid]>=val) hi=mid;
        else if(dist[i][mid]<val) lo=mid+1;

    }

    if(mid+1<=hi && dist[i][mid]<val) mid++;
    else if(mid-1>=0 && dist[i][mid-1]>=val) mid--;


    return mid;
}

int Find2(int i, int lo, int hi, int val)
{

    int cntt=0,mid;
    while(cntt++<32)
    {
        mid=(lo+hi)/2;
        if(dist[i][mid]>val) hi=mid-1;
        else if(dist[i][mid]<=val) lo=mid;

        // printf("%d %d %d\n",lo,hi, mid);
    }

    if(mid+1 <=hi && dist[i][mid+1]<=val) mid++;
    else if(mid-1>=0 && dist[i][mid]>val) mid--;

    return mid;
}

int main()
{
    int n,q,x;
    scanf("%d",&n);

    for(int i=1; i<=n; i++)
    {
        scanf("%d",&x);

        if(x!=0)
        {
            adj[x].push_back(i);
        }
    }

    ms(par,-1);

    for(int i=1; i<=n; i++)
    {
        if(vis[i]==0)
        {
            dfs(i);
        }
    }
    precomputeSparse(n); /// 2 no step


    cin>>q;
    while(q--)
    {
        int v,p,tot=0;
        cin>>v>>p;

        int rt=f(v,p);

        //  cout<<rt<<endl;
        if(Level[v]<p) tot=0;
        else
        {
            int l=start[rt];
            int r=l+cnt[rt]-1;
            // print(dist[Level[v]]);
            //  printf("%d %d\n",l,r);

            // print(dist[Level[v]]);
            int left=Find1(Level[v], 0, dist[Level[v]].size()-1, l);



            //  printf("l=%d ,left=%d\n",l,left);
            int right=Find2(Level[v],0, dist[Level[v]].size()-1, r);
            //printf("r=%d ,right=%d\n",r,right);

            // printf("%d -> %d\n",left,right);
            tot=right-left;
        }
        cout<<tot<<" ";

    }




    return 0;
}
