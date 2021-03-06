#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define inf 100000000000099
using namespace std;


vector<int>adj[100009];
vector<int>edge[100009];
ll dist[100009];
int par[100009];
bool vis[100009];

void dijkstra()
{
    dist[1]=0;
    multiset<pair<int,int>>s;		//this data structure will sort by the first element  and decreasingly that means maximum distance 
    par[1]=1;				// with its correspoding node will be at the front.
    s.insert({0,1});		// 0=distance of the first node  1 means first node;

    while(!s.empty())	
    {
        pair<int,int>p= *s.begin();	// since its a pointer so just use asteric to get the real value its like =  queue.front();
        s.erase(s.begin());	//	its like = queue.pop();

        int u=p.second;		// its the node

        if(vis[u]==true) continue;	//if the popped node(src) is already visited then ignore it.
        vis[u]=true;			// else mark it

        for(int i=0;i<adj[u].size();i++)		//adjacent list 
        {
            int tmp=adj[u][i];				// the nodes where we can go from the src
            int edg=edge[u][i];				// and the distance to go to that node

            if(dist[u]+edg<dist[tmp])			// if the distance of the src+ edge between src and node < dis[node]
            {
               // printf("%d -> %d\n",u,tmp);
                dist[tmp]=dist[u]+edg;			// edit it
                s.insert({dist[tmp],tmp});		// its like= queue.push();
                par[tmp]=u;				// keep the parent for printing tha path
            }	
           // else par[tmp]=u;
        }
    }
}

void print_path(int node)
{
    if(par[node]==node){
        printf("%d ",node);
        return;
    }

    print_path(par[node]);
    printf("%d ",node);
}

int main()
{
    int n,m,u,v,w;
    scanf("%d %d",&n,&m);

    for(int i=0;i<m;i++)
    {
        scanf("%d %d %d",&u,&v,&w);
        adj[u].push_back(v);		//stores the nodes;
        adj[v].push_back(u);

        edge[u].push_back(w);		//stores the edges
        edge[v].push_back(w);
    }

    for(int i=1;i<=n;i++) dist[i]=inf;		// initially all are infinite;

    dijkstra();		//here we are calculating distance from 1 the node

    if(dist[n]==inf)		// if its still inf the no path
        printf("-1");
    else print_path(n);		//else print path.. or print distance by dis[n];  

    puts("");


    return 0;
}
