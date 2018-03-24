///https://vjudge.net/contest/212042#problem/J  pass-tfc22
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
#define mod 1000000007
using namespace std;

int ara[201009];

int main()
{

    int n,s,x;
    cin>>n>>s;
    int mx=0,flag=0;
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&x);
        if(i==s)
        {
            if(x!=0)
            {
               // mx=max(mx,x);
                flag=1;
                continue;
            }
        }

        ara[x]++;
        mx=max(mx,x);
    }


    int t1=0;

    if(flag==0)   ///root at right place
        t1=ara[0]-1;
    else t1=ara[0];

    int tot=0;
    for(int i=1; i<=mx; i++)
    {
        if(ara[i]==0 && t1>0)
        {
            tot++;
            ara[i]=1;
            t1--;
            if(t1==0) break;
        }
    }

    tot=tot+t1+flag;
    ara[0]=1;


    ///all ok till now

    for(int i=0; i<=mx; i++)
    {
        if(ara[i]==0)
        {
            tot++;

            ara[i]=1;
            ara[mx]--;

            while(ara[mx]==0)
                mx--;
        }
    }

    cout<<tot<<endl;


    return 0;
}
