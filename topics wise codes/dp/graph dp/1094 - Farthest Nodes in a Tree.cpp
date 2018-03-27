#include<bits/stdc++.h>

#define pb push_back

#define ms(a,b) memset((a),(b),sizeof(a))

//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
using namespace std;

int f[30009], g[30009], parent[30009];
vector<int>adj[30009];
vector<int>cost[30009];
int diameter;

int dfs(int src)
{

    int mx1=-1,mx2=-1,mx=0,res;
    for(int i=0;i<adj[src].size();i++)
    {
        int node=adj[src][i];
        if(node != parent[src])
        {
            parent[node]=src;

            res= cost[src][i]+dfs(node);

            if(res>mx1) {  mx2=mx1; mx1=res;  }
            else if(res>mx2) { mx2=res; }

            mx= max(mx,res);
        }
    }

    f[src]= mx;

    if(mx1!=-1 && mx2 !=-1)
    g[src]= mx1+mx2;

    diameter= max(diameter, max(f[src],g[src]));
    return f[src];
}

int main()
{

    int t=0,test;
    cin>>test;

    while(t<test){

    int n,u,v,w,i;
    diameter=0;
    scanf("%d",&n);


    for(i=1;i<=n-1;i++)
    {
        scanf("%d %d %d",&u,&v,&w);

        adj[u].pb(v);
        adj[v].pb(u);

        cost[u].pb(w);
        cost[v].pb(w);
    }


    int cc=dfs(0);
    printf("Case %d: %d\n",++t,diameter);

    ms(f,0);
    ms(g,0);
    ms(parent,0);

    for(int i=0;i<=n;i++) {adj[i].clear();   cost[i].clear(); }


    }
    return 0;

}

