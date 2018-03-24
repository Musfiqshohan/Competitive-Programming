#include<bits/stdc++.h>
#define pii pair<i64,i64>
#define inf 100000000000000000
#define mod 1000000007
#define i64 long long
using namespace std;

struct matrix
{
    int row,col;
    int v[35][35];

    matrix operator +(matrix n)
    {
        matrix r;
        r.row=row, r.col=col;
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
                r.v[i][j]=(v[i][j]+n.v[i][j])%10;
        }
        return r;
    }


    matrix operator * (matrix n)
    {
        matrix r;
        r.row=row, r.col=n.col;

//        print_mat(n);
        //printf("%d %d , %d  %d\n",row,col,n.row,n.col);
        assert(col==n.row);


        for(int i=0; i<r.row; i++)
        {
            for(int j=0; j<r.col; j++)
            {
                int sum=0;
                for(int k=0; k<col; k++)
                {
                    sum+=v[i][k]*n.v[k][j];
                    sum%=10;
                }
                r.v[i][j]=sum;
            }
        }
        return r;
    }

} A,z,I;


struct BigMatrix
{
    int row, col;
    matrix mat[3][3]; //={z,z,z,z,z,z,z,z,z};

} BigI;

BigMatrix BInit(BigMatrix Bmat)
{
    for(int i=0; i<Bmat.row; i++)
        for(int j=0; j<Bmat.col; j++)
        {
            Bmat.mat[i][j]=z;
        }
    return Bmat;
}


void print_mat(matrix r)
{
    printf("(");
    for(int i=0; i<r.row; i++)
    {
        for(int j=0; j<r.col; j++)
        {
            printf("%d ",r.v[i][j]);
        }
        if(i<r.row-1)
            printf("-");
        //puts("");
    }
    printf(")");
}


void print_Bigmat(BigMatrix Bmat)
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            print_mat(Bmat.mat[i][j]);
            printf("   ");
        }
        puts(" ");
        puts(" ");
    }
}


BigMatrix BigMul(BigMatrix a, BigMatrix b)
{

    BigMatrix r;
    r.row=a.row, r.col=b.col;
    assert(a.col==b.row);
    r=BInit(r);

    // printf("row=%d col=%d\n",r.row,r.col);


    for(int i=0; i<r.row; i++)
    {
        for(int j=0; j<r.col; j++)
        {
            matrix sum=z;
            for(int k=0; k<a.col; k++)
            {
                sum=sum+ (a.mat[i][k]*b.mat[k][j]);
            }

//            printf("res of %d,%d\n",i,j);
//            print_mat(sum);

            r.mat[i][j]=sum;
        }
    }

    return r;

}


BigMatrix power(BigMatrix base, int p)
{
    BigMatrix res=BigI;

    while(p!=0)
    {
        if(p&1)
            res=BigMul(res,base);

        base=BigMul(base,base);
        p=p>>1;
    }
    return res;
}


void print(matrix r)
{
    for(int i=0; i<r.row; i++)
    {
        for(int j=0; j<r.col; j++)
            printf("%d",r.v[i][j]);
        puts("");
    }
}


int main()
{

    int tt=0,test;
    cin>>test;

    while(tt<test)
    {

        int n,k;
        cin>>n>>k;


        z.row=z.col=I.row=I.col=n;

        // int mxn=31;
        for(int i=0; i<n; i++)
            I.v[i][i]=1;

        BigI.row=BigI.col=3;
        for(int i=0; i<3; i++)
            for(int j=0; j<3; j++)
            {
                if(i==j)
                    BigI.mat[i][j]=I;
                else BigI.mat[i][j]=z;
            }


        //  printf("I,, %d %d\n",I.row,I.col);



        A.row=A.col=n;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
                cin>>A.v[i][j];
        }


        printf("Case %d:\n",++tt);
        if(k==1)
        {
            print(A);
            continue;
        }


        BigMatrix Bmat;
        Bmat.row=Bmat.col=3;
        Bmat=BInit(Bmat);

        Bmat.mat[0][0]=A;
        Bmat.mat[0][1]=Bmat.mat[1][1]=Bmat.mat[1][2]=Bmat.mat[2][0]=Bmat.mat[2][1]=z;
        Bmat.mat[0][2]=Bmat.mat[1][0]=Bmat.mat[2][2]=I;



        Bmat=power(Bmat,k-1);
        // Bmat=BigMul(Bmat,BigI);

        //print_Bigmat(Bmat);

        // print_mat(Bmat.mat[0][0]*BigI.mat[0][0]);

        matrix r=Bmat.mat[0][0]*A + Bmat.mat[0][2]*A;   ///for min k=2


        print(r);




    }


    return 0;
}
