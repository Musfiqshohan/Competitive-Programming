#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pr pair<int, int>
using namespace std;

ll m=1000000007;

ll tree[4*100009];

bool compare(pr a, pr b)
{
    if(a.first==b.first) return a.second<b.second;
    return a.first<b.first;

}

vector<pair<ll, ll> >tup;

void update(ll node, ll beg, ll endd, ll targ, ll val)
{

    if(beg==targ && endd==targ)
    {
        //printf("%d %d %d\n",targ, node, val);
        tree[node]=val;
        return;
    }

    ll left=node*2;
    ll right=left+1;

    ll mid= (beg+endd)/2;

    if(targ<=mid)
        update(left,beg,mid,targ, val);
    else
        update(right, mid+1, endd, targ, val);

    tree[node]=tree[left]+tree[right];

}

ll query(ll node, ll beg, ll endd, ll i, ll j)
{
    if(beg>j || endd<i) return 0;

    if(beg>=i && endd<=j)
    {
        //printf("%d %d %d\n",beg,endd, tree[node]);
        return tree[node];
    }


    ll left= node*2;
    ll right= node*2 +1;

    ll mid= (beg+endd)/2;

    ll t1=query(left,beg,mid, i,j);
    ll t2=query(right,mid+1,endd, i, j);

    return (t1+t2)%m;

}


int main()
{
    int t=0,test;
    cin>>test;

    while(t<test){

    ll n,x;
    scanf("%lld",&n);

    for(int i=0;i<n;i++) {scanf("%lld",&x);  tup.push_back({x,i});   }

    sort(tup.begin(), tup.end(), compare);

    ll sum=0,num,cumsum=0;


    for(int i=0;i<tup.size();i++)
    {
        if(i-1>=0 && tup[i].first==tup[i-1].first)
        {
            num= query(1,0,n-1, 0, tup[i].second-1)+1 - cumsum;
            sum= (sum+num)%m;
            cumsum= (cumsum + num)%m;
            update(1,0,n-1,tup[i].second,num);
        }

        else{
        num= query(1,0,n-1, 0, tup[i].second-1 )+1;
        sum= (sum+num)%m;
        update(1,0,n-1,tup[i].second,num);
        cumsum=num;

        }
    }

    printf("Case %d: %lld\n",++t,sum);
    ms(tree,0);
    tup.clear();


    }
    return 0;
}
