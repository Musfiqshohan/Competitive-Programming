    #include<bits/stdc++.h>


    #define pb push_back
    #define ms(a,b) memset((a),(b),sizeof(a))
    #define ll long long
    #define pii pair<int,int>
    #define inf 100000000000
    #define in(a) freopen(a,"r", stdin)
    #define out(a) freopen(a,"w",stdout)
    using namespace std;

    struct node
    {
        int x,y,ni,mi;
    };
    node ara[205];

    int Graph[205][205], rGraph[205][205], parent[205];


    double Calculate_Distance(node a, node b)
    {
        return sqrt(
                   (a.x-b.x)*(a.x-b.x)
                   +(a.y-b.y)*(a.y-b.y)
               );
    }


    int bfs(int s, int t)
    {
        bool vis[205];

        memset(vis,0,sizeof vis);

        vis[s]=true;
        queue<int>q;
        q.push(s);

        while(!q.empty())
        {
            int u= q.front();
            q.pop();

            for(int v=0; v<=200; v++)
            {
                if(vis[v]==0 && rGraph[u][v]>0)
                {
                    // printf("%d->%d %d\n",u,v,rGraph[u][v]);
                    vis[v]=true;
                    q.push(v);
                    parent[v]=u;
                }
            }
        }


        return (vis[t]==true);

    }

    int fordFulkerson(int s, int t)
    {
        for(int i=0; i<=200; i++)
            for(int j=0; j<=200; j++)
                rGraph[i][j]= Graph[i][j];

        int max_flow=0;

    //   puts("hi");


        //cout<<bfs(s,t)<<endl;

        while(bfs(s,t))
        {
            int path_flow=INT_MAX;

            for(int v=t; v!=s; v=parent[v])
            {
                int u= parent[v];
                // printf("path %d -> %d\n",u,v);
                path_flow= min(path_flow, rGraph[u][v]);
            }

            for(int v=t; v!=s ; v=parent[v])
            {
                int u= parent[v];
                rGraph[u][v]-=path_flow;
                rGraph[v][u]+=path_flow;
            }

            // cout<<path_flow<<endl;

            // puts("End");
            max_flow+=path_flow;

        }

        return max_flow;


    }

    int main()
    {
        int tt=0,test;
        scanf("%d",&test);

        while(tt<test)
        {
            int n;
            double d;
            scanf("%d",&n);
           scanf("%lf",&d);

            int totPenguins=0;
            for(int i=1; i<=n; i++)
            {
                scanf("%d %d %d %d",&ara[i].x, &ara[i].y, &ara[i].ni, &ara[i].mi);

                Graph[i][i+100]=ara[i].mi;

                totPenguins+=ara[i].ni;

            }


            for(int i=1; i<=n; i++)
            {
                for(int j=i+1; j<=n; j++)
                {

                    double dis=Calculate_Distance(ara[i],ara[j]);
                    if(dis<=d)
                    {
                        Graph[i+100][j]=1001;
                        Graph[j+100][i]=1001;
                    }
                }
            }

            for(int i=1; i<=n; i++)
            {
                Graph[0][i]=ara[i].ni;
            }

            vector<int>vec;

           // for(int sink=1; sink<=n; sink++)
          //  {
                int sink=2;
                int res= fordFulkerson(0,sink);

                if(res==totPenguins)
                    vec.push_back(sink);


           // }

            printf("Case %d: ",++tt);
            if(vec.size()==0) printf("-1\n");
            else
            {
                for(int i=0; i<vec.size(); i++)
                    {
                        if(i) printf(" ");
                        printf("%d",vec[i]-1);

                    }

                puts("");
            }


            ms(Graph,0);
            ms(rGraph,0);
            vec.clear();
            ms(parent,0);
            ms(ara,0);


        }

    }

