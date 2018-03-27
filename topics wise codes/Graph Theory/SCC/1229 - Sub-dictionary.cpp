#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<int,int>
#define inf 100000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(b,"w",stdout)
using namespace std;

vector<int>adj[1005];
map<string,int>mp;
int indeg[1005], vis[1005];
int cnt=0;

int BFS()
{

    int ret=cnt;
    queue<int>q;
    for(int i=1; i<=cnt; i++)
    {
        if(indeg[i]==0)
            q.push(i);
    }

    while(!q.empty())
    {
        int u= q.front();
        q.pop();
        ret--;
        vis[u]=1;

        for(int i=0; i<adj[u].size(); i++)
        {
            int node= adj[u][i];

            indeg[node]--;
            if(indeg[node]==0) q.push(node);
        }

    }

    return ret;

}

int main()
{
    int test=0;
        int n;
    while( scanf("%d",&n)==1 && n)
    {

        //if(test++>0) puts("");
        string str;

        getchar();

        for(int i=0; i<n; i++)
        {
            getline(cin,str);

            istringstream iss(str);
            string subs;
            iss>>subs;

            if( mp.find(subs)==mp.end())  //not till now
                mp[subs]=++cnt;

            int x= mp[subs];
            do
            {
                iss >> subs;
                if(subs.size()!=0)
                {
                    if( mp.find(subs)==mp.end())  //not till now
                        mp[subs]=++cnt;

                    int y=mp[subs];
                    adj[x].push_back(y);
                    indeg[y]++;
                }
            }
            while (iss);

        }


        int res=BFS();

        printf("%d\n",res);

        map<string,int>::iterator it;
        string ara[1005];

        int j=0;
        for(it=mp.begin() ;  it!=mp.end() ; it++)
        {

            if( vis[it->second]==0 )
            {

                ara[j++]=it->first;
            }

        }

        sort(ara,ara+res);

        for(int i=0; i<res; i++)
        {
            if(i) printf(" ");
            cout<<ara[i];
        }
        puts("");

        for(int i=0;i<=cnt; i++) adj[i].clear();
        mp.clear();
        ms(vis,0);
        ms(indeg,0);

    }

    return 0;
}
