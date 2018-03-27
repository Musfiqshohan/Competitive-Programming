///http://codeforces.com/contest/855/problem/C
#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;
vector<int>edge[100009];
vector<int>seq;
int par[100009],sib[100009], fc[100009];
ll dp[100009][12][2][2];

int n,k,x,m;
void dfs(int src, int pr)
{
    par[src]=pr;
    for(int i=0; i<edge[src].size(); i++)
    {
        int node= edge[src][i];
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
ll f(int src, int rem, bool par_flag, bool isGreater)
{

    if(src==-1)
    {
        if(rem==0)return 1;
        return 0;

    }


    if(dp[src][rem][par_flag][isGreater]!=-1) return dp[src][rem][par_flag][isGreater];

    /// color

    ll ret=0;

    if(par_flag==false && isGreater==false)
    {
        for(int i=0; i<rem; i++)
        {
            ll temp= mul(1, f(fc[src],i, true, true), f(sib[src],rem-i-1, par_flag, isGreater));
            ret= add(ret,temp);

        }




    }


    if(par_flag==true)      ///not color since parent colored
    {
        for(int i=0; i<=rem; i++)
        {
            ll temp= mul(k-1, f(fc[src],i, false, false), f(sib[src],rem-i, par_flag, isGreater));
            ret= add(ret,temp);

        }

    }
    else
    {
        ///dont color and less than k

        for(int i=0; i<=rem; i++)
        {
            ll temp= mul( k-1, f(fc[src], i, false, false), f(sib[src], rem-i, par_flag, isGreater) );
            ret= add(ret, temp);
        }


        for(int i=0; i<=rem; i++)
        {
            ll temp= mul( m-k, f( fc[src], i, false, true), f(sib[src], rem-i, par_flag,isGreater));
            ret= add(ret, temp);
        }

    }


    /// dont color and greater than k


    //return ret;
     return dp[src][rem][par_flag][isGreater]=ret;

}




int main()
{

    int u,v;
    memset(dp, -1,sizeof dp);
    memset(sib, -1,sizeof sib);
    memset(fc, -1,sizeof fc);


    scanf("%d %d",&n,&m);


    for(int i=1; i<n; i++)
    {
        scanf("%d %d",&u,&v);
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    scanf("%d %d",&k,&x);


    dfs(1,-1);


    for(int i=1; i<=n; i++)
    {
        seq.clear();
        for(int j=0; j<edge[i].size(); j++)
        {
            if(edge[i][j]!=par[i])
                seq.push_back(edge[i][j]);
        }

        if(seq.size())  fc[i]=seq[0];

        for(int j=0; j+1<(ll)seq.size(); j++)
        {
            sib[seq[j]]=seq[j+1];
        }

    }


  //  cout<<f(1,0,0,0)<<endl;

    ll res=0;
    for(int i=0; i<=x; i++)
    {

        ll temp=(int)f(1,i,0,0);

        res= (res+temp)%MOD;
    }


//    if(res!=0 && k==1)
//        printf("1\n");
//    else
    printf("%d\n",(int)res);







    return 0;
}
