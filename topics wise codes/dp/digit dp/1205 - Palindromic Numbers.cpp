#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
using namespace std;
vector<int>digs;
int lim;

int DP(int ipos, int jpos, int isSmaller, int isStart)
{
    if(ipos>jpos) return 1;

    int ses= isSmaller? 9: digs[ipos];


    int res=0;

    if(!isStart)
    {
        for(int i=0; i<=ses; i++)
        {

          //  if(i>=digs[ipos] && i>digs[jpos]) break;
            res += DP(ipos+1, jpos-1 , isSmaller| i<digs[ipos] ,0);

        }
    }

    else
    {
        for(int i=1; i<=ses; i++)
        {

            if(i>=digs[ipos] && i>digs[jpos] && isSmaller==0) break;
            res += DP(ipos+1, jpos-1, isSmaller| i<digs[ipos], 0);

        }

        printf("%d %d %d ses=%d\n",ipos,jpos,res,ses);

        res+= DP(ipos+1,lim-1,1,1);

    }

    return res;

}

int f(int n)
{
    digs.clear();

    while(n)
    {
        digs.push_back(n%10);
        n/=10;
    }


    reverse(digs.begin(), digs.end());
    lim=digs.size();

    return DP(0,lim-1,0,1);

}

int main()
{
    ll n,m,res;
    scanf("%lld",&n);
    cout<<f(n)<<endl;


   // scanf("%lld %lld",&n,&m);


//    if(n<m) swap(n,m);
//
//    if(m==0) res=f(n);
//    else
//    res=f(n)-f(m-1);
//
//    printf("%lld\n",res);

    return 0;
}

/*
999- 109
998- 99
*/
