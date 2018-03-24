#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<int,int>
#define inf 100000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

struct node{
    int nodes,xorr,idx;

    bool operator < (const node &n) const{
        return nodes > n.nodes;
    }
};

priority_queue<node>pq;
pii ara[100009];
vector<int>adj[100009];
int par[100009];

//vector<pii>edge;
set<pii>edge;
set<pii>:: iterator it;

int main()
{

    int n,x,y;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&x,&y);
        ara[i]={x,y};
        pq.push({x,y,i});
    }

    while(!pq.empty())
    {
        //puts("ff");
        node temp=pq.top();
        pq.pop();

        if(temp.nodes==0 ) continue;
        if(temp.nodes>1) break;

        int src=temp.xorr;

      //  printf("->%d %d %d\n",temp.idx, temp.nodes, temp.xorr);

        edge.insert({min(temp.idx,src), max(temp.idx,src)});


//        if(edge.size()==n-1)
//            break;

        ara[src].first--;
        ara[src].second^=temp.idx;

        node newnode={ara[src].first , ara[src].second,  src};
        //    printf("Pushing= %d %d %d\n",newnode.idx, newnode.nodes, newnode.xorr);
        pq.push(newnode);
    }


    cout<<edge.size()<<endl;
    for(it=edge.begin();it!=edge.end();it++)
        printf("%d %d\n",(it)->first,(it)->second);



}
