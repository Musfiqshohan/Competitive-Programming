#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<int,int>
#define inf 100000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
using namespace std;

vector<int>adj1[1000009],adj2[1000009];
vector<pii>fin;
vector<int>vec;

int times,  vis[1000009];


void dfs(int src)
{
    ++times;

    // printf("%d start at %d\n",src,times);

    for(int i=0; i<adj2[src].size(); i++)
    {
        int node= adj2[src][i];

        if(vis[node]==0)
        {
            vis[node]=1;
            dfs(node);

        }

    }

    fin.push_back({++times,src});
    //printf("%d ends at %d\n",src,times);

}



void dfs2(int src)
{

    vec.push_back(src);
    //  printf("->->%d\n",src);
    for(int i=0; i<adj1[src].size(); i++)
    {
        int node= adj1[src][i];
        if(vis[node]==0)
        {
            //   printf("%d->%d\n",src,node);
            vis[node]=1;
            dfs2(node);
        }

    }

}


void dfs3(int src)
{


    for(int i=0; i<adj2[src].size(); i++)
    {
        int node= adj2[src][i];
        if(vis[node]==0)
        {
           // printf("%d->%d\n",src,node);
            vis[node]=1;
            dfs3(node);
        }

    }

}



bool compare(pii a, pii b)
{
    return a.first>b.first;
}


int main()
{
    int n,m,u,v;
    scanf("%d %d",&n,&m);

    for(int i=1; i<=m; i++)
    {
        scanf("%d %d",&u,&v);

        adj1[u].push_back(v);
        adj2[v].push_back(u);
    }

    for(int i=1; i<=n; i++)
    {
        if(vis[i]==0)
        {
            vis[i]=1;

            dfs(i);
        }
    }


    sort(fin.begin(), fin.end(), compare);


    ms(vis,0);


    vis[fin[0].second]=1;
    dfs2(fin[0].second);

    ms(vis,0);



    vis[fin[0].second]=1;
    dfs3(fin[0].second);

    for(int i=1; i<=n; i++)
    {
        if(vis[i]==0)
        {
            printf("0\n");
            return 0;
        }
    }

    sort(vec.begin(), vec.end());

    printf("%d\n",vec.size());
    for(int i=0; i<vec.size(); i++)
        printf("%d ",vec[i]);

    puts("");

    return 0;
}

/*
10 15
1 2
2 3
3 4
3 5
4 6
6 5
5 6
5 3
7 3
7 8
7 10
10 7
8 9
9 10
10 9
*/
