#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
using namespace std;

ll cnt1[2000009], cnt2[2000009] ,ara[2000009];

struct info
{
    ll mx,mn;
} tree[2000009*4];

ll n,x;
map<ll,ll>occur;
map<ll,ll>occur1;
void build(ll signal)
{



    if(signal==1)
    {
        for(ll i=1;i<=n;i++)
        {
            occur[ara[i]]++;
            cnt1[i]= occur[ara[i]];
        }
    }
    else
    {

        for(ll i=n;i>=1;i--)
        {
            occur1[ara[i]]++;
            cnt2[i]=occur1[ara[i]];
        }

    }
}

void update(ll node, ll beg, ll endd, ll indx, ll val)
{
    if(beg==indx && endd==indx)
    {
        tree[node].mx=val;
        tree[node].mn=val;

        return ;
    }

    ll left=node*2;
    ll right=node*2+1;

    ll mid=(beg+endd)/2;

    if(indx<=mid)
        update(left,beg,mid, indx, val);
    else
        update(right,mid+1,endd , indx ,val);

    tree[node].mx= max(tree[left].mx,tree[right].mx);
    tree[node].mn= min(tree[left].mn,tree[right].mn);

}

ll  query(ll node, ll beg, ll endd, ll i, ll j, ll l)
{
    if(beg>j || endd<i) return 0;
  //  if(beg>endd) return 0;
   // if(beg==endd && tree[node]>=l) return 0;
    if(beg>=i && endd<=j )
    {
        //prllf("Inside= beg=%d  endd=%d  i=%d  j=%d  l=%d max=%d\n",beg,endd,i,j,l,tree[node]);
        if(tree[node].mx<l)
        return endd-beg+1;

        if(tree[node].mn>=l) return 0;
        if(beg==endd) return 0;
    }


    ll left=node*2;
    ll right=node*2+1;

    ll mid=(beg+endd)/2;

    ll t1= query(left,beg, mid, i, j, l);
    ll t2= query(right, mid+1,endd, i,j, l);

    return t1+t2;

}

int main()
{
    for(ll i=0;i<=2000009*4;i++) {  tree[i].mn=1; tree[i].mx=1;  }

    ll total=0;
    scanf("%lld",&n);

    for(ll i=1;i<=n;i++)
        scanf("%lld",&ara[i]);



    build(1);
    //occur.clear();
    build(-1);


    for(ll i=n-1;i>=1;i--)
    {
        ll l= cnt1[i];
        ll r= cnt2[i];

        //prllf("loop  from= %d  to=%d\n",i+1,n);
        ll num= query(1,1,n, i+1, n, l);

       // prllf("i=%d j=%d  l=%d num=%d r=%d\n",i,i+1,l,num,r);
        total+=num;

        update(1, 1,n , i, r);

    }


    cout<<total<<endl;



    return 0;
}
