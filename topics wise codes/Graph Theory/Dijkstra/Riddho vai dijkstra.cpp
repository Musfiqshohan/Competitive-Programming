#include <bits\stdc++.h>
using namespace std;
#define inf 500000005
int dis[300005],vis[300005],parent[300005],n,m;
struct element
{
    int u,v,w;
    element(int uu,int ww)
    {
        u = uu;
        w = ww;
    }
    bool operator<(const element a)const
    {
        return w <a.w;
    }
    bool operator >(const element a)const
    {
        return w>a.w;
    }

};
bool cmp(struct element a,struct element b)
{
    return a.u<b.u;
}
priority_queue < element ,vector<element>, greater <element> > q;

vector <struct element> g[300005];
void dijkstra()
{
    q.push(element(0,0));
    dis[0] =0;
    int cnt = 0;
    while(!q.empty())
    {
        cnt++;
        element t = q.top();
        q.pop();
        vis[t.u] = 1;
        sort(g[t.u].begin(),g[t.u].end(),cmp);
        for(int i=0;i<g[t.u].size();i++)
        {
            int now = g[t.u][i].u;
            int d = g[t.u][i].w;
            if(vis[now]== -1 && dis[t.u]+ d < dis[now] && dis[t.u]!=inf)
            {
                parent[now] = t.u;
                dis[now] = dis[t.u]+ d;
                q.push(element(now,dis[now]));
            }
        }
    }
}
void findParent(int x)
{
    if(x == -1 )return ;
    findParent(parent[x]);
    printf("%d\n",x);
}
main()
{
    int i,mu,mv,mw;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++){
        g[i].clear();
        dis[i] = inf;
        vis[i] = -1;
        parent[i] = -1;
    }
    for(i=0;i<m;i++)
    {
        scanf("%d %d %d",&mu,&mv,&mw);
        g[mu].push_back(element(mv,mw));
        g[mv].push_back(element(mu,mw));
    }
    dijkstra();
    for(i=0;i<n;i++)
    {
        if(dis[i]!=inf)printf("%d: %d\n",i,dis[i]);
        else printf("%d: Infinity\n",i);
    }
    findParent(1);
    return 0;

}
