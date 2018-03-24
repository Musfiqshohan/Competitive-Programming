#include<bits/stdc++.h>
#define i64 long long
#define mod 1000000007
using namespace std;



struct matrix
{
    int row,col;
    i64 v[130][130];
} mat,I;

int ara[500];

matrix multiply(matrix a, matrix b)
{
    matrix r;
    r.row=a.row, r.col=b.col;


    assert(a.col==b.row);

    for(int i=0; i<r.row; i++)
    {
        for(int j=0; j<r.col; j++)
        {
            i64 sum=0;
            for(int k=0; k<a.col; k++)
            {
                sum+=a.v[i][k]*b.v[k][j];
                // printf("sum=%lld  k=%lld\n",sum,k);
                sum%=mod;
            }


            //printf("i=%lld j=%lld sum=%lld\n",i,j,sum);
            r.v[i][j]=sum;
        }
    }

    return r;

}




matrix expo(matrix base, int n)
{
    matrix ans=I;

    while(n!=0)
    {
        if(n&1==1)
        {
            ans=multiply(ans,base);
        }

        base=multiply(base,base);
        n>>=1;
    }
    return ans;
}



void pb(int n)
{
    bitset<7>b(n);
    cout<<b<<endl;
}

void f(int pos, int root, int cur)
{

    if(__builtin_popcount(cur)==4)
    {
//        printf("at root:\n");
//        pb(root);
//        pb(cur);
//        puts("");
        mat.v[ara[root]][ara[cur]]++;
        return;
    }

    if(pos==7) return;


    if((root& (1<<pos))==0)
    {

        f(pos+1,root,cur);
    }
    else
    {
        int t1,t2,msk1,msk2;

        if(pos-1>=0)
        {
            t1=cur&(1<<(pos-1));
            msk1=cur|(1<<(pos-1));

            if(t1==0)
                f(pos+1, root, msk1);
        }

        if(pos+1<7)
        {

            t2=cur&(1<<(pos+1));
            // pb(t2);
            msk2=cur|(1<<(pos+1));
            if(t2==0)
                f(pos+1, root, msk2);
        }

    }

    return ;

}

void print(int tot)
{
    for(int i=0; i<tot; i++)
    {
        for(int j=0; j<tot; j++)
            printf("%lld ",mat.v[i][j]);
        puts("");
    }
}

int main()
{



    int cnt=0;
    for(int i=0; i<(1<<7); i++)
    {
        if(__builtin_popcount(i)!=4) continue;
        ara[i]=cnt++;
    }

    for(int i=0; i<(1<<7); i++)
    {
        if(__builtin_popcount(i)!=4) continue;
        f(0,i,0);
    }

    int tot=cnt;

  //  cout<<tot<<endl;

    I.row=I.col=tot;
    for(int i=0; i<tot; i++)
        I.v[i][i]=1;

    int tt=0,test;
    scanf("%d",&test);

    while(tt<test)
    {
        int n,x;
        scanf("%d",&n);

        mat.row=mat.col=tot;
        matrix matt;
        matt.row=matt.col=tot;
        matt=expo(mat,n-1);  /// before using any matrix multiplication define their row and col number



        int start=0;
        for(int i=0; i<7; i++)
        {
            scanf("%d",&x);
            if(x!=0)
                start|=(1<<i);
        }


        // cout<<start<<endl;
        i64 res=0;
        for(int i=0; i<tot; i++)
        {
            res+=matt.v[ara[start]][i];
            res%=mod;
        }

        printf("Case %d: %lld\n",++tt,res);


    }

    return 0;
}
