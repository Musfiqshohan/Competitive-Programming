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



int main()
{
    ll n,k;
    cin>>n>>k;

    ll rem=n%k;

      cout<<rem<<endl;

    if(n==1)
    {
        if(k==2)
            printf("Yes\n");
        else printf("No\n");

    }
    else if(rem==k-1)
        printf("Yes\n");
    else printf("No\n");


}
