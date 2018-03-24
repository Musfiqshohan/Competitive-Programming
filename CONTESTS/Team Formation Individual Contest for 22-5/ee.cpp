#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define i64 long long
#define pii pair<i64,i64>
#define inf 100000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
#define rep(i,n) for(i64 i=0;i<n;i++)
using namespace std;


int main()
{
    int n;

    char ch;
    int cur;
    scanf("%d",&n);

    int pos=0,neg=0,prev=0, pflag=0, nflag=0;
    for(int i=0; i<n; i++)
    {
        cin>>ch>>cur;

        if(cur>prev)
        {

        }

        if(ch=='P' && pflag==0)
        {
            pos++;

            pflag=1;

            if(nflag==1)
                nflag=0, neg--;
        }

        if(ch=='M' && nflag==0)
        {
            neg++;
            nflag=1;
            if(pflag==1)
            pflag=0,pos--;
        }












    }


    return 0;
}
