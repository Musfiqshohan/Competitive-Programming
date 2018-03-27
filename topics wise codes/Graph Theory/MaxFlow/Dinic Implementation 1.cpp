/*
  
 *************************
 Id  : Matrix.code
 Task:
 Date:
  
 **************************
  
 */
 
#include <bits/stdc++.h>
using namespace std;
 
/*------- Constants---- */
 
#define Long                    long long
#define ull                     unsigned long long
#define mod                     1000000007
#define MEMSET_INF              63
#define MEM_VAL                 1061109567
#define forn(i,n)               for( int i=0 ; i < n ; i++ )
#define mp(i,j)                 make_pair(i,j)
#define lop(i,a,b)              for( int i = (a) ; i < (b) ; i++)
#define pb(a)                   push_back((a))
#define all(x)                  (x).begin(),(x).end()
#define gc                      getchar_unlocked
#define PI                      acos(-1.0)
#define INF                     1<<29
#define EPS                     1e-9
#define Fr                      first
#define Sc                      second
#define Sz                      size()
#define lc                      ((n)<<1)
#define rc                      ((n)<<1|1)
#define db(x)                   cout << #x << " -> " << x << endl;
#define Di(n)                   int n;si(n)
#define Dii(a,b)                int a,b;si(a);si(b)
#define Diii(a,b,c)             int a,b,c;si(a);si(b);si(c)
#define Si(n)                   si(n)
#define Sii(a,b)                si(a);si(b)
#define Siii(a,b,c)             si(a);si(b);si(c)
#define min(a,b)                ((a)>(b) ? (b) : (a) )
#define max(a,b)                ((a)>(b) ? (a):(b))
/*---- short Cuts ------- */
#define ms(ara_name,value) memset(ara_name,value,sizeof(ara_name))
typedef pair<int, int> ii;
typedef vector<int > vi ;
typedef vector<Long> vl;
/*------ template functions ------ */
#ifndef getchar_unlocked
#define getchar_unlocked getchar
#endif
template<class T> inline void si(T &x){register int c = gc();x = 0;int neg = 0;for(;((c<48 | c>57) && c != '-');c = gc());
      if(c=='-') {neg=1;c=gc();}for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}if(neg) x=-x;}
template <class T> inline T bigmod(T p,T e,T M){Long ret = 1;for(; e > 0; e >>= 1){if(e & 1) ret = (ret * p) % M;p = (p * p) % M;} return (T)ret;}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}
void io(){freopen("/Users/MyMac/Desktop/in.txt","r",stdin);}
 
/*************************** END OF TEMPLATE ****************************/
 
 
const int N = 3003;
typedef int T;
struct Edge
{
    int u, v;
    T cap, flow;
    Edge(int u, int v, T c, T f):u(u), v(v), cap(c), flow(f) {}
};
 
struct Dinic
{
    int n, m, s, t;
    const T oo = 1e9;
    vector<Edge> edge;
    vector<int> G[N];
    bool vis[N];
    int d[N];
    int cur[N];
 
    void init(int n)
    {
        this->n=n;
        for(int i=0; i<=n; i++)
            G[i].clear();
        edge.clear();
    }
 
    void addEdge(int u, int v, int cap)
    {
        edge.push_back(Edge(u, v, cap, 0));
        edge.push_back(Edge(v, u, cap, 0));
        m=edge.size();
        G[u].push_back(m-2);
        G[v].push_back(m-1);
    }
 
    bool bfs()
    {
        memset(vis, 0, sizeof vis);
        queue<int> q;
        q.push(s);
        d[s]=0;
        vis[s]=1;
        while(!q.empty())
        {
            int x=q.front();
            q.pop();
            for(int i=0; i<G[x].size(); i++)
            {
                Edge& e=edge[G[x][i]];
                if(!vis[e.v] && e.cap>e.flow)
                {
                    vis[e.v]=true;
                    d[e.v]=d[x]+1;
                    q.push(e.v);
                }
            }
        }
        return vis[t];
    }
 
    T dfs(int x, T a)
    {
        if(x==t || a==0)return a;
        T flow=0, f;
        for(int& i=cur[x]; i<G[x].size(); i++)
        {
            Edge& e=edge[G[x][i]];
            if(d[x]+1==d[e.v] && (f=dfs(e.v, min(a, e.cap-e.flow)))>0)
            {
                e.flow+=f;
                edge[G[x][i]^1].flow-=f;
                flow+=f;
                a-=f;
                if(a==0)break;
            }
        }
        return flow;
    }
 
    T dinitz(int s, int t)
    {
        this->s=s;
        this->t=t;
        int flow=0;
        while(bfs())
        {
            memset(cur, 0, sizeof cur);
            flow+=dfs(s, oo);
        }
        return flow;
    }
} MaxF;
 
int main() {
      int n;
      int cs = 0;
      while(scanf("%d",&n) && n ) {
            Diii(u,v,m);
            MaxF.init(n);
            forn(i,m) {
                  Diii(a,b,c);
                  MaxF.addEdge(a,b,c);
             
            }
            printf("Network %d\nThe bandwidth is %lld.\n\n",++cs, MaxF.dinitz(u,v));
      }
       
      return 0;
}
