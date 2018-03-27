#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<int,int>
#define inf 100000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int n,m,k, b_size,xorsum,tot;
struct query
{
    int l,r,i;
}Q[100009];

int ara[100009],cntAra[1000009],answer[100009];

bool cmp(query a, query b)
{
    if(a.l/b_size == b.l/b_size)
        return a.r<b.r;
    return a.l/b_size < b.l/b_size;
}


inline void Add(int pos)
{
    cntAra[ara[pos]]++;
    xorsum=k^ ara[pos];
    tot+= cntAra[xorsum];
    printf("Axor= %d cntAra=%d pos=%d tot=%d\n",xorsum,cntAra[xorsum],pos,tot);

}

inline void Remove(int pos)
{
    cntAra[ara[pos]]--;
    xorsum=k^ ara[pos];
    tot-= cntAra[xorsum];
    printf("Rxor= %d cntAra=%d pos=%d tot=%d\n",xorsum,cntAra[xorsum],pos,tot);

}


int main()
{

    scanf("%d %d %d",&n,&m,&k);
    b_size=sqrt(n);

    rep(i,n)
    scanf("%d",&ara[i]);

    rep(i,m)
    {
        scanf("%d %d",&Q[i].l, &Q[i].r);
        Q[i].i=i;
    }

    sort(Q,Q+m, cmp);

    int curL=0, curR=-1,L,R;
    rep(i,m)
    {
        L=Q[i].l-1;
        R=Q[i].r-1;

        while(curR<R)
        {
            curR++;
            Add(curR);
        }

        while(curR>R)
        {
            Remove(curR);
            curR--;
        }

        while(curL<L)
        {
            Remove(curL);
            curL++;

        }

        while(curL>L)
        {
            curL--;
            Add(curL);

        }

        printf("tot= %d\n",tot);
            answer[Q[i].i]=tot;

    }

    for(int i=0;i<m;i++)
        printf("%d\n",answer[i]);


    return 0;
}
