#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<ll,ll>
#define inf 100000000000
using namespace std;

pii p[500009];
vector<ll>vec;
map<ll,ll>mp;

ll tree[500009*4], ara[500009];
ll mx=0;
void compress()
{
    ll cnt=0;
    for(ll i=0;i<vec.size();i++)
    {
        ll x=vec[i];
        if(mp.find(x)==mp.end()) // not till now
        {
            mp[x]=cnt++;
        }
    }
    mx=cnt-1;
}

void push_down(ll node)
{
    ll left=node*2;
    ll right= node*2+1;

    tree[left]+=tree[node];
    tree[right]+=tree[node];
    tree[node]=0;
}


void update(ll node, ll beg, ll endd, ll x, ll y)
{
    if(beg>y || endd<x) return;

    if(beg>=x && endd<=y)
    {
        tree[node]++;

        return;
    }

    ll left= node*2;
    ll right= node*2+1;


    ll mid= (beg+endd)/2;

    push_down(node);
    update(left, beg,mid, x,y);
    update(right, mid+1, endd, x,y);

}

ll query(ll node, ll beg, ll endd, ll indx)
{
    if(beg==indx && endd==indx)
        return tree[node];

    ll left= node*2;
    ll right= node*2+1;

    ll mid= (beg+endd)/2;

    push_down(node);

    ll t1=0;
    if(indx<=mid)
        t1=query(left, beg, mid, indx);
    else t1=query(right, mid+1, endd, indx);

    return t1;
}

int main()
{
//    freopen("input1089.txt","r",stdin);
//    freopen("output1089.txt","w",stdout);

    ll t=0,test;
    cin>>test;

    while(t<test) {
    printf("Case %lld:\n",++t);
    ll n,q,x,y;
    scanf("%lld %lld",&n,&q);

    for(ll i=0;i<n;i++)
    {
        scanf("%lld %lld",&p[i].first,&p[i].second);

        vec.push_back(p[i].first);
        vec.push_back(p[i].second);
    }

    for(ll i=0;i<q;i++)
    {
        scanf("%lld",&ara[i]);
        vec.push_back(ara[i]);
    }

    sort(vec.begin(), vec.end());

    compress();

//    prllf("mx= %d\n",mx);
//    for(ll i=0;i<vec.size();i++)
//    {
//        prllf("%d -> %d\n",vec[i], mp[vec[i]]);
//    }

    for(ll i=0;i<n;i++)
    {
        ll x= mp[p[i].first];
        ll y= mp[p[i].second];

       // prllf("x=%d y=%d\n",x,y);
        update(1,0,mx,x,y);
    }

    for(ll i=0;i<q;i++)
    {
        x=mp[ara[i]];
      //  prllf("questy =%d\n",x);
        printf("%lld\n",query(1,0,mx,x));
    }

    vec.clear();
    ms(tree,0);
    mp.clear();

    }

    return 0;
}
