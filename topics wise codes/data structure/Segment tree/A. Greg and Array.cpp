#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
using namespace std;

struct info
{
    ll sum,prop;
}tree[4*100009];

struct tripple
{
    ll l,r,d;
}tra[100009];

ll ara[100009];

void push_down(ll node, ll beg, ll mid, ll endd)
{
    ll left= node*2;
    ll right= node*2+1;

    tree[left].prop+=tree[node].prop;
    tree[right].prop+= tree[node].prop;

    tree[left].sum+= (mid-beg+1)*tree[node].prop;
    tree[right].sum+= (endd-mid)*tree[node].prop;

    tree[node].prop=0;

}

void update(ll node, ll beg, ll endd, ll i, ll j, ll val)
{
    if(beg>j || endd<i) return;

    if(beg>=i && endd<=j)
    {
        tree[node].prop+=val;
        tree[node].sum+= (endd-beg+1)*val;
        return ;
    }

    ll left= node*2;
    ll right= node*2+1;

    ll mid= (beg+endd)/2;

    update(left, beg, mid, i,j,val);
    update(right, mid+1, endd, i ,j,val);

    push_down(node,beg,mid,endd);

    tree[node].sum= tree[left].sum + tree[right].sum;

}

ll query(ll node, ll beg, ll endd, ll indx)
{
    if(beg==indx && endd==indx)
    {
        return tree[node].sum;
    }

    ll left= node*2;
    ll right= node*2+1;

    ll mid= (beg+endd)/2;

    ll t;

    push_down(node,beg,mid,endd);

    if(indx<=mid)
        t=query(left,beg, mid, indx);
    else
        t=query(right, mid+1, endd, indx);

    return t;
}

int main()
{
    ll n,m,k;
    scanf("%lld %lld %lld",&n,&m,&k);

    for(ll i=1;i<=n;i++)
    {
        scanf("%lld",&ara[i]);
    }

    for(ll i=1;i<=m;i++)
    {
        scanf("%lld %lld %lld",&tra[i].l, &tra[i].r, &tra[i].d);
    }

    ll x,y;


    for(ll i=1;i<=k;i++)
    {
        scanf("%lld %lld",&x,&y);

        update(1,1,m, x,y, 1);
    }


    for(ll i=1;i<=m;i++)
    {
        tra[i].d*=query(1,1,m,i);
       // prllf("%d\n",tra[i].d);
    }

    ms(tree,0);

    for(ll i=1;i<=m;i++)
    {

        update(1, 1 ,n, tra[i].l, tra[i].r, tra[i].d);
    }

    for(ll i=1;i<=n;i++)
    {
        printf("%lld ", query(1,1,n,i)+ara[i]);
    }
    puts("");


    return 0;
}
