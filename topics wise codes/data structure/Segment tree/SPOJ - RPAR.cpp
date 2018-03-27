///https://vjudge.net/contest/149388#problem/F
#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define i64 long long
#define pii pair<i64,i64>
#define inf 100000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
#define rep(i,n) for(i64 i=0;i<n;i++)
using namespace std;
const i64 MAX=100009;
const i64 mod=10007;
pii cum[MAX];
i64 ara[MAX];

struct info
{
    i64 a,b,c,sum;
} tree[4*MAX];



i64 sqsum1(i64 n)
{
    if(n<=0) return 0;
    return cum[n].first;
   // return (n*(n+1)*(2*n+1))/6;
}
i64 sqsum(i64 b,i64 e)
{
   // return ((cum[e].first-cum[b].first)%mod + (b*b)%mod)%mod;
     return (sqsum1(e)-sqsum1(b-1) + mod)%mod;
}

i64 fsum1(i64 n)
{
    if(n<=0) return 0;
    return cum[n].second;
    //return (n*(n+1))/2;
}

i64 fsum(i64 b, i64 e)
{

    //return ((cum[e].second-cum[b].second)%mod+(b%mod))%mod;
     return (fsum1(e)-fsum1(b-1)+mod)%mod;
}

void update_node(i64 nd, i64 b, i64 e, i64 x, i64 y, i64 z)
{
    i64 res=0;

    res= (x*sqsum(b,e))%mod;
    res+= (y*fsum(b,e))%mod;
    res+= (z*((e-b+1)%mod))%mod;

    tree[nd].sum=(tree[nd].sum+res)%mod;
    tree[nd].a=  (tree[nd].a+x)%mod;
    tree[nd].b=  (tree[nd].b+y)%mod;
    tree[nd].c=  (tree[nd].c+z)%mod;
}


void propagate(i64 nd, i64 i, i64 j)
{

    if(tree[nd].a==0 && tree[nd].b==0 && tree[nd].c==0) return ;
    i64 mid=(i+j)/2;
    i64 lc=nd*2;
    i64 rc=(nd*2)+1;

    update_node(lc,i,mid,  tree[nd].a, tree[nd].b, tree[nd].c);
    update_node(rc,mid+1,j,tree[nd].a, tree[nd].b, tree[nd].c);
    tree[nd].a=tree[nd].b=tree[nd].c=0;

}
i64 update(i64 nd, i64 b, i64 e, i64 i, i64 j, info v)
{


    if(b>j || e<i) return 0;
    if(b>=i && e<=j)
    {

        update_node(nd,b,e,v.a, v.b, v.c);

        return tree[nd].sum;
    }

    i64 mid=(b+e)/2;
    i64 lc=nd*2;
    i64 rc=nd*2+1;

    propagate(nd,b,e);


    i64 t1=update(lc,b,mid,i,j,v);
    i64 t2=update(rc,mid+1,e,i,j,v);


    tree[nd].sum= (tree[lc].sum+ tree[rc].sum)%mod;

    return (t1+t2)%mod;

}



int main()
{

    i64 n,q,cs,x0,x1,a,b,c;
    scanf("%lld %lld",&n,&q);


    for(i64 i=1; i<=n; i++)
    {
        cum[i].first=((cum[i-1].first%mod)+(i*i)%mod)%mod;
        cum[i].second=(cum[i-1].second+i)%mod;

       // printf("%lld -> %lld\n",cum[i].first, sqsum1(i));
    }


   // return 0;


    while(q--)
    {
        scanf("%lld",&cs);

        i64 rest;
        if(cs==0)
        {
            scanf("%lld %lld %lld %lld %lld",&x0,&x1, &a,&b,&c );
            info v= {a,b,c,0};
            rest=update(1,0,n-1,x0,x1,v);

        }
        else
        {
            scanf("%lld %lld",&x0,&x1);

            //  pri64f("starting update\n");
            rest=update(1,0,n-1,x0,x1, {0,0,0,0});
            printf("%lld\n",rest);

            //pri64f("END\n");
        }


    }



    return 0;
}
