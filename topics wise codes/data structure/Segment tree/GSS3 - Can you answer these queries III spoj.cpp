#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define inf -100000000000
using namespace std;

struct info
{
    ll bestLeftSum;
    ll bestRightSum;
    ll sum;
    ll bestSum;
} tree[4*50009];


info merge1(info l, info r)
{
    info temp;
    temp.bestLeftSum=max( l.bestLeftSum,  l.sum+ r.bestLeftSum );
    temp.bestRightSum=max( r.bestRightSum, r.sum+l.bestRightSum);

    temp.sum=l.sum + r.sum;
    temp.bestSum= max( l.bestSum, max( r.bestSum, l.bestRightSum + r.bestLeftSum) );

    return temp;
}

void update(ll node, ll beg, ll endd, ll indx, ll val)
{
    // printf("%d %d %d %d\n",node,beg,endd, indx);
    if(beg==indx && endd==indx)
    {
        tree[node].bestLeftSum=val;
        tree[node].bestRightSum=val;
        tree[node].bestSum=val;
        tree[node].sum=val;
        return;
    }

    ll left= node*2;
    ll right= node*2+1;

    ll mid= (beg+endd)/2;

    if(indx<=mid)
        update(left, beg,mid, indx, val);
    else update(right, mid+1, endd, indx, val);

    info temp= merge1(tree[left],tree[right]);
    tree[node]=temp;
}

info query(ll node, ll beg, ll endd, ll i, ll j)
{

    if(beg>j || endd<i) return {inf,inf,0,inf};

    if(beg>=i && endd<=j)
    {
        return tree[node];
    }

    ll left= node*2;
    ll right= node*2+1;

    ll mid= (beg+endd)/2;

    info l=query(left, beg,mid, i,j);
    info r=query(right, mid+1, endd, i,j);

    return merge1(l,r);


}


int main()
{
    for(ll i=0; i<=4*50009; i++) tree[i]= {inf,inf,0,inf};
    ll n,x,y;
    scanf("%lld",&n);

    for(ll i=1; i<=n; i++)
    {
        scanf("%lld",&x);
        update(1, 1,n, i, x);
    }

    ll m;
    scanf("%lld",&m);
    int cs;
    for(ll i=0; i<m; i++)
    {
        scanf("%d",&cs);
        scanf("%lld %lld",&x,&y);
        if(cs==0)
            update(1,1,n,x,y);
        else
        {
            info res= query(1,1,n,x,y);
            printf("%lld\n",res.bestSum);
        }
    }

    return 0;
}

