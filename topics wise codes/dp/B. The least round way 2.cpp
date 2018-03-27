#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n,ara[1009][1009],vis[1009][1009];

struct info
{
    ll fives,twos;
} dp[1009][1009];

ll find_min(info a, info b)
{
    ll zero1= min(a.fives,a.twos);
    ll zero2= min(b.fives, b.twos);

    if(zero1<zero2) return 1;
    else return 2;

}

info prepare(ll num)
{

    ll fiv,two;
    fiv=0,two=0;

    info temp;
    temp.fives=temp.twos=0;

//   if(num==0) return {-1,-1};

    if(num%2==0)
    {
        while(num%2==0)
        {
            num/=2;
            temp.twos++;
        }
    }

    if(num%5==0)
    {
        while(num%5==0)
        {
            num/=5;
            temp.fives++;
        }
    }

    return temp;

}

info f(ll r, ll c)
{
    if(r==n-1 && c==n-1)
    {
        info temp= prepare(ara[r][c]);
        return temp;

    }

    if(r>=n || c>=n) return {1000000000,1000000000};


    if(vis[r][c]==1) return dp[r][c];
    vis[r][c]=1;

    info t1,t2;

    t1= f(r+1,c);
    t2= f(r,c+1);

    // if(t1.fives==-1 || t2.fives==-1) return dp[r][c]= {-1,-1};

    info ret;
    ret.fives=ret.twos=0;

    if(find_min(t1,t2)==1)
        ret=t1;
    else ret=t2;


    info tt= prepare(ara[r][c]);

    //  if(tt.fives==-1) return dp[r][c]= {-1,-1};

    ret.fives+=tt.fives;
    ret.twos+=tt.twos;

    return dp[r][c]=ret;


}



void prll_path(ll r, ll c)
{



    if(r==n-1 && c==n-1) return;

    info t1= f(r+1,c);
    info t2= f(r,c+1);

    if(find_min(t1,t2)==1)
    {
        printf("D");
        prll_path(r+1,c);
    }

    else
    {
        printf("R");
        prll_path(r,c+1);

    }
}


int main()
{

    scanf("%lld",&n);

    for(ll i=0; i<n; i++)
    {
        for(ll j=0; j<n; j++)
            scanf("%lld",&ara[i][j]);
    }


    info res=f(0,0);

    ll result;
    // if(res.fives==-1) result=1;
    // else
    result=min(res.fives,res.twos);


    printf("%lld\n",result);

    prll_path(0,0);
    puts("");



    return 0;
}
