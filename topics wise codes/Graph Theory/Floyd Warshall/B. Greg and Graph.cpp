#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<ll,ll>
#define inf 100000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
using namespace std;
vector<ll>vec,res;
ll ara[509][509],vis[509];
int main()
{
    ll n,x;
    scanf("%lld",&n);

    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=n;j++)
            scanf("%lld",&ara[i][j]);
    }

    for(ll i=0;i<n;i++)
    {
        scanf("%lld",&x);
        vec.push_back(x);
    }

    reverse(vec.begin(), vec.end());



    for(ll l=0;l<vec.size(); l++)
    {
        ll k= vec[l];

        vis[k]=1;
        ll sum=0;

        for(ll i=1;i<=n;i++)
        {



            for(ll j=1;j<=n;j++)
            {


                if(ara[i][k]+ ara[k][j] < ara[i][j])
                {
                    ara[i][j]= ara[i][k]+ara[k][j];

                }


            }

        }

        for(ll i=1;i<=n;i++)
            for(ll j=1;j<=n;j++)
                {
                    if(vis[i]==1 && vis[j]==1)
                        sum+=ara[i][j];  }

        //prllf("reversly %d\n",sum);

        res.push_back(sum);

    }

   reverse(res.begin(), res.end());

    for(ll i=0;i<res.size();i++)
        printf("%lld ",res[i]);

    puts("");
    return 0;
}
