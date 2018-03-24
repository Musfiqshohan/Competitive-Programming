#include<bits/stdc++.h>
#define pii pair<int,int>
#define inf 10000000000
#define i64 long long
using namespace std;

i64 mod;

i64 mult(i64 a, i64 b)
{
    i64 res=0;
    while(b)
    {
        if(b&1)
        {
            res+=a;
            res%=mod;
        }

        a=a<<1;
        a%=mod;
        b=b>>1;
    }

    return res;
}


struct matrix
{
    i64 row,col;
    i64 v[3][3];

    matrix operator * (matrix n)
    {
        matrix r;
        r.row=row, r.col=n.col;
        // printf("row=%d col=%d\n",row,n.col);
        //  assert(col==n.row);

        for(i64 i=0; i<r.row; i++)
        {
            for(i64 j=0; j<r.col; j++)
            {
                i64 sum=0;
                for(i64 k=0; k<col; k++)
                {
                    sum+=mult(v[i][k],n.v[k][j]);
                    sum%=mod;
                }
                r.v[i][j]=sum;

                // printf("i=%d j=%d  sum=%lld\n",i,j,sum);
            }

        }

        //puts("end");
        return r;
    }


} I;

void print_mat(matrix mat)
{
    for(i64 i=0; i<mat.row; i++)
    {
        for(i64 j=0; j<mat.col; j++)
            printf("%lld ",mat.v[i][j]);
        puts("");
    }
}



matrix power(matrix base, i64 p)
{
    I.row=I.col=base.row;

    for(int i=0; i<I.row; i++)
        I.v[i][i]=1;

    matrix res=I;

    while(p!=0)
    {
        //printf("p=%d\n",p);
        if(p&1)
            res=res*base;

       // print_mat(res);

        base=base*base;

        p=p>>1;
    }

   // print_mat(res);

    return res;
}

int main()
{


    int tt=0,test;
    cin>>test;

    while(tt<test)
    {

        int b,d;
        i64 n,M;
        cin>>n>>b>>d>>M;

        //M=1000000000;

        mod=M;

        matrix mat;
        mat.row=mat.col=2;

        mat.v[0][0]=b;
        mat.v[0][1]=mat.v[1][1]=1;
        mat.v[1][0]=0;


        //mat=power(mat,2LL);


        i64 res=0;

        if(n==1) res=d;
        else
        {
            matrix ret=power(mat,n-1);
           // print_mat(ret);
            //res=((ret.v[0][0]*d)%mod+d)%mod;
            res=(ret.v[0][0]*d)%mod+(ret.v[0][1]*d)%mod;

        }


        printf("Case %d: %lld\n",++tt,res%mod);


    }




    return 0;
}
