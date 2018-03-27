/**http://codeforces.com/problemset/problem/587/C
I've got some motivation again, Now I am trying to solve this problem. I think CP will help me develop my brain. In stead of wasting my time
I am doint CP. And Didnt it taught me many things in the past 2 years? and isnt't it still? So i should continue it and not think about it anymore.
Of course I will do other thinks.
*/
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
const int MAXN=100009, maxL=18;

vector<int>adj[MAXN], Lives[MAXN], vec1,vec2;
int par[MAXN][maxL+5];
vector<int>pep[MAXN][maxL+5];
int  cnt[MAXN], Level[MAXN];

void delete_last(vector<int>&vec)
{
    while(vec.size()>10)
        vec.pop_back();
}

void print(vector<int>vec, int no)
{
    printf("Start= %d\n",no);
    for(int i=0; i<vec.size(); i++)
        printf("%d ",vec[i]);

    puts("End");
}


int dfs(int src,int pr)
{
    for(int i=0; i<adj[src].size(); i++)
    {
        int node=adj[src][i];
        if(node!=pr)
        {
            // printf("%d ->-> %d\n",src,node);
            par[node][0]=src;

            for(int k=0; k<Lives[src].size(); k++)
            {
                int pp=Lives[src][k];
                pep[node][0].push_back(pp);
            }

            sort(pep[node][0].begin(),pep[node][0].end());

            Level[node]=Level[src]+1;
            dfs(node,src);
        }
    }
}

void process(int u, int i)
{
    int impr=par[u][i-1];

    vector<int>temp(pep[u][i-1].size()+pep[impr][i-1].size());
    merge( pep[u][i-1].begin(), pep[u][i-1].end(), pep[impr][i-1].begin(), pep[impr][i-1].end(),  temp.begin());
    pep[u][i]=temp;


    sort(pep[u][i].begin(), pep[u][i].end());

    delete_last(pep[u][i]);


}


void precomputeSparse(int n)
{
    for(int i=1; i<=maxL; i++)
    {
        for(int u=1; u<=n; u++)
        {
            if(par[u][i-1]!=-1)
            {
                int impr=par[u][i-1];
                process(u,i);
                par[u][i]=par[ impr ][i-1];
            }
        }
    }
}




int getLca(int u, int v)
{
    // printf("%d %d\n",u,v);
    if(Level[u]<Level[v])
        swap(u,v);

    int dif=Level[u]-Level[v];
    //vector<int>vec1,vec2;

    for(int i=0; i<Lives[u].size(); i++)
        vec1.push_back(Lives[u][i]);

    sort(vec1.begin(),vec1.end());

    //  puts("hi");
    //vector<int>vecx(10);

    for(int i=maxL; i>=0; i--)
    {
        int d=1<<i;

        if(dif>=d)
        {
            dif-=d;

            vector<int>temp(vec1.size()+pep[u][i].size());
            // print(pep[u][i]);
            merge( vec1.begin(), vec1.end(), pep[u][i].begin(), pep[u][i].end(), temp.begin());
            vec1=temp;
            sort(vec1.begin(),vec1.end());
            delete_last(vec1);
            u=par[u][i];
        }
    }

//   print(vec1);


    if(u==v) return u;

    for(int i=0; i<Lives[v].size(); i++)
        vec2.push_back(Lives[v][i]);

    sort(vec2.begin(),vec2.end());

    for(int i=maxL; i>=0; i--)
    {
        if(par[u][i]!=par[v][i])
        {
            vector<int>temp1(vec1.size()+pep[u][i].size());
            merge(vec1.begin(),vec1.end(), pep[u][i].begin(), pep[u][i].end(), temp1.begin());
            vec1=temp1;
            sort(vec1.begin(),vec1.end());
            delete_last(vec1);



            vector<int>temp2(vec2.size()+pep[v][i].size());
//            print(vec2,1);
//            print(pep[v][i],2);
//            print(temp2,3);
            merge(vec2.begin(),vec2.end(), pep[v][i].begin(), pep[v][i].end(), temp2.begin());
           // print(temp2,4);
            vec2=temp2;
           // print(temp2);
            sort(vec2.begin(),vec2.end());

            delete_last(vec2);

            u=par[u][i], v=par[v][i];
        }
    }


    int pr=par[u][0];
    for(int i=0; i<Lives[pr].size(); i++)
        vec2.push_back(Lives[pr][i]);

    sort(vec2.begin(),vec2.end());
    return par[u][0];
}



int main()
{
    int n,m,q,u,v,x,a;
    cin>>n>>m>>q;

    for(int i=1; i<n; i++)
    {
        scanf("%d %d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=1; i<=m; i++)
    {
        scanf("%d",&x);

        if(Lives[x].size()<10)
        {
            Lives[x].push_back(i);
        }
    }

    for(int i=1; i<=n; i++)
    {
        sort(Lives[i].begin(), Lives[i].end());
    }


    ms(par,-1);
    dfs(1,-1);

    precomputeSparse(n);

    while(q--)
    {

        cin>>u>>v>>a;
        int rt=getLca(u,v);


//        print(vec1);
//        print(vec2);

        sort(vec1.begin(),vec1.end());
        sort(vec2.begin(),vec2.end());

        vector<int>vec(vec1.size()+vec2.size());
        merge(vec1.begin(),vec1.end(),vec2.begin(),vec2.end(),vec.begin());

        sort(vec.begin(),vec.end());
        delete_last(vec);


        printf("%d ",min(a,(int)vec.size()));
        if(vec.size()>0)
        {

            for(int i=0; i<vec.size() && i<a; i++)
                printf("%d ",vec[i]);
        }
        puts("");

        vec1.clear(),vec2.clear();

    }
    return 0;
}
