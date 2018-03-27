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

const int N= 4e5+9;
vector<int>vec;
vector<int>seg[N]
void build(int n , int b, int e)
{

    if(b==e)
    {
        seg[n]=ara[b];
        return ;
    }

    int mid=(b+e)/2;
    int lc=n*2;
    int rc=n*2+1;

    build(lc, b,mid);
    build(rc, mid+1,e);

    merge(seg[lc].begin(), seg[lc].end(),  seg[rc].begin(),  seg[rc].end(), back_in);

}


int query(int n, int b, int e, int i, int j, int v)
{
    if(b>j || e<i) return 0;


}


int main()
{
    int n,q;
    scanf("%d %d",&n,&q);

    for(int i=1;i<=n;i++)
    {
        scanf("%d",&ara[i]);
        vec.push_back(ara[i]);
    }

    sort(vec.begin(), vec.end());

    for(int i=1;i<=n; i++)
    {
        a[i]=lower_bound( vec.begin(), vec.end(), a[i]) - vec.begin()+1;
    }


    build(1,1,n);

    while(q--)
    {
        int l,r,x;
        scanf("%d %d %d",&l ,&r,&x);

        int low=1, high=n, mid,ans;

        while(low<=high)
        {
            mid=(low+high)/2;
            int k=query(1,1,n,l,r,mid);

            if(k>=x)
            {
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;

        }

        printf("%d\n",vec[ans-1]);
    }

    return 0;
}
