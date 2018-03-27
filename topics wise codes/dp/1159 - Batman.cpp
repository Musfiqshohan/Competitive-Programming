#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
using namespace std;

string s1,s2,s3;

int dp[55][55][55];

int f(int i, int j, int k)
{
    if(i>=s1.length() || j>=s2.length() || k>=s3.length() ) return 0;

    if(dp[i][j][k]!=-1) return dp[i][j][k];

    int t1,t2,t3,t4,t5,t6,t7;
    t1=t2=t3=t4=t5=t6=t7=0;

    if(s1[i]==s2[j] && s2[j]==s3[k])
    {
        t1= 1+ f(i+1,j+1,k+1);
    }

    t2= f(i+1,  j,      k);
    t1= max(t1,t2);

    t3= f(i,    j+1,    k);
    t1= max(t1,t3);

    t4= f(i,    j,      k+1);
    t1= max(t1,t4);

    t5= f(i+1,  j+1,    k);
    t1= max(t1,t5);

    t6= f(i+1,  j,      k+1);
    t1= max(t1,t6);

    t7= f(i,    j+1,    k+1);
    t1= max(t1,t7);

    return dp[i][j][k]=t1;

}

int main()
{

    int t=0,test;
    cin>>test;

    while(t<test){
    ms(dp,-1);
    cin>>s1>>s2>>s3;

    printf("Case %d: %d\n",++t,f(0,0,0));

    }
}

