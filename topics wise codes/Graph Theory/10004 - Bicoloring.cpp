#include<bits/stdc++.h>
using namespace std;
vector<int>edge[1000];
int vis[1000],color[1000];
int flag=0;
void bfs(int node)
{
    int i,next_node;
    queue<int>q;

    q.push(node);

    while(!q.empty())
    {

        node= q.front();
        q.pop();

        for(i=0; i< edge[node].size(); i++)
        {
            next_node=edge[node][i];
            if(vis[next_node]==-1)
            {
                color[next_node]=color[node]+1;
                vis[next_node]= color[next_node]%2;
                q.push(next_node);


            }

            else if(vis[next_node]== vis[node])
                flag=1;

        }


    }

}
//pair<int,int>p[1000];
int main()
{
    int cnt=0;
    while(1) {

    memset(vis,-1,sizeof(vis));
    memset(color,0,sizeof(color));

    int n,m,i,x,y;
    cin>>n;
    if(n==0) break;

    cin>>m;

    for(i=0; i<m; i++)
    {
        cin>>x>>y;
//        p[i].first=x;
//        p[i].second=y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }

    flag=0;
    vis[0]= 0;
    color[0]=0;
    bfs(0);


    if(flag==1) printf("NOT BICOLORABLE.\n");
    else printf("BICOLORABLE.\n");

    for(i=0;i<1000;i++)
        edge[i].clear();

//    cnt++;
//    if(cnt==78)
//    {
//
//        cout<<"Fuck"<<n<<" "<<m<<endl;
//        for(i=0;i<m;i++)
//        {
//            cout<<p[i].first<<" " <<p[i].second<<endl;
//        }
//        printf("Fuck end\n");
//
//    }

    }

    return 0;
}
