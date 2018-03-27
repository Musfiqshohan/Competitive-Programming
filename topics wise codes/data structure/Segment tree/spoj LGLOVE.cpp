///https://vjudge.net/contest/149388#problem/G
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
const i64 mod= 1000000007;

struct info
{
    i64 mx, mn, prop;
} tree[4*400009];
i64 ara[400009],lcm[400009];




void sieve(i64 LIM)
{

    //LIM=100000;

    lcm[1]=1;

    for(i64 i=2; i<=LIM; i++)
    {
        if(lcm[i]==0)
        {

            for(i64 j=i*2; j<=LIM; j+=i)
            {
                lcm[j]=1;
            }


            for(i64 j=i;j<=LIM;j=j*i)
            {
                lcm[j]=i;
            }
        }

        lcm[i]=lcm[i-1]*lcm[i];
        lcm[i]%=mod;


       // printf("%lld %lld\n",i,lcm[i]);

    }



}


info Merge(info a, info b)
{
    info ret;
    ret.mx=max(a.mx,b.mx);
    ret.mn=min(a.mn,b.mn);
    ret.prop=0;

    return ret;
}


void build(i64 nd, i64 b, i64 e)
{
    if(b==e)
    {
        tree[nd]= {ara[b],ara[b],0};
        return ;
    }


    i64 mid=(b+e)/2;

    i64 lc= nd*2;
    i64 rc= nd*2+1;



    build(lc, b, mid);
    build(rc, mid+1, e);

    tree[nd]=Merge(tree[lc],tree[rc]);
}


void Propagate(i64 nd, i64 lc,i64 rc)
{

    tree[lc].prop+=tree[nd].prop;
    tree[rc].prop+=tree[nd].prop;

    tree[lc].mn+=tree[nd].prop;
    tree[rc].mn+=tree[nd].prop;

    tree[lc].mx+=tree[nd].prop;
    tree[rc].mx+=tree[nd].prop;

}
info query(i64 nd, i64 b, i64 e, i64 i,i64 j)
{
    if(b>j || e<i) return {0, INT_MAX, 0};

    if(b>=i && e<=j)
    {
        //printf("%lld %lld %lld %lld\n",b,e, tree[nd].mn, tree[nd].mx);

        return tree[nd];
    }


    i64 mid=(b+e)/2;

    i64 lc= nd*2;
    i64 rc= nd*2+1;


    Propagate(nd,lc,rc);
    tree[nd].prop=0;



    info t1=query(lc, b,mid, i, j);
    info t2=query(rc,mid+1,e,i,j);


    info ret= Merge(t1,t2);


    assert(ret.mx>=0 && ret.mn>=0);
    return ret;

}

void update(i64 nd, i64 b, i64 e, i64 i, i64 j, i64 v)
{
    if(e<i || j<b ) return;

    if(b>=i && e<=j)
    {
        tree[nd].mx+=v;
        tree[nd].mn+=v;
        tree[nd].prop+=v;

        // printf("%lld %lld %lld %lld\n",b,e, tree[nd].mn, tree[nd].mx);

        return ;
    }

    i64 mid=(b+e)/2;

    i64 lc= nd*2;
    i64 rc= nd*2+1;

    Propagate(nd,lc,rc);

    update(lc,b,mid,i,j,v);
    update(rc,mid+1,e,i,j,v);


    tree[nd]=Merge(tree[lc],tree[rc]);

}


int main()
{

    sieve(300009);

   // return 0;
//    preprc();


    i64 n, m,x,y,v,cs;

    scanf("%lld %lld",&n,&m);

    for(i64 i=1; i<=n; i++)
        scanf("%lld",&ara[i]);


    build(1,1,n);



    info res;
    for(i64 i=0; i<m; i++)
    {
        scanf("%lld",&cs);
        if(cs==0)
        {
            scanf("%lld %lld %lld",&x,&y,&v);
            x++,y++;
            update(1,1,n,x,y,v);

            // printf("%lld %lld\n",tree[1].mn, tree[1].mx);
        }
        else if(cs==1)
        {
            scanf("%lld %lld",&x,&y);
            x++,y++;
            res= query(1,1,n,x,y);
           // printf("%lld %lld\n",res.mn, res.mx);


            printf("%lld\n",lcm[res.mx]);
        }
        else
        {
            scanf("%lld %lld",&x,&y);
            x++,y++;
            res= query(1,1,n,x,y);

          //  printf("%lld %lld\n",res.mn, res.mx);
            printf("%lld\n",lcm[res.mn]);
        }
    }



    return 0;
}

