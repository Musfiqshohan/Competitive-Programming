#include<bits/stdc++.h>
using namespace std;


vector<long long>adj[10009];

struct circle{
    long long x,y,r;

}Circle[10009];

long long check(circle c1, circle c2)
{

    long long X= c1.x-c2.x;
    long long Y= c1.y-c2.y;
    long long dif= (X*X + Y*Y);

  //  prlong longf("res = %d %d %d =%d\n", X, Y, dif, (c1.r+ c2.r)*(c1.r+ c2.r));

    if( (dif)==(c1.r+ c2.r)*(c1.r+ c2.r)) return 1;

    return 0;
}

long long vis[10009];

struct frac{
    long long n,d,rot;
}dis[10009];


void clearr()
{
    for(long long i=0;i<10019;i++) adj[i].clear();
    memset(vis,0,sizeof vis);
    memset(dis,0,sizeof dis);

}


void BFS(long long src)
{

    queue<long long>q;
    q.push(src);
    dis[src]={1,1,1};
    vis[src]=1;

    while(!q.empty())
    {
        long long u=q.front();
        q.pop();

        for(long long i=0;i<adj[u].size();i++)
        {
            long long node= adj[u][i];

            if(vis[node]==0)
            {
                vis[node]=1;

                dis[node]= { Circle[u].r * dis[u].n , Circle[node].r*dis[u].d ,  dis[u].rot^1};
              //  printf("%d %d->%d %d\n", u, dis[u].rot, node, dis[u].rot);
               // prlong longf("%d-> %d   nu=%d  deno=%d\n", src,node, Circle[src].r * dis[src].n, Circle[node].r*dis[src].d);

                q.push(node);

            }

        }

    }



}


int main()
{
//
//    freopen("input6930.txt", "r", stdin);
//    freopen("output6930.txt", "w", stdout);

    long long test;
    cin>>test;

    while(test--) {


    long long n;
    scanf("%lld",&n);

    for(long long i=1;i<=n;i++)
    {
        scanf("%lld %lld %lld",&Circle[i].x, &Circle[i].y, &Circle[i].r);
    }


    //cout<<check(Circle[1],Circle[2])<<endl;

    for(long long i=1;i<=n;i++)
    {
        for(long long j=i+1;j<=n;j++)
        {
            if( check(Circle[i],Circle[j]) ==1 )
            {
                adj[i].push_back(j);


               // printf("%d ->%d\n",i,j);
            }
        }
    }




    BFS(1);

    for(long long i=1;i<=n;i++)
    {

        long long gcd= __gcd(dis[i].n, dis[i].d);
        if(vis[i]==0 || gcd==0) { printf("not moving\n"); continue; }

        long long x= dis[i].n / gcd;
        long long y= dis[i].d / gcd;

        printf("%lld",x);
        if(y>1) printf("/%lld",y);
        if(dis[i].rot==1) printf(" clockwise\n");
        else printf(" counterclockwise\n");
        //prlong longf("\n");
    }

    clearr();

    }

    return 0;
}
