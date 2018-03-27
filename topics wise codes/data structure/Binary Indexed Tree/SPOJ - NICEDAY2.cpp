///https://vjudge.net/contest/149387#problem/G
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
const int MAXN=100009;




struct info
{
    int a, b,c;
} ara[MAXN];

int BIT[MAXN];



void prepare(int n)
{
    for(int i=0; i<=n; i++)
        BIT[i]=INT_MAX;
}

int query(int idx, int n)
{
    int mn=INT_MAX;

    while(idx>0)
    {
        mn= min(mn,BIT[idx]);
        idx-=(idx&-idx);
    }

    return mn;
}

void update(int idx, int n,int v)
{
    while(idx<=n)
    {
        BIT[idx]= min(BIT[idx],v);
        idx+=(idx&-idx);
    }
}


bool cmp(info x, info y)
{
    return x.a<y.a;
}
int main()
{
    int tt;
    cin>>tt;

    while(tt--)
    {

        int n;
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            scanf("%d %d %d",&ara[i].a, &ara[i].b,&ara[i].c);
        }

        sort(ara, ara+n,cmp);

        prepare(n+1);
        int cnt=0;
        for(int i=0; i<n; i++)
        {
            int ret= query(ara[i].b,n+1);
            if(ret>ara[i].c)
                cnt++;

            update(ara[i].b,n+1,ara[i].c);
        }

        printf("%d\n",cnt);
        ms(BIT,0);
        ms(ara,0);

    }

    return 0;
}
