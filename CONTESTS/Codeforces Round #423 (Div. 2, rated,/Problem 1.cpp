#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<ll,ll>
#define inf 100000000000
using namespace std;


int main()
{
    int n,a,b,x,total=0;
    int cx=0;
    cin>>n>>a>>b;


    for(int i=0; i<n; i++)
    {
        scanf("%d",&x);
        if(x==1)
        {
            if(a-1>=0)  a--;
            else if(b-1>=0)
            {
                b--;
                cx++;
            }
            else if(cx-1>=0) { cx--;  }
            else total++;

        }
        else
        {
            if(b-1>=0) b--;
            else total+=2;
        }

    }

    cout<<total<<endl;
    return 0;
}
