#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
using namespace std;

vector<int>bits1;  /// for left
vector<int>bits2;   /// for right

int lim;
ll dp[70][2][2][2][2];

ll pow1(int x, int n)
{
    if(n==0) return 1;

    if(n%2==0)
    {
        ll ret= pow1(x,n/2);

        return ret*ret;
    }


    return x* pow1(x,n-1);

}

ll DP(int pos,  int isGreater1, int isSmaller1,   int isGreater2, int isSmaller2)
{
    if(pos==lim)
        return 0;


    if(dp[pos][isGreater1][isSmaller1][isGreater2][isSmaller2]!=-1) return dp[pos][isGreater1][isSmaller1][isGreater2][isSmaller2];

    vector<int>a;
    vector<int>b;


    if(isGreater1) a.push_back(0);
    else a.push_back(bits1[pos]);

    if(isSmaller1) a.push_back(1);
    else a.push_back(bits2[pos]);


    if(isGreater2)  b.push_back(0);
    else b.push_back(bits1[pos]);

    if(isSmaller2)  b.push_back(1);
    else  b.push_back(bits2[pos]);


    ll mx=0;

    for(int i=0; i<a.size(); i++)
    {
        for(int j=0; j<b.size(); j++)
        {
            ll ret=0;
            if(a[i]!=b[j])
            {
                ret= pow1(2,lim-pos-1);
              //  printf("lim =%d pos %d  ,%d %d  ret=%d\n",lim,pos,  a[i], b[j],ret);

            }



            ret+=DP(pos+1, isGreater1|(a[i]>bits1[pos]), isSmaller1| a[i]<bits2[pos], isGreater2| b[j]>bits1[pos], isSmaller2| b[j]<bits2[pos]  );
            mx= max(mx,ret);
        }
    }

    return dp[pos][isGreater1][isSmaller1][isGreater2][isSmaller2]= mx;






}


ll f(ll l, ll r)
{
    while(l || r)
    {
        bits1.push_back(l%2);
        l/=2;
        bits2.push_back(r%2);
        r/=2;
    }

    reverse(bits1.begin(), bits1.end());
    reverse(bits2.begin(), bits2.end());



    lim= max( bits1.size(), bits2.size() );

    cout<<DP(0, 0, 0, 0, 0)<<endl;

}

int main()
{
    memset(dp,-1,sizeof dp);
    ll l,r;
    scanf("%lld %lld",&l,&r);

    f(l,r);
}

