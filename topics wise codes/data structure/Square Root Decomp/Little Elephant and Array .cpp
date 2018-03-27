#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
#define loop(i,n) for(int i=0;i<n;i++)
#define ll long long
#define pii pair<int,int>
#define inf 100000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
using namespace std;
int b_size,cnt;
struct query
{
    int l,r,i;
} Q[100009];

int ara[100009], answer[100009], tot[100009];

inline void Add(int pos)
{
    int num=ara[pos];
    if(num==-1) return;

    if(tot[num]==num)
        cnt--;

    tot[num]++;

    if(tot[num]==num)
        cnt++;
        //printf("here=%d\n",num);
}


inline void Remove(int pos)
{
    int num=ara[pos];
    if(num==-1) return;

    if(tot[num]==num)
        cnt--;
        // printf("Remo=%d\n",num);
    tot[num]--;
    if(tot[num]==num)
        cnt++;
}

bool cmp(query a, query b)
{
    if(a.l/b_size == b.l/b_size)
        return a.r<b.r;
    return a.l<b.l;
}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);

    for(int i=1; i<=n; i++)
    {
        scanf("%d",&ara[i]);
        if(ara[i]>100005)
            ara[i]=-1;
    }

    for(int i=1; i<=m; i++)
    {
        cin>>Q[i].l>>Q[i].r;
        Q[i].i=i;
    }


    b_size=sqrt(n);
    sort(Q,Q+m,cmp);


    int curL=1, curR=0;
    for(int i=1; i<=m; i++)
    {
        int L=Q[i].l, R=Q[i].r;
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

        answer[Q[i].i]=cnt;

    }

    for(int i=1; i<=m; i++)
        printf("%d\n",answer[i]);

    return 0;
}
