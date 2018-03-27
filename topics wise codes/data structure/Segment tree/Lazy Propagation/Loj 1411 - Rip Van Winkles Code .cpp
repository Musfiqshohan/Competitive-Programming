///http://lightoj.com/volume_showproblem.php?problem=1411
#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define i64 long long
#define pii pair<i64,i64>
#define INF 100000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
#define rep(i,n) for(i64 i=0;i<n;i++)
using namespace std;
const i64 MAXN=250009;

struct info
{
    i64 a,d,sum,flag;
    i64 Sa, Sd;
} T[4*MAXN+5];


void init()
{
    ms(T,0);
    for(i64 i=0; i<=(MAXN*4)+3; i++)
        T[i].flag=INF;

}

i64 calc(i64 a, i64 d, i64 n)
{
    i64 sum=2*a+ (n-1)*d;
    sum= (sum*n)/2;

    return sum;

}


void update_node(i64 nd, i64 b, i64 e,i64 Fa, i64 Fd)
{
    T[nd].a+=Fa;
    T[nd].d+=Fd;
    T[nd].sum+= calc(Fa,Fd,e-b+1);
}

void update_node2(i64 nd, i64 b, i64 e,i64 Fa, i64 Fd)
{
    T[nd].Sa+=Fa;
    T[nd].Sd+=Fd;
    T[nd].sum+= calc(Fa,-Fd,e-b+1);

}

void update_node3(i64 nd, i64 b, i64 e, i64 v)
{
    T[nd].a=T[nd].d=0;
    T[nd].sum=v*(e-b+1);
    T[nd].flag=v;

    T[nd].a=T[nd].d=T[nd].Sa=T[nd].Sd=0;
}



void Lazy_update(i64 nd,i64 b, i64 e)
{
    i64 mid=(b+e)/2;
    i64 lc=nd*2;
    i64 rc=(nd*2)+1;


    if(T[nd].flag!=INF)
    {
        update_node3(lc,b,mid,T[nd].flag);
        update_node3(rc,mid+1,e,T[nd].flag);


    }




    if(T[nd].a!=0)
    {
        update_node(lc,b,mid, T[nd].a, T[nd].d);
        update_node(rc,mid+1,e, T[nd].a+(mid-b+1)*T[nd].d, T[nd].d);

    }

    if(T[nd].Sa!=0)
    {
        update_node2(lc,b,mid, T[nd].Sa, T[nd].Sd);
        update_node2(rc,mid+1,e, T[nd].Sa-(mid-b+1)*T[nd].Sd, T[nd].Sd);
    }

    T[nd].a=T[nd].d=T[nd].Sa=T[nd].Sd=0;
    T[nd].flag=INF;

}

void update(i64 nd, i64 b, i64 e, i64 i, i64 j, i64 first)
{
    if(b>j || e<i) return;

    if(b>=i && e<=j)
    {
        update_node(nd,b,e,first,1);
        return;
    }

    i64 mid=(b+e)/2;
    i64 lc=nd*2;
    i64 rc=(nd*2)+1;

    Lazy_update(nd,b,e);

    i64 t1=max(mid- max(b,i)+1,0LL);

    update(lc,b,mid,i,j,first);
    update(rc,mid+1,e,i,j,first+t1);

    T[nd].sum= T[lc].sum+T[rc].sum;
}

void update2(i64 nd, i64 b, i64 e, i64 i, i64 j, i64 first)
{

    if(b>j || e<i) return;

    if(b>=i && e<=j)
    {
        update_node2(nd,b,e,first,1);
        return;
    }

    i64 mid=(b+e)/2;
    i64 lc=nd*2;
    i64 rc=(nd*2)+1;

    Lazy_update(nd,b,e);

    i64 t1=max(mid- max(i,b)+1,0LL);

    update2(lc,b,mid,i,j,first);
    update2(rc,mid+1,e,i,j,first-t1);

    T[nd].sum= T[lc].sum+T[rc].sum;
}

void update3(i64 nd, i64 b, i64 e, i64 i, i64 j, i64 v)
{
    if(b>j || e<i) return;

    if(b>=i && e<=j)
    {
        update_node3(nd,b,e,v);
        return;
    }

    i64 mid=(b+e)/2;
    i64 lc=nd*2;
    i64 rc=(nd*2)+1;

    Lazy_update(nd,b,e);

    update3(lc,b,mid,i,j,v);
    update3(rc,mid+1,e,i,j,v);

    T[nd].sum= T[lc].sum+T[rc].sum;

}


i64 query(i64 nd, i64 b, i64 e, i64 i, i64 j)
{
    if(b>j || e<i) return 0;

    if(b>=i && e<=j)
    {

        return T[nd].sum;
    }

    i64 mid=(b+e)/2;
    i64 lc=nd*2;
    i64 rc=(nd*2)+1;

    Lazy_update(nd,b,e);

    i64 t1=query(lc,b,mid,i,j);
    i64 t2=query(rc,mid+1,e,i,j);

    return t1+t2;
}




int main()
{

    i64 tt=0,test;
    scanf("%lld",&test);

    while(tt<test)
    {

        printf("Case %lld:\n",++tt);

        i64 Q,x,y,v;
        scanf("%lld",&Q);

        init();

        getchar();
        while(Q--)
        {
            char cs[5];
            scanf("%s",&cs);

            if(cs[0]=='A')
            {
                scanf("%lld %lld",&x,&y);
                update(1,1,MAXN, x,y,1);
            }
            else if(cs[0]=='B')
            {
                scanf("%lld %lld",&x,&y);
                update2(1,1,MAXN, x,y, y-x+1);
            }
            else if(cs[0]=='C')
            {
                scanf("%lld %lld %lld",&x,&y,&v);
                update3(1,1,MAXN,x,y,v);

            }
            else
            {
                scanf("%lld %lld",&x,&y);
                i64 res= query(1,1,MAXN,x,y);

                printf("%lld\n",res);
            }

        }
    }
}
