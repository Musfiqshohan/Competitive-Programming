///https://odzkskevi.qnssl.com/00567bdd044aefe721cc49955e34995c?v=1505934507
#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;
vector<int>edge[205];
vector<int>seq;
int par[205],sib[205], fc[205];
ll dp[205][205][2][2];

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
ll mul(ll u, ll v)
{
    if(u>=MOD) u%=MOD;
    if(v>=MOD) v%=MOD;

    return (u*v)%MOD;
}



ll f(int idx, int k, bool par_flag, bool dan_flag)
{
    // printf("%d %d %d %d\n",idx, k, par_flag, dan_flag);

//    if(fc[idx]==-1)
//    {
//        if(par_flag==true && k==1)
//            return 1;
//        else return 0;
//    }
//
//
//    if(idx==-1)
//    {
//        if(dan_flag==false && k==0)
//            return 1;
//        else return 0;
//
//    }

    if(idx==-1) return (k==0 && dan_flag==false);
    if(dp[idx][k][par_flag][dan_flag]!=-1) return dp[idx][k][par_flag][dan_flag];

    ll ret=0;

    for(int x=0; x<=k; x++) ///will not color
    {
        ret= add(ret, mul( f(fc[idx], x, false, false), f(sib[idx], k-x, par_flag, dan_flag) ));
    }



    for(int x=0; x<k; x++) /// will color
    {
        bool newdanflag=(par_flag==false);
        ret= add(ret, mul( f(fc[idx], x, true, newdanflag), f(sib[idx], k-1-x, par_flag, false)  ));
    }



    return dp[idx][k][par_flag][dan_flag]=ret;


}




int main()
{

    int n,k,u,v;
    while(scanf("%d %d",&n,&k)==2)
    {

        memset(dp, -1,sizeof dp);
        memset(sib, -1,sizeof sib);
        memset(fc, -1,sizeof fc);



        for(int i=1; i<n; i++)
        {
            scanf("%d %d",&u,&v);
            edge[u].push_back(v);
            edge[v].push_back(u);
        }

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

            for(int j=0; j+1<(int)seq.size(); j++)
            {
                sib[seq[j]]=seq[j+1];

            }

        }

        //cout<<f(1,k,0,0)<<endl;
        printf("%d\n",(int)f(1,k,0,0));

        for(int i=1; i<=n; i++)
            edge[i].clear();



    }

    return 0;
}
