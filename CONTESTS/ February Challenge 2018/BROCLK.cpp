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
    double l,d,t;

    while(1)
    {

        cin>>l>>d;

        for(int i=0; i<=3; i++)
        {
            printf("at time=%d ->",i);
            double res=l* cos( acos(d/l)*i);
            //printf("%lf\n",res);
            cout<<fixed<<setprecision(10)<<res<<endl;
        }


    }


}



