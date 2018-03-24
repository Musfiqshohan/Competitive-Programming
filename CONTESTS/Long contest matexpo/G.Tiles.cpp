#include<bits/stdc++.h>
#define i64 long long
//#define mod 1000000007
using namespace std;

const i64 mod=10007;


struct matrix
{
    i64 v[5][5];
    i64 row,col;
} I;


matrix multiply(matrix a, matrix b)
{
    matrix r;
    r.row=a.row, r.col=b.col;

    for(i64 i=0; i<r.row; i++)
    {
        for(i64 j=0; j<r.col; j++)
        {
            i64 sum=0;
            for(i64 k=0; k<a.col; k++)
            {
                sum+=a.v[i][k]*b.v[k][j];
                // pri64f("sum=%lld  k=%lld\n",sum,k);
                sum%=mod;
            }


            //pri64f("i=%lld j=%lld sum=%lld\n",i,j,sum);
            r.v[i][j]=sum;
        }
    }

    return r;

}


matrix power(matrix mat, i64 n)
{
    if(n==0)
        return I;

    if(n==1) return mat;
    if(n%2==0)
    {
        matrix ret=power(mat,n/2);
        return multiply(ret,ret);
    }

    return multiply(mat, power(mat,n-1));
}


i64 pow1(i64 x, i64 n)
{
    if(n==0) return 1;

    if(n%2==0)
    {
        i64 res= pow1(x,n/2);
        return (res*res)%mod;
    }

    return (x*pow1(x,n-1))%mod;
}

int main()
{

    I.row=I.col=2;
    I.v[0][0]=I.v[1][1]=1;


    i64 tt=0,test;
    scanf("%lld",&test);

    while(tt<test)
    {

        int n;
        cin>>n;

        matrix mat;
        mat.row=mat.col=4;
        mat.v[0][0]=mat.v[0][1]=mat.v[0][2]=mat.v[0][3]=1;
        mat.v[1][0]=mat.v[1][1]=0, mat.v[1][2]=mat.v[1][3]=1;
        mat.v[2][0]=0,mat.v[2][1]=1,mat.v[2][2]=0, mat.v[2][3]=1;
        mat.v[3][0]=1, mat.v[3][1]=mat.v[3][2]=mat.v[3][3]=0;


        mat=power(mat,n);

        printf("Case %lld: %lld\n",++tt,mat.v[0][0]);

    }


}
