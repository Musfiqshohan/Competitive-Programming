#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<int,int>
#define inf 100000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int b_size;
int ara[300009];

void make_bucket(int n)
{
    b_size=sqrt(n);

    rep(i,n)
    {


    }
}
int main()
{
    int n,m,u;
    scanf("%d %d %d",&n,&m,&u);

    for(int i=0;i<n;i++)
        scanf("%d",&ara[i]);


    make_bucket(n);



    return 0;
}
