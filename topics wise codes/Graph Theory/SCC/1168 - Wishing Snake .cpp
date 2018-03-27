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



vector<int>adj1[1009];
vector<int>adj2[1009];
vector<int>scc_graph[1009];
vector<pii> fin;
vector<int>exist;
int vis[1009],belong[1009], outdeg[1009],taken[1009], scc_mat[1009][1009];
int start=0,flag=0, n,k;

void clearr()
{
    start=0,flag=0;
    ms(vis,0);
    ms(belong,0);
    ms(outdeg,0);
    ms(taken,0);
    ms(scc_mat,0);
    fin.clear();
    exist.clear();

    for(int i=0; i<1009; i++)
    {
        adj1[i].clear();
        adj2[i].clear();
        scc_graph[i].clear();
    }

}


void dfs1(int src, vector<int>adj[])
{
    ++start;

    for(int i=0; i<adj[src].size(); i++)
    {
        int node= adj[src][i];

        if(vis[node]==0)
        {

            vis[node]=1;
            dfs1(node,adj);
        }
    }


    fin.push_back({src,++start});


}

void dfs2(int src,vector<int>adj[],int scc)
{

    for(int i=0; i<adj[src].size(); i++)
    {

        int node= adj[src][i];

        if(vis[node]==0)
        {
            //printf("%d belongs to %d\n", node, scc);
            belong[node]=scc;

            vis[node]=1;
            dfs2(node,adj,scc);
        }
    }

}



void dfs33(int src, vector<int>adj[])
{

    if(adj[src].size()>1)
        flag=1;

    for(int i=0; i<adj[src].size(); i++)
    {
        int node= adj[src][i];

        if(vis[node]==0)
        {
            vis[node]=1;
            dfs33(node,adj);
        }
    }

}


bool compare(pii a, pii b)
{
    return a.second>b.second;
}


void find_finishing_time()
{
    vis[0]=1;
    dfs1(0,adj1);



    for(int i=0; i<exist.size(); i++)
    {
        if(vis[exist[i]]==0)
            flag=1;
    }

    sort(fin.begin(), fin.end(), compare);

}

int reversedfs()
{
    int scc=0;
    ms(vis,0);
    for(int i=0; i<fin.size(); i++)
    {
        int src=fin[i].first;

      //  printf("src= %d\n",src);
        if(vis[src]==0)
        {
            vis[src]=1;
            belong[src]=++scc;
            dfs2(src, adj2, scc);
        }
    }



    return scc;
}



int main()
{
//    in("1168.txt");
//    out("1168Out.txt");

    int tt=0,test;
    cin>>test;
    int u,v;

    while(tt<test)
    {



        scanf("%d",&n);



        for(int j=0; j<n; j++)
        {
            scanf("%d",&k);

            for(int i=0; i<k; i++)
            {
                scanf("%d %d",&u,&v);


                if(scc_mat[u][v]==0)
                {

                    scc_mat[u][v]=1;
                    adj1[u].push_back(v);
                    adj2[v].push_back(u);

                }

                if(taken[u]==0)
                {
                    taken[u]=1;
                    exist.push_back(u);
                }

                if(taken[v]==0)
                {
                    taken[v]=1;
                    exist.push_back(v);
                }

            }

        }

        sort(exist.begin(),exist.end());


        find_finishing_time();

        int scc=reversedfs();


        for(int i=0; i<exist.size(); i++)
        {
            int src=exist[i];

            for(int j=0; j<adj1[src].size(); j++)
            {
                int node= adj1[src][j];

                if(belong[src]!=belong[node])
                {

                    scc_graph[ belong[src] ].push_back( belong[node] );
                }

            }
        }

        ms(vis,0);
        vis[1]=1;

        dfs33(1,scc_graph);


        for(int i=1; i<=scc; i++)
        {
            if(vis[i]==0)
                flag=1;
        }


        printf("Case %d: ",++tt);
        if(flag==1) printf("NO\n");
        else printf("YES\n");

        clearr();



    }


    return 0;
}
