#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<ll,ll>
#define inf 100000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
using namespace std;

map<pii,int>mp;
int par[209];


struct node
{
    int u,v,w;

    bool operator <(const node &n)const
    {
        return w>n.w;
    }
};
priority_queue<node>pq;


int findd(int r)
{
    return par[r]= (par[r]==r)? r: findd(par[r]);
}

int mst(int n)
{
    for(int i=1; i<=n; i++)
        par[i]=i;

    int cnt=0,sum=0;
    priority_queue <node>temp;

    while(!pq.empty())
    {
        node tp=pq.top();
        pq.pop();

        int u= findd(tp.u);
        int v= findd(tp.v);

        if(u!=v)
        {
            temp.push(tp);
            cnt++;
            par[u]=v;
            sum+=tp.w;
            if(cnt==n-1) break;
        }
    }

    // cout<<pq.size()<<endl;

    pq=temp;

    return sum;
}

int main()
{
    int tt=0,test;
    cin>>test;

    while(tt<test)
    {
        printf("Case %d:\n",++tt);
        int n,m,u,v,w;
        scanf("%d %d",&n,&m);

        int tot=-1;
        for(int i=0; i<m; i++)
        {
            scanf("%d %d %d",&u,&v,&w);

            pq.push({min(u,v), max(u,v), w});

            int res= mst(n);
            // cout<<pq.size()<<endl;
            if(pq.size()<n-1)
                printf("-1\n");
            else printf("%d\n",res);

        }

        ms(par,0);

        while(!pq.empty()) pq.pop();


    }



    return 0;
}
