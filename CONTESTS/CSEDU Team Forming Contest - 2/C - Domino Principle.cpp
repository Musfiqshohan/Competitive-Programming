#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
using namespace std;

struct tripple
{
    ll first,second, indx, num;
}ara[100009];
ll n,u;
ll srch(ll low, ll high, ll targ)
{
    ll mid,cnt=0;
    while(cnt++<=32)
    {
        mid= low + (high-low)/2;
         //printf("%d %d %d\n",mid, ara[mid].first , targ);

        if(ara[mid].first<=targ)
            low=mid;
        else
            high=mid-1;
    }

    if(ara[mid+1].first<=targ && mid+1<=n) return mid+1;
    if(ara[mid].first>targ) return mid-1;
    return mid;

}

ll tree[4*100009];
void update(ll node, ll beg ,ll endd, ll indx, ll val)
{
    //printf("%d %d %d %d\n",node,beg,endd,indx);
    if(beg==indx && endd ==indx)
    {
        tree[node]=val;
       // printf("%d %d %d\n",beg, node, tree[node]);
       //puts("");
        return ;
    }
    ll left=node*2;
    ll right=node*2+1;

    ll mid=(beg+endd)/2;

    if(indx<=mid)
        update(left,beg,mid, indx, val);
    else
        update(right,mid+1,endd,indx,val);

    tree[node]=max(tree[left], tree[right]);
}

ll query(ll node, ll beg, ll endd, ll i, ll j)
{
    //printf("%d %d %d %d %d\n",node,beg,endd,i,j);
    if(beg>j || endd<i) return INT_MIN;

    if(beg>=i && endd<=j)
    {
      //  printf("%lld %lld %lld\n",beg,endd,tree[node]);



        return tree[node];
    }

    ll left=node*2;
    ll right=node*2+1;

    ll mid=(beg+endd)/2;

    ll l= query(left,beg, mid, i, j);
    ll   r= query(right,mid+1,endd, i, j);

    return max(l,r);


}

bool compare1(tripple a, tripple b)
{
    return a.first<b.first;
}
bool compare2(tripple a, tripple b)
{
    return a.indx<b.indx;
}
int main()
{
   // for(int i=1;i<=4*100009;i++) tree[i]=INT_MIN;
   ms(tree,-1);
    scanf("%lld",&n);

    for(int i=1;i<=n;i++)
    {
        scanf("%lld %lld",&ara[i].first, &ara[i].second);
        ara[i].indx=i;

    }

    sort(ara+1,ara+n+1, compare1);

//    for(int i=1;i<=n;i++)
//    {
//        update(1,1,n, i, ara[i].first+ara[i].second-1);
//    }


  //  cout<<query(1,1,n,3,3)<<endl;

    ll total=0;

    for(int i=n;i>=1;i--)
    {
        ll dis= ara[i].first+ara[i].second-1;
        ll indx= srch(i,n,dis);

        ll last=query(1,1,n,i,indx);

        if(last>indx) indx=last;

        update(1,1,n, i, indx);

//       // printf("%lld %lld %lld\n",dis, indx, h);
//        ll indx2= srch(i,n, h);

        total= indx-i+1;


     //   printf("%lld\n",total);
        ara[i].num=total;
    }

     sort(ara+1,ara+n+1, compare2);

    for(int i=1;i<=n;i++) printf("%lld ",ara[i].num);
    puts("");
    return 0;
}
