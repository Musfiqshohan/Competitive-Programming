#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<int,int>
#define inf 100000000000
using namespace std;
int n,k;
int ara[5009], dp[5009][5009][2];
int f(int  pos, int k, int isStart)
{
    if(pos==n) return 0;

    int t1=0,t2=0,t3=0;

    if(dp[pos][k][isStart]!=-1 ) return dp[pos][k][isStart];

    if(isStart==0)      //nei nai ekhono
    {
        //nibo
        if(ara[pos]<0)
        {
            if(k>0)
                t1= f(pos+1,k-1,1);

            t2= ara[pos] + f(pos+1, k, 1);
        }
        else
            t1= ara[pos]+ f(pos+1,k,1);

        t3= f(pos+1,k,0);

    }


    else if(isStart==1)
    {

        if(ara[pos]<0)
        {
            if(k>0)
                t1= f(pos+1,k-1,1);

            t2= ara[pos]+ f(pos+1,k,1);
        }
        else
            t1= ara[pos]+ f(pos+1,k,1);
        t3=0;

    }

    return dp[pos][k][isStart]=max(t1, max(t2,t3));




}


int main()
{
    int t=0,test;
    scanf("%d",&test);

    while(t<test) {
    ms(dp,-1);
    scanf("%d %d",&n,&k);

    for(int i=0; i<n; i++) scanf("%d",&ara[i]);

    printf("Case %d: %d\n",++t, f(0,k,0));

    }

    return 0;
}
