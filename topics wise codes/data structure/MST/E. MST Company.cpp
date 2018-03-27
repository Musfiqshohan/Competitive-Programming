#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
#define ll long long
using namespace std;

int total=0;
struct tripple
{
    int u,v,weight,index;
};

tripple tra[100009];
int par[100009];
int n,m,k;
vector<int>ind;

bool compare(tripple a, tripple b)
{
    if((a.u==1 || a.v==1) && (b.u==1 || b.v==1))  // if both are capital roads.
        return a.weight<b.weight;

    if(a.u==1 || a.v==1 )       // if the first tripple is capital
        return true;

    if(b.u==1 || b.v==1)    // if the 2nd is capital road
        return false;

    return a.weight<b.weight;   // otherwise just weight

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
        par[u]=v;
        total+=temp.weight;

        if(temp.u==1 || temp.v==1) k--;

        ind.push_back(temp.index+1);
        printf("(%d %d) =%d at %d\n",temp.u, temp.v, temp.weight, temp.index+1);



    }
}

void mst()
{
    for(int i=1;i<=n;i++) par[i]=i;

    for(int i=0;i<m;i++)
    {

        if(k==0 && (tra[i].u==1 || tra[i].v==1)) continue;  // since exactly k capital roads

        unionn(tra[i]);
    }

}



int main()
{
    scanf("%d %d %d",&n,&m,&k);

    for(int i=0; i<m; i++)
    {
        scanf("%d %d %d",&tra[i].u,&tra[i].v,&tra[i].weight);
        tra[i].index=i;
    }

    sort(tra,tra+m, compare);

   // for(int i=0;i<m;i++) printf("(%d %d) =%d at %d\n",tra[i].u, tra[i].v, tra[i].weight, tra[i].index+1);


    mst();

    if(k)  {  printf("-1\n"); return 0; }

    int parent= findd(1);

    for(int i=1;i<=n;i++)
    {
        if(findd(i)!=parent) {  printf("-1\n"); return 0; }
    }

    cout<<ind.size()<<endl;

    for(int i=0;i<ind.size();i++) printf("%d ",ind[i]);


    puts("");
    cout<<total<<endl;

   // another();

    return 0;

}
