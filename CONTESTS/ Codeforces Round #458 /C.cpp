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
int k;
const i64 mod=1000000007;

vector<int>vec;
int check(int tot)
{
    if(tot==0) return 0;
    int step=0;
    while(tot!=1)
    {
        tot=__builtin_popcount (tot);
        step++;
        //  printf("%d\n",tot);
    }

    return step+1;

}

i64 dp[1010][1010][2];
i64 f(int pos, int tot, int isSmaller)
{
    if(tot>1009) return 0;

    // printf("%d %d %d\n",pos,tot,isSmaller);


    if(dp[pos][tot][isSmaller]!=-1)
        return dp[pos][tot][isSmaller];

    if(pos==vec.size())
    {
        int ret=check(tot);
        // printf("Inside=%d\n",tot);
        if(ret==k)
            return 1;
        else return 0;
    }

    int ses= isSmaller? 1: vec[pos];


    i64 res=0;
    for(int i=0; i<=ses; i++)
    {
        int one=0;
        if(i==1)
            one=1;

        i64 temp= f(pos+1, tot+one, i<vec[pos]|isSmaller);

        res= (res+temp)%mod;

    }


    return dp[pos][tot][isSmaller]=res;



}



int  main()
{

    // cout<<check(2)<<endl;
    ms(dp,-1);
    string str;
    cin>>str;
    scanf("%d",&k);
    for(int i=0; i<str.size(); i++)
        vec.push_back(str[i]-'0');

    cout<<f(0,0,0)<<endl;

}
