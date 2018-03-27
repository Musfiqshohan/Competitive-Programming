#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
#define ll long long
using namespace std;

struct tripple
{
    int u,v,w;

};
int par[56];
int n;
bool compare(tripple a , tripple b)
{
    return a.w<b.w;
}

vector<tripple>tra;

void allclear()
{
    ms(par,0);
    tra.clear();

}
int findd(int r)
{
   // return par[r]=r? r : par[r]=findd(par[r]);
   if(par[r]==r) return r;

   return par[r]=findd(par[r]);
}

int unionn(tripple temp)
{
    int u= findd(temp.u);
    int v= findd(temp.v);

    if(u!=v)
    {
        par[u]=v;

        //printf("%d %d %d\n",temp.u,temp.v, temp.w);
        return temp.w;
    }

    return 0;

}

int mst()
{
    int total=0;

    for(int i=0;i<n;i++) par[i]=i;

    for(int i=0;i<tra.size();i++)
        total+= unionn(tra[i]);
    return total;
}

int main()
{
    int t=0,test;
    cin>>test;

    while(t<test){
    int total=0,x;

    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&x);
            total+=x;
            if(i!=j && x)
            {

                tra.push_back({i,j,x});

            }
        }
    }

    sort(tra.begin(),tra.end(), compare);

   // for(int i=0;i<tra.size();i++) printf("%d %d %d\n",tra[i].u,tra[i].v, tra[i].w);

    int sum= mst();


    int cnt=0;
    for(int i=0;i<=n;i++) if(par[i]==i) cnt++;


    printf("Case %d: ",++t);
    if(cnt>1) printf("-1\n");
    else
    printf("%d\n",total-sum);

    allclear();

    }

    return 0;
}

