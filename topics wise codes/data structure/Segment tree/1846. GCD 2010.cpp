#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<ll,ll>
#define inf 100000000000
using namespace std;

map<ll, ll>mp;

struct info{
    ll val,num;
}tree[4*100009];

void update(ll node, ll beg, ll endd, ll indx, ll val)
{

    if(beg==indx && endd==indx)
    {

        if(val<0)
        tree[node].num--;
        else
            tree[node].num++;

        if(tree[node].num>0)
            tree[node].val= abs(val);
        else tree[node].val=0;

        return;
    }

    ll left= node*2;
    ll right= node*2+1;

    ll mid= (beg+endd)/2;

    if(indx<=mid)
        update(left, beg, mid, indx, val);

    else update(right, mid+1, endd, indx, val);

    tree[node].val= __gcd(tree[left].val, tree[right].val);
}

int main()
{

    ll q;
    ll n=101009;
    scanf("%lld",&q);
    getchar();

    ll cnt=0,flag=0;
    for(ll i=0;i<q;i++)
    {
        ll x;
        char sign;
        scanf("%c %lld",&sign,&x);
        getchar();

        if(mp.find(x)==mp.end())
        {
            mp[x]=++cnt;
        }

        ll indx= mp[x];

        if(sign=='+')
            update(1,1,n, indx, x );
        else
            update(1,1,n, indx, -x);

        if(x==0 && sign=='+') flag=1;
        if(x==0 && sign=='-') flag=0;


        if(tree[1].val==0 && flag==0) printf("1\n");
        else
        printf("%lld\n",tree[1].val);

    }





    return 0;
}
