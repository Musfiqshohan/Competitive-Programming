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
vector<int>adj[209];
map<pii,int>mp;
int times=0, disc[209],low[209],vis[209],par[209];
stack<pii>stk;


pii mxedge;
int mx=-1;
void find_bicom(int src)
{
    disc[src]= low[src]=++times;
    vis[src]=1;

    for(int i=0; i<adj[src].size(); i++)
    {
        int node= adj[src][i];

        pii edge;
        edge= {min(src,node), max(src,node)};

        if(vis[node]==0)
        {
            par[node]=src;
            stk.push(edge);

            find_bicom(node);

            low[src]= min(low[src], low[node]);

            if(low[node]>=disc[src])
            {
                int cnt=0;
                pii temp;
                while(stk.top()!= edge)
                {
                    temp=stk.top();
                    printf("%d -> %d\n",temp.first, temp.second);
                    cnt+=2;

                    if(mp[temp]>mx)
                    {
                        mx= mp[temp];
                        mxedge=temp;
                    }


                    stk.pop();
                }

                temp= stk.top();

                if(mp[temp]>mx)
                {
                    mx= mp[temp];
                    mxedge=temp;
                }

               printf("%d -> %d\n",temp.first, temp.second);
                cnt+=2;
                cout<<cnt<<endl;
                if(cnt==2) mx=-1;
                stk.pop();

                while(!stk.empty()) stk.pop();

                // return mx;
            }

        }
        else if(node != par[src] && disc[node]<low[src])
        {
            low[src]= min(low[src],disc[node]);
            stk.push(edge);
        }
    }

    //return mx;

}

int main()
{
    int n,m,u,v,w;
    scanf("%d %d",&n,&m);

    int tot=-1;
    for(int i=0; i<m; i++)
    {
        scanf("%d %d %d",&u,&v,&w);

        adj[u].push_back(v);
        adj[v].push_back(u);


        mp[ {min(u,v), max(u,v)}]=1;
        times=0;
        mx=-1;
        find_bicom(1);

        if(mx>w)
        {
            tot=tot-mx+w;
            mp[mxedge]=0;
            mp[ {min(u,v), max(u,v)}]=1;
            mp[ {min(u,v), max(u,v)}]=1;

        }

        printf("mx=%d tot=%d\n",mx,tot);
    }




    return 0;
}
