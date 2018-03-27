#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<int,int>
#define inf 100000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(b,"w",stdout)
using namespace std;

int times,  child,totartu;
vector<int>adj[10009];
vector<pii>edge;
int disc[10009], low[10009], vis[10009], par[10009], artu[10009];


void clearr(int n)
{
    totartu=0;
    times=0,child=0;
    for(int i=0; i<=n; i++) adj[i].clear();
    edge.clear();
    ms(vis,0);
    ms(artu,0);
}

void dfs(int src)
{
    disc[src]= low[src] = ++times;

    for(int i=0; i<adj[src].size(); i++)
    {
        int node= adj[src][i];

        if(vis[node]==0 )
        {
            if(par[src]==src)
                child++;


            vis[node]=1;
            par[node]=src;

            dfs(node);

            low[src]= min( low[src], low[node]);

            if(low[node]>=disc[src] && par[src]!=src)
            {
               // printf("%d -> ->%d\n",src,node);
                if(artu[src]==0) totartu++;
                 artu[src]=1;

            }
        }

        else if(node != par[src])  //back edge
        {
            low[src]= min( low[src], disc[node]);
        }



    }




}



int split_str(string s)
{

    istringstream iss(s);
    int cnt=0,u,v;

    while(iss)
    {
        int v=-1;

        iss>>v;
        if(v==-1) break;

        if(cnt++==0) { u=v;  if(u==0) return 1; }

        else
        {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

    }

}


int main()
{



    while(1)
    {

        int n,x,y;
        scanf("%d",&n);
        getchar();

        if(n==0) break;

        while(1)
        {

            string str;
            getline(cin,str);
            if(split_str(str)==1) break;

        }

        for(int i=1; i<=n; i++)
        {
            int src= i;

            if(vis[src]==0)
            {
                par[src]=src;
                vis[src]=1;
                dfs(src);

                if(child>1) {
                        //printf("from =%d %d\n",src,child);
                        if(artu[src]==0) totartu++;
                        artu[src]=1;
                }
                child=0;
            }

        }


        printf("%d\n",totartu);

        clearr(n);


    }


    return 0;
}
