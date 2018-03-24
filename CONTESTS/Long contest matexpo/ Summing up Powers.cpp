///never user specifier of unknown type like unsigned int, use cout
#include<bits/stdc++.h>
#define pii pair<int,int>
#define inf 10000000000
#define ui unsigned int
#define i64 long long
using namespace std;

const int MX=59;

ui dp[MX][MX],ara[MX][MX],kpower[MX][MX];
int vis[MX][MX];
struct matrix
{
    int row,col;
    ui v[MX][MX];
} I;

matrix muit(matrix a, matrix b)
{
    matrix r;
    r.row=a.row, r.col=b.col;
    assert(a.col==b.row);

    for(int i=0; i<r.row; i++)
    {
        for(int j=0; j<r.col; j++)
        {
            ui sum=0;
            for(int k=0; k<a.col; k++)
            {
                sum+=a.v[i][k]*b.v[k][j];
               // sum%=mod;
            }
            r.v[i][j]=sum;
        }
    }
    return r;

}

ui nCr(int n, int r)
{
    if(r==1) return n;
    if(r==0 || n==r) return 1;

    if(vis[n][r]==1) return dp[n][r];
    vis[n][r]=1;

    return dp[n][r]=nCr(n-1,r)+nCr(n-1,r-1);
}


matrix prepare(matrix mat,int k)
{
    mat.v[0][0]=1;
    for(int i=1; i<mat.col; i++)
        mat.v[0][i]=nCr(k,i-1);

    for(int i=1; i<mat.row; i++)
    {

        assert(k>=0);
        for( int j=i; j<mat.col; j++)
        {
            mat.v[i][j]=nCr(k, j-i);
        }
        k--;
    }

   // printf("k=%d\n",k);
    assert(k==-1);
    return mat;
}

matrix power(matrix base, i64 p)
{

    matrix res=I;

    while(p!=0)
    {
        if(p&1)
            res=muit(res,base);

        base=muit(base,base);
        p=p>>1;
    }
    return res;
}

ui pow1(ui base,i64 p)
{
    if(base==0) return 0;
    ui res=1;
    while(p!=0)
    {
        if(p&1)
            res=(res*base);
        base=base*base;
        p=p>>1;
    }
    return res;
}




int main()
{

    for(int i=0; i<=55; i++)
        I.v[i][i]=1;

    for(int k=0; k<=55; k++)
    {
        ui sum=0;

        for(int i=0; i<=55; i++)
        {
            ui res= pow1(i,k);
            kpower[i][k]=res;
            sum+=res;
            ara[k][i]=sum;

        }
    }

    int tt=0,test;
    scanf("%d",&test);

    while(tt<test)
    {
        i64 n;
        int k;

        scanf("%lld %d",&n,&k);

        matrix matt;
        matt.row=matt.col=k+2;
        matt=prepare(matt,k);


        ui res=0;

        if(n<=k+1)
        {
            res=ara[k][n];
        }
        else
        {
            I.row=I.col=k+2;

            matt=power(matt,n-k-1);  ///* i have issue here

            res=ara[k][k+1];
            for(int i=1; i<matt.col; i++)
            {
                res+= matt.v[0][i]* kpower[k+1][k-i+1];   ///also here
                assert(k-i+1>=0);
            }

        }

       // printf("Case %d: %u\n",++tt,res);
        cout<<"Case "<<++tt<<": "<<res<<endl;


    }

}

