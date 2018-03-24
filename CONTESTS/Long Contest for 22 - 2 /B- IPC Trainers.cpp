///https://vjudge.net/contest/212042#problem/B   pass:tfc22

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
#define mod 1000000007
using namespace std;

struct info
{
    int di,ti,si;
    bool operator <(const info &n) const
    {
        return si<n.si;
    }
} ara[100009];


bool cmp(info a, info b)
{
    return a.di<b.di;
}
int main()
{

    int tt;
    cin>>tt;

    while(tt--)
    {

        int n,d;
        cin>>n>>d;
        for(int i=0; i<n; i++)
        {
            scanf("%d %d %d",&ara[i].di, &ara[i].ti, &ara[i].si);
        }

        sort(ara,ara+n,cmp);

        priority_queue<info>pq;



        for(int i=1, j=0; i<=d; i++)
        {
            while(j<n && ara[j].di==i)
            {
                // printf("%d %d %d\n",ara[j].di, ara[j].si, ara[j].ti);
                pq.push(ara[j]);
                j++;
            }

            info t;
            if(!pq.empty())
            {
                t=pq.top();
                pq.pop();
                t.ti--;
                if(t.ti>0)
                    pq.push(t);

            }
        }

        i64 tot=0;
        while(!pq.empty())
        {
            info t=pq.top();
            pq.pop();
            tot+=(i64)t.ti*t.si;
        }

        cout<<tot<<endl;


    }

    return 0;
}
