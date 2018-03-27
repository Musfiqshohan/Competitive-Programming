#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<ll,ll>
#define inf 100000000000
using namespace std;

ll ara[100009];

struct info
{
    ll mn, num, gcd;

}tree[4*100009];


info merged(info l, info r, ll beg, ll endd)
{

    info temp;

    temp.gcd= __gcd(l.gcd, r.gcd);

   // prllf("merging= %d %d -> %d %d %d\n",beg,endd, temp.gcd, l.gcd, r.gcd);

    if(l.mn<r.mn) { temp.mn=l.mn;  temp.num=l.num; }
    else if(l.mn>r.mn) { temp.mn=r.mn; temp.num=r.num; }
    else
    {
        temp.mn=l.mn;
        temp.num= l.num + r.num;
    }

    return temp;

}

void build(ll node, ll beg, ll endd)
{

    if(beg==endd)
    {
        tree[node].mn=ara[beg];
        tree[node].num= 1;
        tree[node].gcd= ara[beg];

        return;
    }

    ll left= node*2;
    ll right= node*2+1;

    ll mid= (beg+endd)/2;


    build(left, beg, mid);
    build(right,mid+1, endd);

    tree[node]=merged(tree[left],tree[right], beg,endd);

}

info query(ll node, ll beg, ll endd, ll i, ll j)
{
    if(beg>j || endd<i) return {inf,0, 0};

    if(beg>=i && endd<=j)
    {
       // if(tree[node].gcd== tree[node].mn) return tree[node].num;

        //prllf("Reached: %d %d %d\n",beg,endd, tree[node].gcd);
        return tree[node];
    }

   ll left= node*2;
    ll right= node*2+1;

    ll mid= (beg+endd)/2;

    info t1= query(left, beg,mid, i,j);
    info t2= query(right, mid+1, endd, i, j);

    return merged(t1,t2,beg,endd);

}

int main()
{
    ll n,m,x,y;
    scanf("%lld",&n);

    for(ll i=0;i<n;i++)
        scanf("%lld",&ara[i]);

    build(1, 0, n-1);

    scanf("%lld",&m);

    for(ll i=0;i<m;i++)
    {
        scanf("%lld %lld",&x,&y);

        info res=query(1,0,n-1, x-1,y-1);

        if(res.gcd==res.mn) printf("%lld\n", y-x+1 - res.num);
        else printf("%lld\n", y-x+1);

    }

    return 0;
}
