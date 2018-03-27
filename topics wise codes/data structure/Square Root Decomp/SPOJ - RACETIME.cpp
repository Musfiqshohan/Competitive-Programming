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

const i64 MAXN=320;

i64 bucket[MAXN][MAXN], cnt[MAXN],ara[MAXN*MAXN];
i64 Bsize;
void build(i64 n)
{
    Bsize=sqrt(n);
    i64 m=n/Bsize;
    if(n%Bsize!=0) m++;

    i64 x;
    for(i64 i=0; i<n; i++)
    {
        scanf("%lld",&x);
        ara[i]=x;
        i64 bno=i/Bsize;
        bucket[bno][cnt[bno]]=x;
        cnt[bno]++;
    }
    for(i64 i=0; i<m; i++)
        sort(bucket[i], bucket[i]+cnt[i]);
}

i64 findd(i64 bno, i64 X)
{
    i64 l=0,r=cnt[bno]-1,mid,cntt=32;
    while(cntt--)
    {
        mid=(l+r)/2;
        if(bucket[bno][mid]<=X)
            l=mid;
        else r=mid;
    }

    if(mid+1<=r && bucket[bno][mid+1]<=X) mid++;

    if(bucket[bno][mid]>X) return 0;
    return mid+1;
}


i64 query(i64 P, i64 Q, i64 X)
{

    i64 lbno=P/Bsize, rbno=Q/Bsize;

    i64 tot=0;

    if(lbno==rbno)
    {
        for(i64 i=P; i<=Q; i++)
            if(ara[i]<=X)   tot++;

        return tot;
    }


    for(i64 i=P; i<(lbno+1)*Bsize; i++)
        if(ara[i]<=X)  tot++;


    for(i64 i=rbno*Bsize; i<=Q; i++)
        if(ara[i]<=X) tot++;



    for(i64 i=lbno+1; i<rbno; i++)
        tot+= findd(i,X);


    return tot;
}

void update(i64 pos, i64 v)
{
    i64 bno=pos/Bsize;
    i64 bpos;
    for(int i=0; i<cnt[bno]; i++)
    {
        if(bucket[bno][i]==ara[pos])
        {
            bucket[bno][i]=ara[pos]=v;
            bpos=i;
            break;
        }
    }


    while(bpos-1>=0 && bucket[bno][bpos-1]>bucket[bno][bpos])
    {
        swap(bucket[bno][bpos-1], bucket[bno][bpos]);
        bpos--;
    }

    while(bpos+1<cnt[bno] && bucket[bno][bpos+1]< bucket[bno][bpos])
    {
        swap(bucket[bno][bpos+1], bucket[bno][bpos]);
        bpos++;
    }


}
int main()
{
    i64 n,q;
    scanf("%lld %lld",&n,&q);
    build(n);

    i64 x,v,P,Q,X;
    while(q--)
    {
        char str[4];
        scanf("%s",&str);

        if(str[0]=='M')
        {
            scanf("%lld %lld",&x,&v);
            update(x-1,v);
        }
        else
        {
            scanf("%lld %lld %lld",&P,&Q,&X);
            i64 ret=query(P-1,Q-1,X);
            printf("%lld\n",ret);
        }
    }



    return 0;

}
