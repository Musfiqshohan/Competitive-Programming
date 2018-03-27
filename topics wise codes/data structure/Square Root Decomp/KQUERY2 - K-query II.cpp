#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
#define loop(i,n) for(int i=0;i<n;i++)
#define ll long long
#define pii pair<int,int>
#define inf 100000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
using namespace std;


int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&ara[i]);

    scanf("%d",&m);

    make_bucket();

    for(int i=0;i<q;i++)
    {
        scanf("%d",&case);
        if(case==0)
        {
            scanf("%d %d",&x,&val);
            update(x,val);
        }
        else
        {
            scanf("%d %d %d")
        }
    }




    return 0;
}
