/// problem link:

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

const i64 MAXN=10009;
struct info
{
    i64 maxL, maxR, sum,maxS;
} tree[4*MAXN];
i64 ara[MAXN];

info merge(info t1, info t2)
{
    info ret;

    ret.maxL= max(t1.maxL, t1.sum+ t2.maxL);
    ret.maxR= max(t2.maxR, t2.sum+ t1.maxR);

    ret.sum= t1.sum+ t2.sum;

    ret.maxS= max(t1.maxR+ t2.maxL, max(t1.maxS, t2.maxS));

    return ret;
}

info build(i64 node, i64 b, i64 e)
{
    if(b==e)
    {
        tree[node]= {ara[b],ara[b], ara[b], ara[b]};
        return tree[node];
    }

    i64 mid=(b+e)/2;

    i64 l=node*2;
    i64 r=node*2+1;

    info t1,t2;
    t1=build(l, b, mid);
    t2=build(r, mid+1, e);

    return  tree[node]=merge(t1,t2);

}

info query(i64 node, i64 b, i64 e, i64 i, i64 j)
{
    if(b>j || e<i) return {-1000000000,-1000000000,0,-1000000000};

    if(b>=i && e<=j)
        return tree[node];


    i64 mid=(b+e)/2;

    i64 l=node*2;
    i64 r=node*2+1;

    info t1= query(l, b, mid, i, j);
    info t2= query(r, mid+1, e, i,j);

    return merge(t1,t2);

}


int main()
{
    i64 tt;
    cin>>tt;

    while(tt--)
    {


        i64 n;
        scanf("%lld",&n);

        for(i64 i=1; i<=n; i++)
            scanf("%lld",&ara[i]);

        build(1,1,n);


        i64 x1,y1,x2,y2;


        i64 m;
        scanf("%lld",&m);

        for(i64 q=0; q<m; q++)
        {

            scanf("%lld %lld %lld %lld",&x1,&y1, &x2,&y2);


            i64 tot=0;
            info ret1,ret2,ret3;
            i64 tot2,tot1,tot3;
            if(x2>y1)
            {
                ret1= query(1,1,n, x1,y1);
                ret2= query(1,1,n, y1+1,x2-1);
                ret3= query(1,1,n,x2,y2);

//                pri64f("%d %d %d\n",ret1.maxL, ret1.maxR, ret1.sum);
//                pri64f("%d %d %d\n",ret2.maxL, ret2.maxR, ret2.sum);
//                pri64f("%d %d %d\n",ret3.maxL, ret3.maxR, ret3.sum);

                tot=ret1.maxR+ ret2.sum+ ret3.maxL;
            }
            else if(x2<y1)
            {
                ret1= query(1,1,n, x1,x2);
                ret2= query(1,1,n, x2+1,y2);
                tot1= ret1.maxR+ max(0LL,ret2.maxL);

             //   printf("%d + %d? =%d\n",ret1.maxR, ret2.maxL,tot1);

                ret1= query(1,1,n, x1,y1);
                ret2= query(1,1,n, y1+1, y2);
                tot2=ret1.maxR+ max(0LL,ret2.maxL);

                ret1=query(1,1,n,x2,y1);
                tot3=ret1.maxS;

             //   printf("%d + %d? =%d\n",ret1.maxR,ret2.maxL,max(0LL,ret2.maxL));

                tot= max(tot1,tot2);
                tot= max(tot,tot3);
            }
            else
            {
                ret1=query(1,1,n, x1,y1);
                tot= ret1.maxR;


                if(x2+1<=y2)
                    ret2= query(1,1,n, x2+1,y2), tot+=max(0LL,ret2.maxL);
            }

            printf("%lld\n",tot);


        }

        ms(tree,0);
        ms(ara,0);

    }



    return 0;
}
