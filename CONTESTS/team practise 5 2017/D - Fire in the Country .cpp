 #include<bits/stdc++.h>
using namespace std;
int a[2000][2000];
int n,m,flag=0;

int fire[20005];
bool vis[2005];

void bfs(int src)
{
    fire[src] = 1;
    vis[src] = 1;

    queue<int> q;

    q.push(src);

    while(!q.empty())
    {
        int top = q.front();
        q.pop();

        int i, u;

        for(i=1; i<=n; i++)
        {
            if(a[top][i]==1)
            {
                if(vis[i]==0)
                {
                    vis[i] = 1;
                    fire[i] = fire[top] + 1;
                    q.push(i);
                }
            }
        }
    }

}

int f(int node, int days)
{

    vis[node]=1;
    int i,t;
    for(i=1; i<=n; i++)
    {
        if(a[node][i]==1)
        {

            if(fire[i]>days )
            {
                t=f(i,days+1);
                if(t==0){   return 1;    }
            }

        }
    }

    vis[node]=0;
    return 0;

}


int  main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int i,j,x,y;
    scanf("%d %d",&n,&m);

    for(i=1; i<=m; i++)
    {
        scanf("%d %d",&x,&y);
        a[x][y]=a[y][x]=1;
    }



    bfs(1);

    memset(vis,0,sizeof(vis));



   flag= f(1,1) ;
    if(flag==1)  printf("Vladimir\n");
    else   printf("Nikolay\n");



    return 0;
}
