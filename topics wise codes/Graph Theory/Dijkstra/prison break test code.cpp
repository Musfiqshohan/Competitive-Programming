#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define memo(a,b) memset(a,b,sizeof(a))
#define INF 1e9
#define EPS 1e-8
#define PI 3.14159265358979323846

typedef long long ll ;
typedef unsigned long long ull ;

/* int dx[] = {1,-1,0,0} , dy[] = {0,0,1,-1}; */ // 4 Direction
/* int dx[] = {1,-1,0,0,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1,1,-1}; */ // 8 Direction
/* int dx[] = {1,-1,1,-1,2,2,-2,-2} , dy[] = {2,2,-2,-2,1,-1,1,-1}; */ // Knight Direction
/* int dx[] = {2,-2,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1}; */ // Hexagonal Direction

struct Node
{
    int u , c , co ;
};

class cmp
{
public:
    bool operator () (Node A,Node B)
    {
        if(A.co==B.co) return A.c < B.c ;
        else return A.co > B.co ;
    }
};

vector < pair<int,int> > G[100+10] ;
int arr[100+10] , d[100+10][100+10] , n , m , q ;
bool check[100+10][100+10] ;

int dijkstra(int s,int t,int p)
{
    priority_queue <Node,vector<Node>,cmp> Q ;

    for(int i=0;i<=100;i++) for(int j=0;j<=100;j++) d[i][j] = INF , check[i][j] = false ;

    d[s][0] = 0 ;
    Node obj ; obj.u = s ; obj.c = 0 ; obj.co = 0 ;
    Q.push(obj);

    while( !Q.empty() )
    {
        int u = Q.top().u , c = Q.top().c , co = Q.top().co ;
        Q.pop();

        if(check[u][c]) continue ;
        check[u][c] = true ;
        if(u==t) return co ;

        for(int i=0;i<G[u].size();i++)
        {
            int v = G[u][i].ff , w = G[u][i].ss ;
            for(int i=w;i<=p;i++)
            {
                int dif = 0 ;
                if(c<i) dif = i-c;

                if(d[v][i-w]>co+dif*arr[u])
                {
                    d[v][i-w] = co+dif*arr[u] ;
                    obj.u = v ; obj.c = i-w ; obj.co = d[v][i-w] ;
                    Q.push(obj);
                }
            }
        }
    }
    return -1 ;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int T ;
    cin >> T ;
    for(int cas=1;cas<=T;cas++)
    {
        cin >> n >> m ;
        for(int i=0;i<n;i++) cin >> arr[i] , G[i].clear();
        while( m-- )
        {
            int u , v , w ;
            cin >> u >> v >> w ;
            G[u].pb(mp(v,w));
            G[v].pb(mp(u,w));
        }

        cout << "Case " << cas << ":\n";
        cin >> q ;

        while( q-- )
        {
            int c , s , t ;
            cin >> c >> s >> t ;

            int ans = dijkstra(s,t,c);
            if(ans==-1) puts("impossible");
            else cout << ans << endl ;
        }
    }
    return 0;
}
