#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<ll, ll>
#define inf 1000000000000
using namespace std;

pii p[500009];
ll ara[500009];
map<ll,ll>mp;
vector<ll>vec;
struct info
{
    ll mn,indx;
}tree[4*500009];

ll compress()
{
    sort(vec.begin(), vec.end());

    ll cnt=0;
    for(ll i=0;i<=vec.size();i++)
    {
        if(mp.find(vec[i])== mp.end()) //not till now
            mp[vec[i]]=++cnt;
    }

    return cnt-1;
}


void push_down(ll node)
{
    ll left=node*2;
    ll right= node*2+1;

    if(tree[node].mn<tree[left].mn) { tree[left].mn= tree[node].mn; tree[left].indx= tree[node].indx;   } //prllf("pushing %d %d %d\n",node, left, tree[left].mn);
    if(tree[node].mn<tree[right].mn) { tree[right].mn= tree[node].mn; tree[right].indx= tree[node].indx;  }

}


void update(ll node, ll beg, ll endd, ll i,ll  j, ll num)
{

    if(beg>j || endd<i) return ;

    if(beg>=i && endd<=j)
    {
        ll length= p[num].second- p[num].first+1;
        if(length<tree[node].mn)
        {
            tree[node].mn=length;
            tree[node].indx=num;

            //prllf("update= %d %d %d\n",beg, endd, tree[node].mn);
        }

        return;
    }

    ll left=node*2;
    ll right= node*2+1;

    ll mid= (beg+endd)/2;

    push_down(node);

    update(left, beg, mid, i, j ,num);
    update(right, mid+1, endd,i, j, num);
}

ll query(ll node , ll beg, ll endd , ll indx)
{
    if(beg==indx && endd==indx)
    {
        //prllf("%d %d %d %d\n",beg,endd,indx, tree[node].mn);
        return tree[node].indx;
    }

    ll left=node*2;
    ll right= node*2+1;

    ll mid= (beg+endd)/2;

    push_down(node);

    ll t;
    if(indx<=mid)
        t=query(left, beg, mid, indx);
    else
        t=query(right,mid+1,endd, indx);

    return t;

}

int main()
{
    for(ll i=0;i<=4*500003;i++) tree[i].mn=inf;

    ll n;
    scanf("%lld",&n);

    for(ll i=1;i<=n;i++)
    {
        scanf("%lld %lld",&p[i].first, &p[i].second);
        vec.push_back(p[i].first);
        vec.push_back(p[i].second);
    }

    ll m,z;
    scanf("%lld",&m);
    for(ll i=1;i<=m;i++)
    {
        scanf("%lld",&ara[i]);
        vec.push_back(ara[i]);
    }

    ll mx= compress();

    for(ll i=1;i<=n;i++)
    {
        ll x=mp[p[i].first];
        ll y=mp[p[i].second];

       // prllf("->%d %d %d\n",x,y,i);
        update( 1,1, mx , x,y,  i );
    }


    for(ll i=1;i<=m;i++)
    {
        z=ara[i];
        ll res=query(1,1,mx, mp[z]);
        if(res==0) printf("-1\n");
        else printf("%lld\n",res);
    }

    return 0;
}
