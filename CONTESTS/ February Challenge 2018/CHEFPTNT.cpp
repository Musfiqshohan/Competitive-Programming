///https://www.codechef.com/FEB18/problems/CHEFPTNT
#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define i64 long long
#define pii pair<int,int>
#define inf 10000000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;



int main()
{
    int tt;
    cin>>tt;

    while(tt--)
    {

        int N,m,x,k;
        cin>>N>>m>>x>>k;

        string s;
        cin>>s;

        int even=0,odd=0;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]=='E')
                even++;
            else odd++;
        }

       // cout<<even<<" "<<odd<<endl;


        for(int i=1; i<=m; i++)
        {
            int mn;
            if(i%2==1)
            {
                mn=min(x,odd);
                odd-=mn;
            }
            else
            {
                mn=min(x,even);
                even-=mn;
            }

          //  cout<<mn<<endl;
            N-=mn;
            if(N<=0)
                break;
        }

        if(N>0) printf("no\n");
        else printf("yes\n");

    }


    return 0;
}
