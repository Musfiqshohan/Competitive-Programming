#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
#define i64 long long
#define pii pair<int,int>
#define INF 1000000009
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
using namespace std;



int src, int snk,nNode, nEdge;
int fin[MAXN], pre[MAXN], dist[MAXN];
int cap[MAXE], cost[MAXE], nextt[MAXE], to[MAXE],from[MAXE];

inline void init(int _src, int _snk, int nodes){
    ms(fin,-1);
    nNode=nodes, nEdge=0;
    src=_src, snk=_snk;
}


inline void addEdge(int u, int v, int _cap, int _cost)
{
    from[nEdge]=u, to[nEdge]=v, cap[nEdge]=_cap, cost[nEdge]=_cost;
    nextt[nEdge]=fin[u], fin[u]=nEdge++;
    from[nEdge]=v, to[nEdge]=u, cap[nEdge]=0, cost[nEdge]=-(_cost);
    nextt[nEdge]=fin[v], fin[v]=nEdge++;
}

bool bellman()
