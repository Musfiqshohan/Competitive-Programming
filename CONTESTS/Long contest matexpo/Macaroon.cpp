#include<bits/stdc++.h>
#define i64 long long
//#define mod 1000000007
using namespace std;

i64 n,m;

const i64 mod=1000000000;


struct matrix
{
    i64 v[301][301];
    i64 row,col;
} I,matt;


matrix multiply(matrix a, matrix b)
{
    matrix r;
    r.row=a.row, r.col=b.col;

    // printf("%lld %lld %lld %lld\n",a.row,a.col,b.row,b.col);

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




matrix expo(matrix base, i64 exponent)
{
    matrix ans = I;
    while(exponent !=0 )
    {
        if((exponent&1) == 1)
        {
            ans = multiply(ans,base) ;

        }
        base = multiply(base,base);
        exponent>>= 1;
    }
    return ans;
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

void print(int tot)
{
    for(int i=0; i<tot; i++)
    {
        for(int j=0; j<tot; j++)
        {
            printf("%lld ",matt.v[i][j]);
        }
        puts("");
    }
}

void f(int pos, int mask, int pr)
{
    //   printf("%d %d\n",pos,mask);
    if(pos==n)
    {
        //  printf("pr=%d mask=%d\n",pr,mask);
        matt.v[pr][mask]++;

        return;
    }

    // if(mask& (1<<pos)) f(pos+1,mask,pr);
    if(mask& (1<<pos)) f(pos+1, mask& ~(1<<pos),pr);
    else
    {
        f(pos+1,mask,pr);

        if(pos+2<=n && (mask& 1<<(pos+1))==0)
            f(pos+2,mask,pr);

        f(pos+1,mask|(1<<pos),pr);
    }

}


int main()
{


    cin>>n>>m;



    int tot=(1<<n);
    for(int i=0; i<tot; i++)
    {
        f(0,i,i);
    }



    I.row=I.col=tot;

    for(int i=0; i<tot; i++)
            I.v[i][i]=1;

    matt.row=matt.col=tot;
    matt=expo(matt,m);
   // matt=power(matt,m);
    //print(tot);

   // matt= multiply(matt,matt);

    cout<<matt.v[0][0]<<endl;





}
