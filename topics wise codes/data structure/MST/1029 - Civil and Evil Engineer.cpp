#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
#define ll long long
using namespace std;

struct tripple
{
    int u,v,w;
} tra[16009];

int n;
int par[200];


bool compare1(tripple a, tripple b)
{
    return a.w<b.w;
}

bool compare2(tripple a, tripple b)
{
    return a.w>b.w;
}

int findd(int r)
{
    if(par[r]==r) return r;
    return par[r]=findd(par[r]);
}


int unionn(tripple temp)
{
    int u= findd(temp.u);
    int v= findd(temp.v);

   // printf("%d->%d %d->%d\n", temp.u,u, temp.v,v);
    if(u!=v)
    {
        par[u]=v;

       // printf("%d %d %d\n",temp.u,temp.v,temp.w);
        return temp.w;
    }
    return 0;
}

int main()
{

    int t=0,test;

    cin>>test;

    while(t<test){

    scanf("%d",&n);

    int i=0,u,v,w;
    while(1)
    {

        scanf("%d %d %d",&u, &v, &w);

        if(u==0 && v==0 && w==0) break;

        tra[i].u=u;
        tra[i].v=v;
        tra[i].w=w;
        i++;

    }

    int m=i;


    for(int i=0; i<=n; i++) par[i]=i;

    sort(tra,tra+m, compare1);
    int t1=0;
    for(int i=0; i<m; i++)
    {
        t1+=unionn(tra[i]);
    }

   // ms(par,0);
   //puts("");
    for(int i=0; i<=n; i++) par[i]=i;

    sort(tra,tra+m, compare2);
    int t2=0;
    for(int i=0; i<m; i++)
    {
        t2+=unionn(tra[i]);
    }


     printf("Case %d: ",++t);
    if((t1+t2)%2==0)
        printf("%d\n",(t1+t2)/2);
    else printf("%d/2\n",(t1+t2));


    }

    return 0;
}
