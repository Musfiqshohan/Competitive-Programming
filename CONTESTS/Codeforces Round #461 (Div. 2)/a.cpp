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
   int x,y;
   cin>>x>>y;

   int tot=y-1;

   int rem=x-tot;
   if(rem>=0 && rem%2==0)
    printf("Yes\n");
   else printf("No\n");

   return 0;
}
