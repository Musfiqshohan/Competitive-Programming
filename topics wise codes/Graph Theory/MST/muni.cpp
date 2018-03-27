#include<bits/stdc++.h>
using namespace std;



struct edge
{
    unsigned long long u,v,w;
    bool operator<(const edge& p) const
    {
        return w<p.w;
    }
};

vector<edge>e;
int parent[210000];

int find(int n)
{
    if(parent[n]==n)
        return n;
    else
        return find(parent[n]);
}

unsigned long long int  mst(int n)
{
    sort(e.begin(),e.end());
    for(int i=0; i<n; i++)
    {
        parent[i]=i;
    }
    unsigned long long int  sum=0,cnt=0;
    for(int i=0; i<(int)e.size(); i++)
    {
        int u = find(e[i].u);
        int v = find(e[i].v);
        if(u!=v)
        {
            cnt++;
            sum+=e[i].w;
            parent[u] = find(v);
            if(cnt==n-1)
                return sum;
        }
    }
    return sum;

}

int main()
{

    while(true)
    {
        unsigned long long int n,m,u,v,w,k=0;
        e.clear();
        memset(parent,0,sizeof(parent));
        cin>>n>>m;
        if(n==0 && m==0)
            break;
        for(int i=0; i<m; i++)
        {
            cin>>u>>v>>w;
            edge d;
            d.u = u;
            d.v = v;
            d.w = w;
            k+=w;
            e.push_back(d);

        }
        cout<<k-mst(n)<<endl;
    }
    return 0;
}
