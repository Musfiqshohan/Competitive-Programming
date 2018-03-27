///http://codeforces.com/contest/855/problem/C
#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;
vector<ll>edge[100009];
vector<ll>seq;
ll par[100009],sib[100009], fc[100009];
ll dp[100009][12][2][2];

ll n,k,x,m;
void dfs(ll src, ll pr)
{
    par[src]=pr;
    for(ll i=0; i<edge[src].size(); i++)
    {
        ll node= edge[src][i];
        if(node!=pr)
        {
            dfs(node,src);
        }
    }
}

ll add(ll u, ll v)
{
    return (u+v)%MOD;
}
ll mul(ll w,ll u, ll v)
{
    if(w>=MOD) w%=MOD;
    if(u>=MOD) u%=MOD;
    if(v>=MOD) v%=MOD;

    ll temp=(w*u);
    if(temp>=MOD)
        temp%=MOD;

    return (temp*v)%MOD;
}


///k is value of maximum security
///m is number of different value types which needs to multiply
///x number of max security vaults
ll f(ll src, ll rem, bool par_flag, bool isGreater)
{


    if(src==-1)
    {

        if(rem>=0)
            return 1;
        else return 0;
    }

    if(dp[src][rem][par_flag][isGreater]!=-1) return dp[src][rem][par_flag][isGreater];

    ll ret=0;
    if(par_flag==false)
    {
        if(isGreater==false) ///  i can make it secure or not.  /// one is will i secure this or not, and how many remains
        {
            /// another is how many ways, i will count it later
            if(sib[src]==-1 && rem-1>=0) ret= add(ret, mul(1, f(fc[src], rem-1, true, true), 1) ); ///if no sibling take only
            else if(fc[src]==-1 && rem-1>=0)   ret= add(ret, mul(1, 1,  f(sib[src], rem-1, par_flag, isGreater)) );
            else if(sib[src]==-1 && fc[src]==-1)    return 1;
            else
            {
                for(ll i=0; i<rem; i++) ///lets secure first which can be in 1 way
                {
                    ret= add(ret, mul(1, f(fc[src], i, true, true), f(sib[src], rem-1-i, par_flag, isGreater)) ); /// false

                }

            printf("at %lld  rem=%lld par=%d  isGR=%d  res=%lld  where sec\n",src, rem, par_flag, isGreater,ret);
            }



            if(sib[src]==-1) ret= add(ret, mul( k-1, f(fc[src], rem,  false, false), 1 ));
            else if(fc[src]==-1)   ret= add(ret, mul( k-1, 1, f(sib[src], rem, par_flag, isGreater) ));
            else if(sib[src]==-1 && fc[src]==-1)return 1;
            else
            {
                for(ll i=0; i<=rem; i++) ///now i will not secure   and if smaller than K
                {
                    ret= add(ret, mul( k-1, f(fc[src], i,  false, false), f(sib[src], rem-i, par_flag, isGreater) ));
                }
            }

            printf("at %lld  rem=%lld par=%d  isGR=%d  res=%lld where small\n",src, rem, par_flag, isGreater,ret);


            if(sib[src]==-1) ret= add(ret, mul( m-k, f(fc[src], rem,  false, true), 1 ));
            else if(fc[src]==-1) ret= add(ret, mul( m-k, 1, f(sib[src], rem, par_flag, isGreater) ));
            else if(sib[src]==-1 && fc[src]==-1)return 1;
            else
            {
                for(ll i=0; i<=rem; i++) ///now i will not secure   and if greater or equal than k
                {
                    ret= add(ret, mul( m-k, f(fc[src], i,  false, true), f(sib[src], rem-i, par_flag, isGreater) ));
                }
            }

            printf("at %lld  rem=%lld par=%d  isGR=%d  res=%lld where grt\n",src, rem, par_flag, isGreater,ret);

        }
        else
        {
            if(sib[src]==-1) ret= add(ret, mul( k-1, f(fc[src], rem,  false, false), 1) );
            else if(fc[src]==-1) ret= add(ret, mul( k-1, 1, f(sib[src], rem, par_flag, isGreater) ));
            else if(sib[src]==-1 && fc[src]==-1)return 1;
            else
            {
                for(ll i=0; i<=rem; i++) ///now i will not secure   and if smaller than K
                {
                    ret= add(ret, mul( k-1, f(fc[src], i,  false, false), f(sib[src], rem, par_flag, isGreater) ));
                }
            }

            if(sib[src]==-1) ret= add(ret, mul( m-k, f(fc[src], rem,  false, true), 1 ));
            else if(fc[src]==-1) ret= add(ret, mul( m-k, 1, f(sib[src], rem, par_flag, isGreater) ));
            else if(sib[src]==-1 && fc[src]==-1)return 1;
            else
            {
                for(ll i=0; i<=rem; i++) ///now i will not secure   and if greater or equal than k
                {
                    ret= add(ret, mul( m-k, f(fc[src], i,  false, true), f(sib[src], rem-i, par_flag, isGreater) ));
                }
            }

        }

    }
    else
    {
        ///ok
        if(sib[src]==-1) ret= add(ret, mul( k-1, f(fc[src],rem, false, false), 1 )) ;
        else if(fc[src]==-1)  ret= add(ret, mul( k-1, 1, f(sib[src], rem, par_flag, isGreater)) );
        else if(sib[src]==-1 && fc[src]==-1)return 1;
        else
        {
            for(ll i=0; i<=rem; i++) /// since parent is secured, i cant secure any child  and their value will be less than k
            {
                ret= add(ret, mul( k-1, f(fc[src],i, false, false), f(sib[src], rem-i, par_flag, isGreater)) );

            }
        }

    }

    return dp[src][rem][par_flag][isGreater]=ret;

}




int main()
{

    ll u,v;
    memset(dp, -1,sizeof dp);
    memset(sib, -1,sizeof sib);
    memset(fc, -1,sizeof fc);


    scanf("%lld %lld",&n,&m);


    for(ll i=1; i<n; i++)
    {
        scanf("%lld %lld",&u,&v);
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    scanf("%lld %lld",&k,&x);


    dfs(1,-1);


    for(ll i=1; i<=n; i++)
    {
        seq.clear();
        for(ll j=0; j<edge[i].size(); j++)
        {
            if(edge[i][j]!=par[i])
                seq.push_back(edge[i][j]);
        }

        if(seq.size())  fc[i]=seq[0];

        for(ll j=0; j+1<(ll)seq.size(); j++)
        {
            sib[seq[j]]=seq[j+1];
        }

    }



    ll res=(ll)f(4,1,0,0);

    if(res!=0 && k==1)
        printf("1\n");
    else printf("%lld\n",res);







    return 0;
}
