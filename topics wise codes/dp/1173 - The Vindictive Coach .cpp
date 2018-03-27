#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define llu unsigned long long
#define pii pair<int,int>
#define inf 100000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

llu dp[2][50][50];

llu f(bool isGreater , int smaller, int bigger)
{
  //  printf("%d %d %d\n",isGreater, smaller, bigger);

    if(smaller==0 && bigger==0) return 1;

    if(dp[isGreater][smaller][bigger]!=-1) return dp[isGreater][smaller][bigger];

    llu  t1=0, t2=0;
    if(isGreater==true)
    {
        for(int i=1;i<=bigger; i++)
        {
            t1+= f(false, smaller+i-1 , bigger-i);
        }
    }
    else
    {
        for(int i=1;i<=smaller; i++)
        {
            t2+= f(true, i-1, bigger+smaller-i);
        }
    }

    return dp[isGreater][smaller][bigger]=t1+t2;
}


int main()
{

    memset(dp,-1,sizeof dp);
    int t=0,test;
    cin>>test;

    while(t<test)
    {
        int n,m;
        scanf("%d %d",&n,&m);

        llu res=0;

        if(n==1 || n==2)
            res=1;
        else if(m==1)
            res= f(false, 1, n-3);
        else
            res= f(false, m-1, n-m);

        printf("Case %d: %llu\n",++t, res);

    }

}
