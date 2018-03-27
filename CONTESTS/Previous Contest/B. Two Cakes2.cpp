#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define i64 long long
#define pii pair<int,int>
#define INF 1000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
#define rep(i,n) for(i64 i=0;i<n;i++)
using namespace std;


int f(int n, int a)
{
    int res= a/n;

    if(res>0) return res;
    else return -1;
}

int main()
{
    int n,a,b;
    scanf("%d %d %d",&n,&a,&b);

    int mx=0;

    for(int i=1;i<=n-1;i++)
    {
        int t1=f(i,a);
        int t2=f(n-i,b);

       // printf("i=%d %d %d\n",i,t1,t2);

        if(t1>0 && t2>0)
            mx=max(mx, min(t1,t2));
    }

    cout<<mx<<endl;

}
