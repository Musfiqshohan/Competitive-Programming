///https://vjudge.net/contest/212042#problem/D  pass- tfc22
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

bitset<16>ara[16];
int n;

int find_val(bitset<16>bset)
{
    bitset<16>temp[16],t;
    for(int i=0; i<16; i++)
        temp[i]=ara[i];

    int tot=0;
    t= temp[0]^bset;
    tot+=t.count();

    temp[0]=bset;

    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n; j++)
        {
            int x=0;
            if(j-1>=0)
                x=temp[i][j-1];

            if(j+1<n)
                x^=temp[i][j+1];

            if(i-1>=0)
                x^=temp[i-1][j];

            if(x!=temp[i+1][j])
            {
                if(temp[i+1][j]==0)
                    tot++, temp[i+1][j]=x;
                else return 100000;
            }
        }
    }
    return tot;
}


int f(int pos, bitset<16>bset)
{
    if(pos==n)
        return find_val(bset);


    bitset<16>bs1,bs2;
    bs1=bset;
    bs1[pos]=1;

    int t1=f(pos+1, bs1);
    int t2=f(pos+1,bset);
    return min(t1,t2);
}

int main()
{
    int tt=0,test;
    scanf("%d",&test);

    while(tt<test)
    {
        scanf("%d",&n);
        int x;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                scanf("%d",&x);
                ara[i][j]=x;
            }
        }

        bitset<16>bset;
        bset=ara[0];

        int res=f(0,bset);
        if(res==100000)res=-1;
        printf("Case %d: %d\n",++tt,res);

    }


    return 0;
}
