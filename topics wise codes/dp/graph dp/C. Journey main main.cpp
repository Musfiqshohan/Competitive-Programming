#include<bits/stdc++.h>
#define ll long long
#define inf 100000000000000;
using namespace std;
ll  dp[5009][5009], dir[5009];
vector<ll>adj[5009];
vector<ll>spent[5009];
ll n;
ll f(ll index, ll num)
{

    if(index == n && num==0) return dp[index][num]=0;
    if(num<0) return INT_MAX;
    if( dp[index][num]!=-1) return  dp[index][num];

    ll mn=INT_MAX;

    for(ll i=0; i<adj[index].size(); i++)
    {
        ll node= adj[index][i];

        ll res=spent[index][i] + f(node,num-1);
        if(res<=mn)
        {

            mn=res;
        }

    }

    return dp[index][num]=mn;

}


ll print_path(ll index, ll num, ll cnt)
{

    if(index == n && num==0)
    {
        return 0;
    }

    ll mn=inf;
    ll mnx=0;

    for(ll i=0; i<adj[index].size(); i++)
    {
        ll node= adj[index][i];

         if(spent[index][i]+dp[node][num-1]<=mn && dp[node][num-1]!=-1)
        {
            mn=spent[index][i]+dp[node][num-1];
            mnx=node;
        }

    }

    dir[index]=mnx;
    return 1+print_path(mnx,num-1,cnt+1);

}

int main()
{
    memset(dp,-1,sizeof dp);
    memset(dir,-1,sizeof dir);
    ll m,T,u,v,t;

    scanf("%lld %lld %lld",&n,&m,&T);

    for(ll i=0; i<m; i++)
    {
        scanf("%lld %lld %lld",&u,&v,&t);

        adj[u].push_back(v);
        spent[u].push_back(t);
    }

    ll mn=inf;
    ll res=0,i;

    for(i=n; i>=2; i--)
    {

        res= f(1,i-1);

        if(res<=T) break;

    }



    cout<<print_path(1,i-1,0)+1<<endl;

    i=1;
    while(dir[i]!=n)
    {
        printf("%lld ",i);
        i=dir[i];
    }

    printf("%lld %lld\n",i,n);

    return 0;
}
