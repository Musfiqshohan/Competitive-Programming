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

vector<int>adj[MAXN], Lives[MAXN],vec;
int par[MAXN][maxL+5], pep[MAXN][maxL+5];
int  cnt[MAXN], Level[MAXN];


set<int>myset;
set<int>::iterator it;
int dfs(int src,int pr)
{
    for(int i=0; i<adj[src].size(); i++)
    {
        int node=adj[src][i];
        if(node!=pr)
        {
            // printf("%d ->-> %d\n",src,node);
            par[node][0]=src;
            pep[node][0]=cnt[node]+cnt[src];

            Level[node]=Level[src]+1;
            dfs(node,src);
        }
    }
}


void precomputeSparse(int n)
{
    for(int i=1; i<=maxL; i++)
    {
        for(int u=1; u<=n; u++)
        {
            if(par[u][i-1]!=-1)
            {
                par[u][i]=par[ par[u][i-1] ][i-1];

                if(par[u][i]!=-1)
                {
                    pep[u][i]=pep[ par[u][i-1] ][i-1]+ pep[u][i-1] - cnt[ par[u][i-1] ];

//                    printf("u=%d %d, pr=%d\n",u,i,par[u][i]);
//                    printf("%d + %d  -%d= %d\n",pep[ par[u][i-1] ][i-1],pep[u][i-1], cnt[par[u][i-1] ], pep[u][i]);
                }
            }
        }
    }
}

int getLca(int u, int v)
{
    printf("%d %d\n",u,v);
    if(Level[u]<Level[v])
        swap(u,v);

    int dif=Level[u]-Level[v];

    for(int i=maxL; i>=0; i--)
    {
        int d=1<<i;

        if(dif>=d)
        {
            dif-=d;
            u=par[u][i];
        }
    }


    if(u==v) return u;

    for(int i=maxL; i>=0; i--)
    {
        if(par[u][i]!=par[v][i])
            u=par[u][i], v=par[v][i];
    }


    return par[u][0];
}



void collect(int u, int rt, int a)
{
    for(int i=0; i<Lives[u].size(); i++)
    {
        if(a>0)
        {
            //vec.push_back(Lives[u][i]);
            myset.insert(Lives[u][i]);
            a--;

        }
    }

    if(u!=rt)
    {
        for(int i=0; i<Lives[rt].size(); i++)
        {
            if(a>0)
            {
                myset.insert(Lives[rt][i]);
                a--;

            }
        }
    }
}


void f1(int u, int rt, int a, int last)
{
    static int cnt2=0;
    if(cnt2++>20)
    {
        puts("OverFlow");
        return;
    }
    // printf("%d %d %d %d\n",u,rt,a,last);

    if(rt==par[u][0] || u==rt)
    {
        //printf("at root %d\n",rt);
        collect(u,rt,a);
        return ;
    }

    int d=last/2;

    if(par[u][d]==-1)
    {
        // printf("In 1\n");
        f1(u,rt,a,d);
    }
    else if(pep[u][d]<a)
    {
        // printf("In 2\n");
        f1(u,par[u][d], pep[u][d],d);
        f1(par[u][d], rt, (a-pep[u][d]+cnt[ par[u][d]]),d);

    }
    else if(pep[u][d]>=a)
    {
        // printf("In 3\n");
        f1(u,par[u][d],a,d);
    }

}

void f2(int u, int rt, int a, int last)
{

    static int cnt2=0;
    if(cnt2++>20)
    {
        puts("OverFlow");
        return;
    }
     printf("%d %d %d %d\n",u,rt,a,last);

    if(rt==par[u][0] || u==rt)
    {
        //printf("at root %d\n",dest);
        collect(u,rt,a);
        return ;
    }

    int d=last/2;

    if(par[u][d]==-1)
    {
        // printf("In 1\n");
        f2(u,rt,a,d);
    }
    else
    {
        int dif=Level[u]-Level[rt]- (1<<d) +1;
        int keep=u;

        for(int i=maxL; i>=0; i--)
        {
            int dd=1<<i;
            if(dif>=dd)
            {
                dif-=dd;
                u=par[u][i];
            }
        }

        if(pep[u][d]<a)
        {
            f2(u,rt,pep[u][d],d);
            f2(keep,u,  a-pep[u][d]+ cnt[u], d);
        }
        else
        {
            f2(u,rt, a,d);
        }
    }
}


int Counting(int u, int rt)
{
    int dif=Level[u]-Level[rt];
    int tot=0;
    for(int i=maxL; i>=0; i--)
    {
        int d=1<<i;
        if(dif>=d)
        {
            dif-=d;
            tot+=pep[u][i]- cnt[ par[u][i] ];
            u=par[u][i];
        }

    }

    tot+=cnt[rt];
    return tot;

}

int main()
{
    int d=cnt[1];
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
        Lives[x].push_back(i);
        cnt[x]++;
    }

    // puts("->");
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

        cout<<rt<<endl;

        int rem1= Counting(u,rt);
        int rem2= Counting(v,rt);


        printf("rem1=%d but a=%d\n",rem1,a);
        f1(u, rt, min(a,rem1), maxL);

        printf("remain=%d but rem2=%d\n",a-myset.size(),rem2);
        a=a-myset.size()+cnt[rt];x

        //f2(v,rt, min(a,rem2),maxL);
         // f2(3,1,2,maxL);


        puts("---");
        for(it=myset.begin(); it!=myset.end(); it++)
            printf("%d ",*it);


        myset.clear();

        puts("");

    }

    return 0;
}
