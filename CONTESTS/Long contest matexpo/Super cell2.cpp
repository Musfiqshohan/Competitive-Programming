#include<bits/stdc++.h>
#define pii pair<i64,i64>
#define inf 100000000000000000
#define mod 1000000007
#define i64 long long
using namespace std;

i64 dp[35][35][105];

struct matrix
{
    i64 row,col;
    i64 v[35][35];

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

} matt;



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

    matrix I;
    I.row=I.col=base.row;
    for(i64 i=0; i<base.row; i++)
        I.v[i][i]=1;

    matrix res=I;

    while(p!=0)
    {
        if(p&1)
            res=res*base;

        base=base*base;
        p=p>>1;
    }

    return res;
}


i64 f(i64 n, i64 T, i64 k)
{
    // printf("n=%lld \n",n);
    if(n==0)
        return dp[n][T][k]=1;
    if(dp[n][T][k]!=-1) return dp[n][T][k];

    i64 sum=0;

    i64 m=n;
    i64 t=T;
    while(t--)
    {
        m--;
        sum+= (k*f(m,T,k))%mod;
        sum%=mod;

        if(m==0) break;
    }

    return dp[n][T][k]=sum;

}

void precalc()
{
    for(i64 N=31; N>=0; N--)
    {
        for(i64 T=31; T>=0; T--)
        {
            for(i64 K=101; K>=0; K--)
            {
                f(min(N,T),T,K);
            }
        }
    }
    // f(min(N,T),T,K);
}



i64 Born(i64 N,i64 T,i64 K)
{
    // printf("entering %lld\n",N);
    if(N<0) return 0;
    if(N<=T)
        return dp[N][T][K];

    matrix ret=power(matt,N-T);

    //print_mat(ret);

    i64 sum=0;
    for(i64 i=1; i<ret.col; i++)
    {
        sum+= (ret.v[0][i]*dp[T-(i-1)][T][K])%mod;
        sum%=mod;
    }

    return sum;
}

int main()
{
    clock_t start,endd;
    double cpu_time;
    start=clock();

    //freopen("input.txt","r",stdin);
    memset(dp,-1,sizeof dp);
    precalc();
    i64 test;
    scanf("%lld",&test);
    //puts("gg");
    while(test--)
    {
        //memset(dp,-1,sizeof dp);
        i64 T,K,N;
        scanf("%lld %lld %lld",&T,&K,&N);
        //cin>>T>>K>>N;

        memset(matt.v,0,sizeof matt.v);
        matt.row=matt.col=T+1;
        for(i64 i=1; i<matt.col; i++)
        {
            if(i<matt.col-1)
                matt.v[0][i]=1;

            matt.v[0][i]+=K;
        }


        for(i64 i=1; i<matt.col; i++)
        {
            matt.v[1][i]=K;
        }

        for(i64 i=2; i<matt.row; i++)
        {
            matt.v[i][i-1]=1;
        }

        // print_mat(matt);

//        for(i64 i=0;i<=N;i++)
//            printf("%lld =%lld\n",i,dp[i][T][K]);


        i64 tot=0;

        if(N<=T)
        {
            tot=Born(N,T,K);
            for(i64 i=1; i<T; i++)
            {
                i64 res=Born(N-i,T,K);
                // printf("at %lld  =%lld\n",N-i,res);
                tot+=res;
                tot%=mod;
            }
        }
        else
        {
            tot=Born(N,T,K);
        }

        //cout<<tot<<endl;
        printf("%lld\n",tot);

    }


    endd=clock();
    cpu_time=((double)(endd-start))/CLOCKS_PER_SEC;
 //   cout<<cpu_time<<endl;
    return 0;

}
