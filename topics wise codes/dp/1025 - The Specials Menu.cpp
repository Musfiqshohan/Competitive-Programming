#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
using namespace std;

string s;

ll dp[70][70];
ll f(ll start, ll endd)
{

    if(start==endd) return 1;
    if(start+1==endd)
    {
        if(s[start]==s[endd])
            return 3;
        else return 2;
    }

    if(dp[start][endd]!=-1) return dp[start][endd];

    ll res=0,res1=0,res2=0,total=0;
    res=f(start+1, endd-1);

    res1=f(start,endd-1);
    res2=f(start+1,endd);


    total= res1+res2-res;

    //printf("%d %d %d\n",res1,res,res2);

    if(s[start]==s[endd])
    {
        total+=res+1;
    }

    return dp[start][endd]=total;

}


int main()
{
    int t=0,test;
    cin>>test;

    while(t<test){
    ms(dp,-1);
    cin>>s;

    printf("Case %d: %lld\n",++t,f(0,s.length()-1));

    }
}

