#include<bits/stdc++.h>
#define i64 long long
//#define mod 1000000007
using namespace std;

const i64 mod=1000000007;


struct matrix{
    i64 v[5][5];
    i64 row,col;
}I;


matrix multiply(matrix a, matrix b)
{
    matrix r;
    r.row=a.row, r.col=b.col;

    for(i64 i=0;i<r.row;i++)
    {
        for(i64 j=0;j<r.col;j++)
        {
            i64 sum=0;
            for(i64 k=0;k<a.col;k++)
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
i64 f(i64 N, i64 X, i64 M, i64 Y, i64 K)
{

    matrix mat, mat1,mat2,mat3;
    mat.row=mat.col=2;
    memset(mat.v,0,sizeof mat.v);
    mat.v[0][0]=mat.v[0][1]=mat.v[1][0]=1;
    mat.v[1][1]=0;



    mat1=power(mat,N-1);

    mat2=power(mat,M-1);
    mat3=power(mat,K-1);


    i64 a1,a2,b1,b2,c1,c2,det,detX,detY;

    a1=mat1.v[0][0];
    b1=mat1.v[0][1];
    c1=X;

    a2=mat2.v[0][0];
    b2=mat2.v[0][1];
    c2=Y;



    swap(a1,b1); a1+=b1;
    swap(a2,b2); a2+=b2;
   // pri64f("a1=%lld b1=%lld a2=%lld b2=%lld\n",a1,b1,a2,b2);

    det=(a1*b2)%mod-(a2*b1)%mod;
    det= (det+mod)%mod;

    detX=(b2*c1)%mod-(b1*c2)%mod;
    detX= (detX+mod)%mod;

    detY=(a1*c2)%mod-(a2*c1)%mod;
    detY=(detY+mod)%mod;


   // cout<<det<<" "<<detX<<" "<<detY<<endl;
    if(det==0) return -1;

    i64 a=(detX*pow1(det,mod-2))%mod;

    i64 b=(detY*pow1(det,mod-2))%mod;

//    pri64f("a=%lld  b=%lld n=%lld m=%lld\n",mat3.v[0][0],mat3.v[0][1], a,b);
//
//    i64 r1= ((mat1.v[0][0]*(a+b))%mod + (mat1.v[0][1]*a)%mod)%mod;
//    i64 r2= ((mat2.v[0][0]*(a+b))%mod + (mat2.v[0][1]*a)%mod)%mod;
//
//    cout<<r1<<" "<<r2<<endl;
    if(a+b>X || a+b>Y) return -1;

    i64 res= ((mat3.v[0][0]*(a+b))%mod + (mat3.v[0][1]*a)%mod)%mod;
    return res;


   // pri64f("-> %lld %lld\n",mat.v[0][0], mat.v[0][1]);

}
int main()
{

    I.row=I.col=2;
    I.v[0][0]=I.v[1][1]=1;


    i64 tt=0,test;
    scanf("%lld",&test);

    while(tt<test){


    i64 N,X,M,Y,K;
    cin>>N>>X>>M>>Y>>K;

    i64 res=f(N,X,M,Y,K);

    printf("Case %lld: ",++tt);
    if(res==-1)
        printf("Impossible\n");
    else
    printf("%lld\n",res);


    }


}
