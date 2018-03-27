#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
long long B[20];
long long m;
struct matrix{
    long long row,col;
    long long v[20][20];
};

matrix multiply(matrix a, matrix b)
{
    long long i,j,k,sum=0;
    matrix r;
    assert(a.col==b.row);
    r.row=a.row, r.col=b.col;

    for(i=0;i<r.row;i++)
    {
        for(j=0;j<r.col;j++)
        {
            sum=0;
            for(k=0;k<a.col;k++)
                //sum+=a.v[i][k]*b.v[k][j];
                sum=((sum%m)+((a.v[i][k]%m)*(b.v[k][j]%m))%m)%m;

            r.v[i][j]=sum%m;

        }
    }

    return r;
}


string binary(int p)
{
    string ret="";
    while(p>0)
    {
        if(p%2==1) ret+='1';
        else ret+='0';
        p/=2;
    }

    reverse(ret.begin(),ret.end());
    return ret;
}

matrix power(matrix mat ,long long p)
{

    matrix ret=mat;
    string bin=binary(p);
    //cout<<bin<<endl;
    for(long long i=1;i<bin.size();i++)
    {
        ret=multiply(ret,ret);
        if(bin[i]=='1') ret=multiply(ret,mat);
    }

    return ret;
}

int main()
{
    matrix mat;
    mat.row=mat.col=20;
       long long d,n,i,j,sum=0;
    for(i=0;i<20;i++)
    {
        for(j=0;j<20;j++) mat.v[i][j]=0;
    }

    scanf("%lld %lld %lld",&d,&n,&m);
    mat.row=mat.col=d;
    for(i=0;i<d;i++)
        scanf("%lld",&mat.v[0][i]);

    for(i=0;i<d;i++) scanf("%lld",&B[i]);

    if(n<=d)
        printf("%lld \n",B[n-1]);
    else{


    for(i=1,j=0;i<d && j<d;i++,j++)
        mat.v[i][j]=1;

    /*for(i=0;i<d;i++)
    {
        for(j=0;j<d;j++) printf("%lld ",mat.v[i][j]);
        printf("\n");
    }*/

    mat=power(mat,n-2);


    for(i=0;i<d;i++)
       {
       // printf("t1 =%lld b1=%lld\n",mat.v[0][i],B[d-i-1]);
        //sum+=mat.v[0][i]*B[n-i-1];
        sum=((sum%m)+((mat.v[0][i]%m)*(B[d-i-1]%m))%m)%m;
       }

    printf("%lld\n",sum%m);

    }

    return 0;
}

