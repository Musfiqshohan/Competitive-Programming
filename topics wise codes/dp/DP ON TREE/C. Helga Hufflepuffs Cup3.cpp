#include<bits/stdc++.h>
using namespace std;
#define D(x)    cout << #x " = " <<(x) << endl
#define MAX     100000
#define MOD     1000000007
typedef long long int LL;

vector<int> edge[MAX+5];
int par[MAX+5], fc[MAX+5], sib[MAX+5];

void dfs(int idx, int p = -1){
    par[idx] = p;
    for(auto x : edge[idx])
        if(x != p)
            dfs(x, idx);
}

int m, SPCL;
vector<int> seq;

inline LL add(LL u, LL v){
    LL ret = (u + v);
    if(ret >= MOD) return ret % MOD;
    return ret;
}

inline LL mul(LL u, LL v){
    LL ret = (u * v);
    if(ret >= MOD) return ret % MOD;
    return ret;
}

int dp[MAX+5][12][2][2];

LL F(int idx, int rm, bool pflag, bool hadExactK = false)
{
    if(idx == -1) return (rm == 0);
    if(dp[idx][rm][pflag][hadExactK] != -1) return dp[idx][rm][pflag][hadExactK];

    int onleft;
    if(pflag && hadExactK){
        LL ret = 0, current;
        for(onleft = 0; onleft <= rm; onleft++){
            current = F(fc[idx], onleft, false);
            current = mul(current, F(sib[idx], rm - onleft, true, hadExactK));
            ret = add(ret, mul(current, SPCL - 1));
        }
        return dp[idx][rm][pflag][hadExactK] = ret;
    }
    else{
        LL ret = 0, current;

        ///IF I MAKE IT SPECIAL
        if(pflag == false){
            for(onleft = 0; onleft <= rm - 1; onleft++){
                current = F(fc[idx], onleft, true, true);
                current = mul(current, F(sib[idx], rm - 1 - onleft, false));
                ret = add(ret, current);
            }
        }

        ///IF I DON'T MAKE IT SPECIAL AND INSERT VALUE > K
        if(SPCL != m)
        {
            for(onleft = 0; onleft <= rm; onleft++){
                current = F(fc[idx], onleft, true);
                current = mul(current, F(sib[idx], rm - onleft, pflag));
                ret = add(ret, mul(current, m - (SPCL + 1) +1));
            }
        }

        ///IF I DON'T MAKE IT SPECIAL AND INSERT VALUE < K
        if(SPCL != 1){
            for(onleft = 0; onleft <= rm; onleft++){
                current = F(fc[idx], onleft, false);
                current = mul(current, F(sib[idx], rm - onleft, pflag));
                ret = add(ret, mul(current, SPCL - 1));
            }
        }

        return dp[idx][rm][pflag][hadExactK] = ret;
    }
}

int main()
{
//    freopen("rm.txt", "r", stdin);

    memset(fc, -1, sizeof(fc));
    memset(sib, -1, sizeof(sib));
    memset(dp, -1, sizeof(dp));

    int n, k, x, u, v, i, j;
    LL res = 0;

    scanf("%d %d", &n, &m);
    for(i = 1; i < n; i++){
        scanf("%d %d", &u, &v);
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    dfs(1);
    for(i = 1; i <= n; i++){
        seq.clear();
        for(auto x : edge[i])
            if(x != par[i])
                seq.push_back(x);

        if(seq.size()) fc[i] = seq[0];
        for(j = 0; j + 1 <(int) seq.size(); j++)
            sib[seq[j]] = seq[j+1];
    }

    scanf("%d %d", &k, &x);
    SPCL = k;

    for(int ex = 0; ex <= x; ex++)
        res = (res + F(1, ex, false)) % MOD;

    cout << res << endl;
    return 0;
}
