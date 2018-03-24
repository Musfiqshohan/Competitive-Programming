#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<ll,ll>
#define inf 100000000000
using namespace std;

char ara[505][505];
ll dp[505][505];
ll f(int row , int col)
{

    if(row<=1 && col<=1) return 0;
    if(row<1 || col<1) return 0;

    if(dp[row][col]!=-1) return dp[row][col];

    ll t1,t2,t3;
    t1= f(row-1,col);
    t2= f(row,col-1);

    t3= f(row-1, col-1);

    ll res=t1+t2-t3;

    if(ara[row][col]=='.' && ara[row][col-1]=='.') res++;
    if(ara[row][col]=='.' && ara[row-1][col]=='.') res++;

    return dp[row][col]=res;
}


int main()
{
    ms(dp,-1);

    int h,w,m;
    scanf("%d %d",&h,&w);

    getchar();

    for(int i=1;i<=h;i++)
    {
        for(int j=1;j<=w;j++)
            scanf("%c",&ara[i][j]);
        getchar();
    }

    //cout<<f(h,w)<<endl;

    scanf("%d",&m);

    int r1,r2,c1,c2;
    ll res=0;
    for(int i=0;i<m;i++)
    {
        scanf("%d %d %d %d",&r1,&c1, &r2,&c2);


        res= f(r2,c2)- f(r1-1,c2) - f(r2, c1-1) + f(r1-1,c1-1);


//        printf("%d - %d - %d + %d= %d\n",f(r2,c2), f(r1-1,c2), f(r2, c1-1) , f(r1-1,c1-1),res);
//        cout<<res<<endl;
        for(int i=c1;i<=c2;i++)
            if(ara[r1][i]=='.' && ara[r1-1][i]=='.') res--;

        for(int i=r1; i<=r2;i++)
            if(ara[i][c1]=='.' && ara[i][c1-1]=='.') res--;

        cout<<res<<endl;

    }


    return 0;
}
