#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
using namespace std;

vector<int>digs;
int lim;
int  n,s;
int DP(int pos, int isSmall, int isStart, int sum)
{
    if(pos==lim)
    {
        printf("sum=%d %d\n",sum, n-sum);
        if(n-sum>=s)
            return 1;
        return 0;
    }

    int ses= isSmall? 9:digs[pos];
    int ret=0;

    if(!isStart)
    {
        for(int i=0; i<=ses; i++)
        {
            ret+= DP(pos+1, isSmall| i<digs[pos],0, sum+i );
        }

    }
    else
    {
        for(int i=1; i<=ses; i++)
        {
            ret+= DP(pos+1, isSmall| i<digs[pos], 0, sum+i);
        }

        ret+=DP(pos+1, 1, 1, 0);

    }

    return ret;

}

int f(int n, int s)
{
    digs.clear();

    while(n)
    {
        digs.push_back(n%10);
        n/=10;
    }


    reverse(digs.begin(), digs.end());
    lim=digs.size();

    cout<< DP(0,0,1,0)<<endl;

}

int main()
{


    scanf("%d %d",&n,&s);
    f(n,s);

}
