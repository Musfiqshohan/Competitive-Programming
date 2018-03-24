#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define inf 1000000000000000
#define pii pair<ll,ll>
#define mod 1000000007
using namespace std;

int f(int a,int b, int i, int j)
{
     return (a*i+b*j) ^ (a*j+b*i);
}

int main()
{
     freopen("crypto.in","r",stdin);
    freopen("crypto.out","w",stdout);
     int n,a,b;
    cin>>n>>a>>b;

    int mx=-1, mxx=0,mxy=0;
    for(int x=n;x>=max(1,n-100);x--)
    {
        for(int y=1;y<=n;y++)
        {
            if(x&y==y)
            {
                int res=f(a,b,x,y);
                if(res>mx)
                {
                    mx=res;
                    mxx=x;
                    mxy=y;
                }
            }
        }
    }

    cout<<mxx<<" "<<mxy<<endl;
}
