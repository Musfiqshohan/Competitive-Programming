/** codeforces.com/problemset/problem/832/D
This is a lca problem. I am in short of motivations. I am thinking that I have nothing to gain and I will surely leave
everything, Everyone will become better than me but I will not improve.
*/

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
const int MAXN=100009, maxL=18;

vector<int>adj[MAXN];
int Level[MAXN],par[MAXN][maxL+5];


int dfs(int src,int pr)
{
    for(int i=0; i<adj[src].size(); i++)
    {
        int node=adj[src][i];
        if(node!=pr)
        {
           // printf("%d ->-> %d\n",src,node);
           par[node][0]=src;
            Level[node]=Level[src]+1;
            dfs(node,src);
        }
    }
}


void precomputeSparse(int n)
{
    for(int i=1; i<=maxL; i++)
    {
        for(int u=1; u<=n; u++)
        {
            if(par[u][i-1]!=-1)
            {
                par[u][i]=par[ par[u][i-1] ][i-1];
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


    if(u==v) return u;

    for(int i=maxL; i>=0; i--)
    {
        if(par[u][i]!=par[v][i])
            u=par[u][i], v=par[v][i];
    }


    return par[u][0];
}


int f(int s, int f, int t)
{
    if(Level[s]<Level[t])
        swap(s,t);



    int rt1=getLca(s,f);
    int rt2=getLca(t,f);

    if((rt1==f && rt2!=f) || (rt2==f && rt1!=f) ) return 1;

    int res=min(abs(Level[rt1]-Level[f]), abs(Level[rt2]-Level[f]))+1;


    //int res= Level[f]-Level[mx]+1;

  //  printf("s=%d ,f=%d t=%d ,%d %d res=%d\n",s,f,t,rt1,rt2,res);

    if(rt1==rt2)
    {
        int rt3=getLca(s,t);
        res+= abs(Level[rt3]-Level[rt1]);
    }

    return res;
}

int main()
{
    int n,q,x,u,v,w;
    scanf("%d %d",&n,&q);

    for(int i=2; i<=n; i++)
    {
        scanf("%d",&x);
        adj[x].push_back(i);
        adj[i].push_back(x);
    }


    ms(par,-1);
    dfs(1,-1);

  //  puts("hi");
    precomputeSparse(n);

  //  cout<<f(1,2,3)<<endl;

   // cout<<getLca(3,5)<<endl;

    while(q--)
    {
        int mx=0;
        cin>>u>>v>>w;
       // cout<<f(u,v,w)<<endl;

        mx=max(mx, f(u,v,w));
        //cout<<mx<<endl;
        mx=max(mx, f(u,w,v));
       // cout<<mx<<endl;
        mx=max(mx, f(w,u,v));
       // cout<<mx<<endl;


        //cout<<"ans "<<mx<<endl;
        cout<<mx<<endl;


    }


    return 0;
}


