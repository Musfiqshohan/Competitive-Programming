/** 1st: you have to calculate the both results simultaneously ,not separately cz then one will give result for k length
and another will for less than k */
#include<bits/stdc++.h>
#define pii pair<i64,i64>
#define inf 100000000000000000
#define mod 1000000007
#define i64 long long
using namespace std;



struct matrix
{
    i64 row, col;
    pii v[155][155];
} I;


matrix mul(matrix a, matrix b)
{
    matrix r;
    assert(a.col==b.row);
    r.row=a.row, r.col=b.col;
    for(i64 i=0; i<a.row    ; i++)
    {
        for(i64 j=0; j<b.col; j++)
        {
            i64 sum=inf;
            for(i64 k=0; k<a.col; k++)
            {
                i64 res=a.v[i][k].first+b.v[k][j].first;
                sum=min(sum,res);
            }
            r.v[i][j].first=sum;

            sum=0;
            for(i64 k=0; k<a.col; k++)
            {
                i64 res=a.v[i][k].first+b.v[k][j].first;
                if(res==r.v[i][j].first)
                {
                    sum+=a.v[i][k].second*b.v[k][j].second;
                    sum%=mod;
                }
            }
            r.v[i][j].second=sum;
        }
    }
    return r;
}


matrix power(matrix base, i64 n)
{

    matrix res=I;
    while(n!=0)
    {
        if(n&1)
            res=mul(res,base);
        base=mul(base,base);
        n=n>>1;
    }
    return res;
}




void pri64(i64 n, i64 ara[][155])
{
    for(i64 i=0; i<n; i++)
    {
        for(i64 j=0; j<n; j++)
        {
            if(ara[i][j]>100) printf("x ");
            else
                printf("%lld ",ara[i][j]);
        }
        puts("");
    }
}
int main()
{

//    for(i64 i=0; i<152; i++)
//        Ic.v[i][i]=1;

    for(i64 i=0; i<152; i++)
        for(i64 j=0; j<152; j++)
        {
            if(i==j) I.v[i][j]= {0,1};
            else I.v[i][j]= {inf,0};
        }

    i64 n,m,k,uu,vv,ww;
    cin>>n>>m>>k;

    matrix mat;

    mat.row=mat.col=I.row=I.col=n;


    for(i64 i=0; i<n; i++)
        for(i64 j=0; j<n; j++)
            mat.v[i][j]= {inf,0};

    for(i64 i=0; i<m; i++)
    {
        scanf("%lld %lld %lld",&uu,&vv,&ww);
        uu--,vv--;
        mat.v[uu][vv]= {ww,1};
        mat.v[vv][uu]= {ww,1};
    }



    mat=power(mat,k);


    for(i64 i=0; i<n; i++)
    {
        for(i64 j=0; j<n; j++)
        {
            // if(j) printf(" ");
            if(mat.v[i][j].second==0)
                printf("X 0 ");
            else printf("%lld %lld ",mat.v[i][j].first, mat.v[i][j].second);
        }
        puts("");

    }




    return 0;
}
