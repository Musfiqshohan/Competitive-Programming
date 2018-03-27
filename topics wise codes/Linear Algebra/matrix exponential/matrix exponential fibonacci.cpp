#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
long long i,j,k,mod=1000000007;
long long total[100009];
struct matrix
{
    long long v[5][5];
    long long row,col;

};

matrix multiply(matrix a,matrix b)
{
    long long sum=0;
    assert(a.col==b.row);
    matrix r;
    r.row=a.row;
    r.col=b.col;
    for(i=0; i<r.row; i++)
    {
        for(j=0; j<r.col; j++)
        {
            sum=0;
            for(k=0; k<a.col; k++) sum= ((sum%mod) + ((a.v[i][k]%mod)*(b.v[k][j]%mod))%mod)%mod;
            r.v[i][j]=sum;

        }
    }


    return r;
}
matrix power(matrix mat, long long p)
{
    if (p==1) return mat;
    if(p%2==1)
        return multiply(mat,power(mat,p-1));
    matrix ret= power(mat,p/2);
    ret= multiply(ret,ret);
    return ret;
}

int main()
{
    long long m=100000,n;


    for(n=1; n<=m; n++)
    {
        long long a=0,b=1;



        matrix mat;
        mat.row=mat.col=2;
        mat.v[0][0]=mat.v[0][1]=mat.v[1][0]=1;
        mat.v[1][1]=0;

        if(n<3)
        {
            if(n==0)  total[n]=a;
            else if(n==1)  total[n]=b;
            else   total[n]=a+b;
        }
        else
        {
            mat= power( mat,n-1);
            long long ans= (mat.v[0][0]+mat.v[0][1]*0)%mod;
            total[n]=ans;
        }

        //total[n]=total[n-1]+n*total[n];

    }

    long long t=0,test,y;
    scanf("%lld",&test);

    while(t++<test)
    {
        scanf("%lld",&y);
        printf("%lld\n",total[y]);
    }


    return 0;
}
