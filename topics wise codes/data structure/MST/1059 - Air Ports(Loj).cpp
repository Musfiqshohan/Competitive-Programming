#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
using namespace std;

struct tripple{
    int u,v,w;
};
bool compare(tripple a, tripple b)
{
    return a.w<b.w;
}

vector<tripple>tra;
int par[10009], A,total=0;

void clearr()
{
    total=0;
    ms(par,0);
    tra.clear();
}

int findd(int r)
{
    if(par[r]==r) return r;

    return par[r]=findd(par[r]);
}

void unionn(tripple temp)
{
    int u=findd(temp.u);
    int v=findd(temp.v);

    if(u!=v)
    {
        if(temp.w+A<2*A)
        {
           // printf("%d %d %d %d\n",temp.u,temp.v,temp.w,2*A);
            par[u]=v;
            total+=temp.w;
        }
    }
}


int main()
{
    int t=0,test;
    cin>>test;
    while(t<test){
    int n,m,u,v,w;

    scanf("%d %d %d",&n,&m,&A);

    for(int i=0;i<m;i++)
    {
        scanf("%d %d %d",&u,&v,&w);
        tra.pb({u,v,w});
    }

    sort(tra.begin(), tra.end(), compare);

    for(int i=0;i<n;i++) par[i]=i;

    for(int i=0;i<m;i++)
    {
        unionn(tra[i]);
    }

    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(par[i]==i) cnt++;
    }

    printf("Case %d: %d %d\n",++t,total+cnt*A,cnt);
    clearr();

    }
    return 0;
}
