#include<bits/stdc++.h>
#define ms(a,b) memset(a,b,sizeof a);
#define ll long long
using namespace std;

vector<ll>adj[300009];

ll ara[300009], disAll[300009], disOneOut[300009], vis[300009];

void f(ll src)
{
    for(ll i=0;i<adj[src].size();i++)
    {
        ll node =adj[src][i];

        if(vis[node]==0)
        {
            vis[node]=1;

          //  printf("all=%lld  oneout=%lld\n",disAll[src], disOneOut[src]);

            ll temp1= __gcd(disAll[src],ara[node]);
            ll temp2= disAll[src];
            ll temp3= __gcd(disOneOut[src],ara[node]);

            printf("%lld->%lld  =%lld %lld %lld\n",src,node,temp1,temp2,temp3);

            disAll[node]=temp1;
            disOneOut[node]= max(temp2,temp3);

            f(node);
        }

    }

}

int main()
{
    ll n,u,v;
    scanf("%lld",&n);

    for(ll i=1;i<=n;i++) scanf("%lld",&ara[i]);

    for(ll i=1;i<=n-1;i++)
    {
        scanf("%lld %lld",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vis[1]=1;
    disAll[1]=ara[1];
    disOneOut[1]=0;

    f(1);
    for(ll i=1;i<=n;i++)
    {
        printf("%lld ", max(disAll[i], disOneOut[i]));
    }
    puts("");


    return 0;
}

/*
4
12 3 4 3
1 2
2 3
3 4
*/
