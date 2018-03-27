#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<int,int>
#define inf 100000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;


vector<int>adj[100009],vec;


int dist[100009], init[100009], goal[100009];
int total;

void dfs(int src, int pr, int isOdd, int isEve)
{
    //printf("%d %d %d\n",src,isOdd, isEve);

    for(int i=0; i<adj[src].size(); i++)
    {
        int node= adj[src][i];

        if(node==pr) continue;
        dist[node]=dist[src]+1;



        if(dist[node]%2==1 && isOdd==1)
        {
            init[node]^=1;

            if(init[node]!=goal[node])
            {
                init[node]^=1;
                total++;
                vec.push_back(node);
                dfs(node, src, isOdd^1,  isEve);
            }
            else dfs(node,  src, isOdd,isEve);

        }
        else if(dist[node]%2==0 && isEve==1)
        {
            init[node]^=1;
            if(init[node]!=goal[node])
            {
                init[node]^=1;
                total++;
                vec.push_back(node);
                dfs(node, src, isOdd, isEve^1);
            }
            else dfs(node,  src,isOdd, isEve);
        }
        else if(init[node]!=goal[node])
        {
           // printf("->%d\n",node);
            init[node]^=1;
            total++;
            vec.push_back(node);
            if(dist[node]%2==0)
                dfs(node, src, isOdd, isEve^1);
            else dfs(node,  src,isOdd^1, isEve);
        }
       else
            dfs(node,src,isOdd, isEve);


    }


}


void check(int n)
{
    for(int i=1;i<=n;i++)
    {
        printf("%d -> %d\n",init[i], goal[i]);
    }
}


int main()
{
    int n,u,v;
    scanf("%d",&n);

    adj[0].push_back(1);
    for(int i=1; i<=n-1; i++)
    {
        scanf("%d %d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=1; i<=n; i++)
        scanf("%d",&init[i]);

    for(int i=1; i<=n; i++)
        scanf("%d",&goal[i]);


    dist[1]=0;


    dfs(0, -1, 0, 0);



   // check(n);

    cout<<total<<endl;
    for(int i=0; i<vec.size(); i++)
        printf("%d\n",vec[i]);



    return 0;
}
