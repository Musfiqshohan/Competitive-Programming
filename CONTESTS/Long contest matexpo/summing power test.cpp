#include<bits/stdc++.h>
#define pii pair<i64,i64>
#define inf 100000000000000000
#define mod 1000000007
#define i64 long long
using namespace std;

int dp[55][55],ara[55];
struct matrix
{
    i64 row,col;
    int v[35][35];

    matrix operator * (matrix n)
    {
        matrix r;
        r.row=row, r.col=n.col;
        assert(col==n.row);

        for(i64 i=0; i<r.row; i++)
        {
            for(i64 j=0; j<r.col; j++)
            {
                i64 sum=0;
                for(i64 k=0; k<col; k++)
                {
                    sum+=v[i][k]*n.v[k][j];
                    sum%=mod;
                }
                r.v[i][j]=sum;
            }

        }
        return r;
    }

};

void print_mat(matrix mat)
{
    for(i64 i=0; i<mat.row; i++)
    {
        for(i64 j=0; j<mat.col; j++)
            printf("%d ",mat.v[i][j]);
        puts("");
    }
}


int nCr(int n, int r)
{

    if(r==0 || n==r) return 1;

    if(dp[n][r]!=-1) return dp[n][r];

    return dp[n][r]=nCr(n-1,r)+nCr(n-1,r-1);
}


matrix prepare(matrix mat,int k)
{
    mat.v[0][0]=1;
    for(int i=1; i<mat.col; i++)
        mat.v[0][i]=nCr(k,i-1);

    for(int i=1; i<mat.row; i++)
    {
        int j=i;
        for( ; j<mat.col; j++)
        {
            mat.v[i][j]=nCr(k, j-i);
        }
        k--;
    }
    return mat;
}

matrix power(matrix base, int p)
{
    matrix I;
    I.row=I.col=base.row;

    for(int i=0;i<I.row;i++)
        I.v[i][i]=1;
    matrix res=I;
    while(p)
    {
        if(p&1)
            res=res*base;

        base=base*base;
        p>>=1;
    }
    return res;
}

int pow1(int base ,int p)
{
    int res=1;
    while(p)
    {
        if(p&1)
            res=res*base;
        base=base*base;
        p>>=1;
    }
    return res;
}




int main()
{

    int n,k;
    cin>>n>>k;




    int sum=0;
    for(int i=1;i<=n;i++)
    {
        sum+= pow1(i,k);
        ara[i]=sum;
    }

    cout<<sum<<endl;



}
