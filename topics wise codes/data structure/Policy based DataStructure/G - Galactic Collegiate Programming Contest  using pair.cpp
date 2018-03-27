///https://vjudge.net/contest/191052#problem/G
///using pbds

#include<bits/stdc++.h>

///These are for pbds
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/detail/standard_policies.hpp>

#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<int,int>
#define inf 100000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
#define rep(i,n) for(int i=0;i<n;i++)
#define MP(x,y) make_pair(x,y)

using namespace std;
using namespace __gnu_pbds;

typedef pair<pair<int,int>,int>PI;

typedef tree<PI,null_type, less<PI>, rb_tree_tag,
tree_order_statistics_node_update> set_t;

const int mx=1e5+10;
int ps[mx],pp[mx];

int main()
{
    set_t s;

    int n,m,t,p;

   cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        s.insert(MP(MP(0,0),i+1));
    }

    rep(i,m)
    {
        cin>>t>>p;
        s.erase(MP(MP(-ps[t],pp[t]),t));
        ps[t]++;
        pp[t]+=p;
        s.insert(MP(MP(-ps[t],pp[t]),t));
        cout<<s.order_of_key(MP(MP(-ps[1],pp[1]),1))+1<<endl;

    }



    return 0;
}
