#include<bits/stdc++.h>
using namespace std;
typedef pair< double , int > pdi;
const int mxn = 1e2;
vector< pdi > adj[mxn+10];
double prob[mxn+10];
#define eps 1e-6
bool vis[mxn+10];
bool operator <( pdi a , pdi b)
{
	return a.first < b.first;
}
void dks()
{
	memset(vis , false , sizeof(vis));
	for(int i = 0; i < mxn+10; i++)
	{
		prob[i] = 0.0D;
	}
	prob[0] = 1.00000D;
	priority_queue< pdi > pq;
	pq.push(make_pair(1.00000D , 0));
	while(!pq.empty())
	{
		pdi p = pq.top();
		pq.pop();
		if(vis[p.second])
		continue;
		vis[p.second] = true;
		for(int i =0; i < (int)adj[p.second].size(); i++)
		{
			pdi q = adj[p.second][i];
			if(vis[q.second])
			continue;
			if (prob[q.second] < prob[p.second]*(q.first))
			{
				prob[q.second] = prob[p.second]*(q.first);
				pq.push(make_pair(prob[q.second] ,q.second));
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int tc;
	cin>>tc;
	int cs = 0;
	int n , m;
	double s, k;
	while(tc--)
	{
		cs++;
		cin>>n>>m>>s>>k;
		int v , u;
		double w;
		for(int i = 0; i < m; i++)
		{
			cin>>u>>v>>w;
			adj[u].push_back(make_pair(w/100.0D,v));
			adj[v].push_back(make_pair(w/100.0D,u));
		}
		dks();
		double ans = (2.0D*k*s)/prob[n-1];
		cout<<"Case "<<cs<<": "<<fixed<<setprecision(10)<<ans<<endl;
	}
}
