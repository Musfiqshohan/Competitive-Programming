
#include <bits/stdc++.h>

using namespace std;

vector <int> G[1005],T[1005],SG[1005];
stack <int> S;
bool graph[1005];
bool taken[1005];
vector <int> vertex;
bool visit[1005];
vector <int> V;
vector <int> SCC[1005];
int scc[1005];
vector <pair <int,int> > E;
int indeg[1005],outdeg[1005];
map < pair <int,int>, bool >  DAG;

void DFS(int s)
{
    visit[s] = true;
    for(int i = 0; i < G[s].size(); i++)
    {
        int v = G[s][i];
        if(visit[v]==false)
        {
            DFS(v);
        }
    }
    S.push(s);
}

void dfs(int s, int cnt)
{
    visit[s] = true;
    scc[s]=cnt;
    SCC[cnt].push_back(s);
    for(int i = 0; i < T[s].size(); i++)
    {
        int v = T[s][i];
        if(visit[v]==false)
        {
            dfs(v,cnt);
        }
    }
}


void ddffss(int s)
{
    visit[s] = true;
    for(int i = 0; i < SG[s].size(); i++)
    {
        int v = SG[s][i];
        if(visit[v]==false)
        {
            ddffss(v);
        }
    }
    S.push(s);
}

void diefesh(int s)
{
    visit[s] = true;
    for(int i = 0; i < SG[s].size(); i++)
    {
        int v = SG[s][i];
        if(visit[v]==false)
        {
            diefesh(v);
        }
    }
}

int main()
{
    //freopen("in.txt","r",stdin);
    int TT;
    scanf("%d",&TT);
    for(int t = 1; t <= TT; t++)
    {
        memset(graph,false,sizeof(graph));
        memset(taken,false,sizeof(taken));
        memset(indeg,0,sizeof(indeg));
        memset(outdeg,0,sizeof(outdeg));
        memset(visit,false,sizeof(visit));
        int m, n,u,v;
        scanf("%d",&n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d",&m);
            for(int i = 0; i < m; i++)
            {
                scanf("%d %d",&u,&v);
                if(taken[v]==false)
                {
                    taken[v] = true;
                    vertex.push_back(v);
                }
                if(taken[u]==false)
                {
                    taken[u] = true;
                    vertex.push_back(u);
                }
                graph[u] = graph[v] = true;
                G[u].push_back(v);
                T[v].push_back(u);
                E.push_back(make_pair(u,v));
            }
        }
        sort(vertex.begin(),vertex.end());

        for(int i = 0; i < vertex.size(); i++)
        {

            if(visit[vertex[i]]==false)
            {

                DFS(vertex[i]);
            }
        }
//    cout << S.size() << endl;
//    cout << "hha" << endl;
        while(!S.empty())
        {
            V.push_back(S.top());
            S.pop();
        }
        memset(visit,false,sizeof(visit));
        int cnt=0;
        for(int i = 0; i < V.size(); i++)
        {
//            cout << V[i] << endl;
            if(visit[V[i]] == false and graph[V[i]])
            {

                dfs(V[i],cnt);
                cnt++;
            }
        }

        for(int i = 0; i < E.size(); i++)
        {
            pair <int,int> p = E[i];
            if(scc[p.first]!=scc[p.second])
            {
                if(DAG[p]==false)
                {

                    DAG[p]=true;
                    indeg[scc[p.second]]++;
                    outdeg[scc[p.first]]++;
                }
            }
        }
        V.clear();
        int inzero = 0,outzero = 0;

        bool bull = true;
        for(int i = 0; i < cnt; i++)
        {
            if(indeg[i] > 1)
            {
                bull = false;

            }
            if(outdeg[i] > 1)
            {
                bull = false;

            }
            if(indeg[i]==1 and outdeg[i]==1);
            else if(indeg[i]==0) inzero++;
            else if(outdeg[i]==0) outzero++;
        }
        if(inzero !=1 and outzero != 1)
        {

            bull = false;
        }
        if(indeg[scc[0]] > 0 or outdeg[scc[0]] != 1) bull = false;
        if(cnt==1) bull = true;
        if(taken[0]==false) bull = false;
        if(bull) printf("Case %d: YES\n",t);
        else printf("Case %d: NO\n",t);
        for(int i = 0; i <= 1000; i++)
        {
            if(G[i].size() > 0) G[i].clear();
            if(T[i].size() > 0) T[i].clear();
            if(SG[i].size() > 0) SG[i].clear();
        }
        E.clear();
        DAG.clear();
        vertex.clear();
        V.clear();
    }

    return 0;
}

