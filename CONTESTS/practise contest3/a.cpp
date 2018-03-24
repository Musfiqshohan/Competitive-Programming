///CodeForces - 808B
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

int ara[200009];
int main()
{

    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>ara[i];

    double sum=0;
    double tot=0;

    for(int i=1;i<=k;i++)
        tot+=ara[i];

    sum+=tot;

    for(int i=k+1; i<=n; i++)
    {
        tot+=ara[i];
        tot-=ara[i-k];
        sum+=tot;
    }

    //cout<<sum<<endl;

    printf("%.10lf\n",sum/(n-k+1));
}
