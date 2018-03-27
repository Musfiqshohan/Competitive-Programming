#include<bits/stdc++.h>
//#include <windows.h>
using namespace std;

#define FRE(i,a,b)  for(i = a; i <= b; i++)
#define FRL(i,a,b)  for(i = a; i < b; i++)
#define mem(t, v)   memset ((t) , v, sizeof(t))
#define sqr(x)      ((x)*(x))
#define all(x)      x.begin(),x.end()
#define un(x)       x.erase(unique(all(x)), x.end())
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define sfff(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define D(x)        cout<<#x " = "<<(x)<<endl
#define pf          printf
#define VI          vector <int>
#define pii         pair <int, int>
#define pll         pair <LL, LL>
#define pb          push_back
#define mp          make_pair
#define pi          acos(-1.00)
#define DBG         pf("Hi\n")
#define sz          size()
#define ins         insert
#define fi          first
#define se          second
#define xx          first
#define yy          second
#define inf         (1<<29)
#define hp          (LL) 999983
#define MOD         1000000007
#define eps         1e-9
#define MAX         200000

typedef long long int LL;
typedef double db;

LL hash1[MAX+11];
LL hash2[MAX+11], inv[MAX+11];

char in1[MAX+11], in2[MAX+11];
int len;

LL ip(LL a, LL p)
{
    if(!p) return 1;
    if(p&1) return (a*ip(a,p-1))%MOD;

    LL ret = ip(a,p/2);
    return (ret*ret)%MOD;
}

LL hit(int idx, int i, int j)
{
    LL ret;
    if(idx == 1) ret = (hash1[j] - hash1[i-1]);
    else ret = (hash2[j] - hash2[i-1]);

    if(ret >= MOD) ret %= MOD;
    if(ret < 0) ret += MOD;
    ret = (ret * inv[i-1]);
    if(ret >= MOD) ret %= MOD;

    return ret;
}

bool eq(int l, int r, int p, int q)
{
    if(hit(1,l,r) == hit(2,p,q)) return true;
    if((r-l+1) & 1) return false;
    if(l == r) return false;

    int m1 = (l+r)/2, m2 = (p+q)/2, c = rand();

    if(c&1)
    {
        if(eq(l,m1,p,m2)) return eq(m1+1,r,m2+1,q); /// this is false  so return false
        if(eq(l,m1,m2+1,q)) return eq(m1+1,r,p,m2); /// but this is true so, should return true
    }
    else
    {
        if(eq(l,m1,m2+1,q)) return eq(m1+1,r,p,m2);
        if(eq(l,m1,p,m2)) return eq(m1+1,r,m2+1,q);
    }

    return false;
}

int main()
{
    //freopen("c:\\Users\\User\\Desktop\\in.txt", "r", stdin);
    //freopen("c:\\Users\\User\\Desktop\\out.txt", "w", stdout);
    //ios_base::sync_with_stdio(0); cin.tie(0);

    int i, j, k;
    LL cur;

    scanf("%s %s", in1, in2);
    len =strlen(in1);

    for(i = 0; i <= len; i++)
        inv[i] = ip(ip(hp,i), MOD-2);


    for(cur = i = 1; i <= len; i++)
    {
        hash1[i] = (hash1[i-1] + (in1[i-1]-'0') * cur)%MOD;
        hash2[i] = (hash2[i-1] + (in2[i-1]-'0') * cur)%MOD;
        cur = (cur*hp) % MOD;
    }


    if(eq(1,len,1,len)) puts("YES");
    else puts("NO");

    return 0;
}
