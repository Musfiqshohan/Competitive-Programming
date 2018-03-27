#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<int,int>
#define inf 100000000000000009
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
using namespace std;
string s1,s2;
int l1,l2;

ll dp1[32][32], dp2[32][32][62];

ll f1(int i, int j)
{

    if(i==l1 && j==l2) return 0;
    if(i==l1) return l2-j;
    if(j==l2) return l1-i;

    if(dp1[i][j]!=-1) return dp1[i][j];


    ll ret1=inf,ret2=inf,ret3=inf;

    if(s1[i]==s2[j])
    {

        ret3=1+ f1(i+1,j+1);
    }
    else
    {

        ret1=1+f1(i+1,j);
        ret2=1+f1(i,j+1);
    }


    return dp1[i][j]=min( ret3, min(ret1,ret2));



}

ll f2(int i, int j, int len)
{


    if(len ==0 )
    {
        if(i==l1 && j==l2)
            return 1;
        return 0;
    }

    if(len<0) return 0;

    if(dp2[i][j][len]!=-1) return dp2[i][j][len];

    ll ret1=0,ret2=0,ret3=0;

    if(s1[i]==s2[j] && i<l1 && j<l2)
    {
        ret1= f2(i+1,j+1,len-1);
    }
    else{
    if(i<l1)
    ret2= f2(i+1,j,len-1);

    if(j<l2)
    ret3= f2(i,j+1,len-1);
    }

    return dp2[i][j][len]=ret1+ret2+ret3;

}

int main()
{
    int t=0,test;
    cin>>test;
    getchar();

    while(t<test)
    {
        ms(dp1,-1);
        ms(dp2,-1);

    cin>>s1>>s2;



    l1=s1.length();
    l2=s2.length();

    ll minL= f1(0,0);


    ll res= f2(0,0,minL);
   // cout<<minL<<" "<<res<<endl;

    printf("Case %d: %lld %lld\n",++t, minL, res);


    }
}
