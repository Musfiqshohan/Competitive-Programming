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

void update(ll node, ll beg, ll endd, ll i, ll j, ll val)
{
    if(beg>j || endd<i) return;

    if(beg>=i && endd<=j)
    {
        //printf("%d -> %d %d %d\n",beg,endd, i,j);
        tree[node].sum+=  (endd-beg+1)*val;
        tree[node].prop+=val;
        return ;
    }

    ll left=node<<1;
    ll right=(node<<1)+1;

    ll mid= (beg+endd)/2;

    update(left, beg, mid, i,j, val);
    update(right, mid+1, endd, i,j, val);

    tree[node].sum=tree[left].sum+ tree[right].sum + (endd-beg+1)*tree[node].prop;
}


ll query(ll node, ll beg, ll endd, ll i, ll j, ll carry)
{

    if(beg>j || endd<i) return 0;
    if(beg>=i && endd<=j)
    {
        return tree[node].sum+ (endd-beg+1)*carry;
    }


    ll left=node*2;
    ll right= node*2+1;

    ll mid=(beg+endd)/2;

    ll t1= query(left, beg, mid, i,j, carry+tree[node].prop);
    ll t2= query(right, mid+1, endd, i, j, carry+tree[node].prop);

    return t1+t2;
}
int main()
{
    ll t=0,test;
    cin>>test;

    while(t++<test){

   // printf("Case %lld:\n",++t);
    ll n,q,cs,x,y,v;

    scanf("%lld %lld",&n,&q);
    for(ll i=0;i<q;i++)
    {
        scanf("%lld",&cs);

        if(cs==0)
        {
            scanf("%lld %lld %lld",&x,&y,&v);
            update(1,1,n,x,y,v);

        }
        else
        {
            scanf("%lld %lld",&x,&y);

            printf("%lld\n", query(1,1,n,x,y,0));
        }
    }

    ms(tree,0);

    }

    return 0;
}
