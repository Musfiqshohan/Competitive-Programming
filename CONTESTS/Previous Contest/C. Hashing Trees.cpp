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


vector<int>adj1[200009],adj2[200009];
int vis[200009], parent[200009], ara[200009];
void create1(int src, int x, int y)
{
    for(int i=x; i<=y; i++)
        adj1[src].push_back(i);
}

void create2(int src, int x, int y)
{
    for(int i=x; i<=y; i++)
        adj2[src].push_back(i);
}


void dfs(vector<int>adj[], int src)
{
    vis[src]=1;

    for(int i=0; i<adj[src].size(); i++)
    {
        int node= adj[src][i];
        if(vis[node]==0)
        {
            parent[node]=src;

          //  printf("%d -> %d\n",src,node);
            dfs(adj,node);

        }
    }

}


void print(int n)
{
    for(int i=1; i<=n; i++)
        printf("%d ",parent[i]);

    puts("");

}
int main()
{

    int n;
    scanf("%d",&n);

    int LastNode=0,flag=0;

    for(int i=0; i<=n; i++)
    {
        scanf("%d",&ara[i]);



        if(i>0 || flag==1)
        {
            create1(LastNode,LastNode+1,LastNode+ara[i]);
            create2(LastNode,LastNode+1,LastNode+ara[i]);
        }


      //  printf("i=%d ar= %d\n",i,ara[i]);
        if(i>1 && ara[i]>1)
        {
           // puts("hi");
            flag=1;
            create1(LastNode,LastNode+1,LastNode+ara[i]);

            create2(LastNode-1,LastNode+1,LastNode+1);
            create2(LastNode, LastNode+2, LastNode+ara[i]);
        }

        LastNode+=ara[i];
    }


    if(flag==0) printf("perfect\n");
    else
    {
        printf("ambiguous\n");
        dfs(adj1,1);
        print(LastNode);

        ms(vis,0);
        ms(parent,0);
        dfs(adj2,1);
        print(LastNode);
    }

    return 0;
}
