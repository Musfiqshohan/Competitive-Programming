#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
using namespace std;
map<ll,ll>mp;

pair<ll, ll>par[2*100009];
vector<ll>v;
ll mx,cnt;
struct info
{
    ll mx,  prop;

} tree[4*100009];

void compress()
{

    for(ll i=0; i<v.size(); i++)
    {
        if(mp.find(v[i])==mp.end()) // not till now
        {
            mp[v[i]]=++cnt;
            // prllf("%d -> %d\n",v[i],cnt);
            mx=max(mx,cnt);
        }
    }
}

void push_down(ll node)
{
    ll left=node*2;
    ll right=node*2+1;

    tree[left].prop+=tree[node].prop;
    tree[right].prop+=tree[node].prop;

    tree[left].mx+=tree[node].prop;
    tree[right].mx+=tree[node].prop;

    tree[node].prop=0;
}

void update(ll node, ll beg, ll endd, ll i, ll j)
{
    if(beg>j || endd<i) return;

    if(beg>=i && endd<=j)
    {
        tree[node].prop++;
        tree[node].mx++;
        return;
    }

    ll left= node*2;
    ll right= node*2+1;

    ll mid=(beg+endd)/2;

    push_down(node);

    update(left, beg, mid, i,j);
    update(right, mid+1, endd, i, j);

    tree[node].mx=max(tree[left].mx, tree[right].mx);
}

ll query(ll node, ll beg, ll endd, ll i, ll j)
{
    //  prllf("%d %d %d %d %d\n",node,beg,endd, i, j);
    if(beg>j || endd<i) return 0;

    if(beg>=i && endd<=j)
    {
        //  prllf("Hello\n");
        return tree[node].mx;
    }

    ll left= node*2;
    ll right= node*2+1;

    ll mid=(beg+endd)/2;

    push_down(node);

    ll t1= query(left, beg, mid, i,j);
    ll t2= query(right, mid+1, endd, i, j);

    tree[node].mx=max(tree[left].mx, tree[right].mx);
    return max(t1,t2);
}

int main()
{
    ll n,x,y;
    scanf("%lld",&n);

    for(ll i=0; i<n; i++)
    {
        scanf("%lld %lld",&par[i].first,&par[i].second);
        v.push_back(par[i].first);
        v.push_back(par[i].second);
    }

    ll m;
    scanf("%lld",&m);

    for(ll i=n; i<m+n; i++)
    {
        scanf("%lld %lld",&par[i].first,&par[i].second);
        v.push_back(par[i].first);
        v.push_back(par[i].second);
    }

    sort(v.begin(), v.end());

    compress();


    for(ll i=0; i<n; i++)
    {
        x=par[i].first;
        y=par[i].second;

        update(1,1,mx, mp[x], mp[y]);
    }



//
//    v.clear();
//
//    ms(par,0);



//    sort(v.begin(), v.end());
//    compress();

    for(ll i=n; i<m+n; i++)
    {
        x=par[i].first;
        y=par[i].second;

        //printf("%lld->%lld %lld->%lld\n",x,mp[x],y,mp[y]);
        printf("%lld\n", query(1,1,mx, mp[x],mp[y]) );
    }


    return 0;
}
