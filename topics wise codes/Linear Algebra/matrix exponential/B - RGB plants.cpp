#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
long long i,j,k;
long long m=1000000007;
struct matrix{
    long long v[5][5];
    long long row,col;
};

matrix multiply(matrix a, matrix b)
{   long long sum=0;
    matrix r;
    assert(a.col==b.row);
    r.row=a.row;
    r.col=b.col;

    for(i=0;i<r.row;i++)
    {
        for(j=0;j<r.col;j++)
        {   sum=0;
            for(k=0;k<a.col;k++)  sum=(sum%m + ((a.v[i][k]%m)*(b.v[k][j]%m))%m)%m;
            r.v[i][j]=sum;
        }
    }

    return r;
}

matrix power(matrix mat, long long p)
{
    matrix ret;
    if(p==1) return mat;

    if(p%2==1)
        return multiply(mat,power(mat,p-1));
    ret=power(mat,p/2);
    ret=multiply(ret,ret);
    return ret;
}
int main()
{
    int s;
    scanf("%d",&s);
    while(s--){
   long long n,sum=0;
    scanf("%lld",&n);
    if(n==1)  printf("3\n");
    else{
    matrix mat;
    mat.row=mat.col=3;
    mat.v[0][0]=1, mat.v[0][1]=4, mat.v[0][2]=7;
    mat.v[1][0]=2, mat.v[1][1]=5, mat.v[1][2]=8;
    mat.v[2][0]=3, mat.v[2][1]=6, mat.v[2][2]=9;

    mat= power(mat,n-1);
    for(i=0;i<mat.row;i++)
    {
        for(j=0;j<mat.col;j++) sum=((sum%m)+(mat.v[i][j])%m)%m;
    }
    printf("%lld\n",sum%m);
    }
    }
return 0;
}
