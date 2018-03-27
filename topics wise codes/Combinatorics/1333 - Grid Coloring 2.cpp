#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll unsigned long long
#define pii pair<ll,ll>
#define inf 100000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
using namespace std;

ll mod=1000000000LL;

struct info
{
    ll x,y;
};


bool exist[1000009];
vector<ll>exist1;
vector<ll>adj[1000009];


void clearr()
{
   ms(exist,0);
   exist1.clear();


}

bool compare(info a, info b)
{
    if(a.y==b.y)
        return a.x<b.x;
    return a.y<b.y;

}

ll pow1(ll x, ll n)
{
    if(n==0) return 1;
    if(n%2==0)
    {
        ll ret= pow1(x,n/2);
        return (ret*ret)%mod;
    }

    return (x* pow1(x,n-1))%mod;

}

ll f1(ll m,ll n, ll k)
{

    return (pow1(k,n) *  pow1( (k-1), ((m-1)*n)%mod ) )%mod;

}

int main()
{

        in("1333I.txt");
    out("1333O.txt");

    ll test,tt=0;
    cin>>test;

    while(tt<test)
    {


    ll N,M,k,B,x,y;


    scanf("%lld %lld %lld %lld",&M,&N,&k,&B);


    ll row=M, col= N;

    for(ll i=0; i<B; i++)
    {
        scanf("%lld %lld",&x,&y);


        adj[y].push_back(x);


        if(exist[y]==false)
        {
            exist1.push_back(y);
            exist[y]=true;
            col--;
        }

    }



    ll ans1= f1(M, col ,k)%mod;


    for(ll i=0;i<exist1.size();i++)
    {
        ll col=exist1[i];
        sort(adj[col].begin(), adj[col].end());

        ll uniq=0;

        if(adj[col][0]!=1)
            {
                uniq++;
            }

        for(ll j=0;j<adj[col].size()-1;j++)
        {
            if(adj[col][j]+1 != adj[col][j+1])
                uniq++;
        }

        if(adj[col][ adj[col].size()-1 ]!=M) uniq++;
        ll block= adj[col].size() ;


        ll a1= ((M- block)-uniq);


        ll rs1= pow1(k-1, a1);

        ll rs2= pow1(k,uniq);

       // cout<<ans2<<" "<<rs1<<" "<<rs2<<endl;

        ll res=1;
        res=(rs1*rs2)%mod;

        ans1= ( ans1 * res )%mod;

        adj[col].clear();
    }



    printf("Case %lld: %lld\n",++tt,ans1);


    clearr();

    }


    return 0;
}
