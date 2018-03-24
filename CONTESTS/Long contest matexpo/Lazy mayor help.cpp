//itisalways42
#include<bits/stdc++.h>

using namespace std;

typedef long long int 	LL;
typedef pair<LL,LL>   II;
typedef vector< II >      VII;
typedef vector<int>     VI;
typedef vector< VI > 	VVI;
typedef vector< VII > mat;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define ALL(a) a.begin(),a.end()
#define SET(a,b) memset(a,b,sizeof(a))

#define si(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
#define sll(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

//FILE *fin = freopen("in","r",stdin);
//FILE *fout = freopen("out","w",stdout);

const int N = int(500)+10;
const LL INF = LL(1e15);
const LL MOD = LL(1e9)+7;
int n;
int g[N][N];

void mult(mat &a, mat &b)
{
	mat ret(n,VII(n,MP(INF,0)));
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
		{
			LL mn=INF;
			for(int k=0; k<n; k++)
				if(a[i][k].F + b[k][j].F < mn)
					mn = a[i][k].F + b[k][j].F;
			ret[i][j].F = mn;
			for(int k=0; k<n; k++)
				if(a[i][k].F + b[k][j].F == mn)
					ret[i][j].S = (ret[i][j].S + a[i][k].S*b[k][j].S)%MOD;
		}
	a = ret;
}

mat ret;
void expo(int k)
{
	ret.resize(n, VII(n, MP(INF, 0)));

	for(int i=0; i<n; i++) ret[i][i] = MP(0,1);
	mat a(n,VII(n));
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			if(g[i][j])
				a[i][j] = MP(g[i][j],1);
			else
				a[i][j] = MP(INF,0);
	while(k)
	{
		if(k&1) mult(ret,a);
		mult(a,a);
		k /= 2;
	}
}

int main()
{
	fast_io;
	int m,k;
	cin>>n>>m>>k;
	for(int i=0; i<m; i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		u--, v--;
		g[u][v] = g[v][u] = w;
	}
	expo(k);
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(ret[i][j].F == INF) cout<<"X "<<0<<" ";
			else cout<<ret[i][j].F<<" "<<ret[i][j].S<<" ";
		}
		cout<<"\n";
	}
	return 0;
}

