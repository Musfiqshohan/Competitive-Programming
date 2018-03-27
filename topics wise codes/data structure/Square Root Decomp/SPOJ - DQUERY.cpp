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
struct query
{
    int l,r,i;

} Q[200009];

int b_size,ara[30009],tot,answer[200009], cntAra[1000009];

bool cmp(query a, query b)
{
    if(a.l/b_size == b.l/b_size)
        return a.r<b.r;
    return a.l/b_size<b.l/b_size;

}

inline void Add(int pos)
{
    cntAra[ara[pos]]++;

    if(cntAra[ara[pos]]==1)
        tot++;
}

inline void Remove(int pos)
{
    cntAra[ara[pos]]--;

    if(cntAra[ara[pos]]==0)
        tot--;

}
int main()
{
    int n,q;
    scanf("%d",&n);
    b_size=sqrt(n);

    for(int i=0; i<n; i++)
        scanf("%d",&ara[i]);

    scanf("%d",&q);

    rep(i,q)
    {
        scanf("%d %d",&Q[i].l, &Q[i].r);
        Q[i].i=i;
    }

    sort(Q,Q+q,cmp);

    int curL=0, curR=-1;
    rep(i,q)
    {
        int L=Q[i].l-1;
        int R=Q[i].r-1;

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

        //printf("tot= %d\n",tot);

        answer[Q[i].i]=tot;

    }

    for(int i=0;i<q;i++)
        printf("%d\n",answer[i]);

}
