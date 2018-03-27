///https://vjudge.net/contest/149387#problem/J
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

const int MAX =100009*4;
vector<int>vec;
int ara[100009];

vector<int>seg[MAX];

void build(int nd, int b, int e)
{
    if(b==e)
    {
        seg[nd].push_back(ara[b]);

      //  printf("%d %d %d\n",b,e,ara[b]);
        return ;
    }


    int mid= (b+e)/2;

    int lc= nd*2;
    int rc=nd*2+1;

    build(lc, b, mid);
    build(rc,mid+1, e);

    merge(seg[lc].begin(), seg[lc].end(), seg[rc].begin(), seg[rc].end(),back_inserter(seg[nd]));

}

int query(int nd, int b, int e, int i, int j,int v)
{
    if(b>j || e<i)return 0;

    if(b>=i && e<=j)
    {
        int k= upper_bound(seg[nd].begin(), seg[nd].end(), v) - seg[nd].begin();

      //  printf("root= %d to %d =%d\n",b,e,k);

        return k;
    }

    int mid= (b+e)/2;

    int lc= nd*2;
    int rc=nd*2+1;

    int t1=query(lc,b,mid,i,j,v);
    int t2=query(rc,mid+1,e,i,j,v);


  //  printf("%d %d = %d\n",b,e,t1+t2);

    return t1+t2;

}

int main()
{
    int n,m;

    scanf("%d %d",&n,&m);

    for(int i=1; i<=n; i++)
    {

        scanf("%d",&ara[i]);
        vec.push_back(ara[i]);
    }

    sort(vec.begin(), vec.end());

    for(int i=1; i<=n; i++)
    {
        ara[i]= lower_bound(vec.begin(), vec.end(), ara[i]) - vec.begin()+1;
    }


    build(1,1,n);

//    for(int i=0;i<seg[1].size();i++)
//        printf("%d ",seg[1][i]);
//
//    puts("");
//
//    return 0;

    while(m--)
    {
        int i,j,k;
        scanf("%d %d %d",&i,&j,&k);


        int low=1, high=n, mid,cnt=0;

        while(cnt++<32)
        {
            mid=(low+high)/2;

            int res= query(1,1,n,i,j,mid);


            if(res<k)
            {
                low=mid;
            }
            else
                high=mid;
        }


        if(query(1,1,n,i,j,mid)<k) mid++;


        printf("%d\n",vec[mid-1]);

    }


    return 0;
}
