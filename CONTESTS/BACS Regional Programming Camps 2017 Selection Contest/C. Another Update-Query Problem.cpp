#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<ll,ll>
#define inf 100000000000
#define  mod 1000000007
using namespace std;

int ara[4009];
int f(int l, int r,int d)
{
    int cnt=0,t;

    for(int i=l ;i<=r;i++)
    {
        t+= ((1+ (cnt%mod*d%mod)%mod)* ara[i]%mod) %mod;
        cnt++;
    }
    return t;
}


int main()
{

    int n,q,x,y,d;

    scanf("%d",&n);
    cin>>n;

    for(int i=1;i<=n;i++)
        scanf("%d",&ara[i]);

    for(int i=1;i<=q;i++)
    {
        scanf("%d %d %d",&x,&y,&d);

        printf("%d\n", f(x,y,d));
    }

   // return 0;
}
