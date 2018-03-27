#include<bits/stdc++.h>
#define llu unsigned long long
using namespace std;

struct matrix
{
    llu v[3][3];
    llu row,col;
};

matrix multiply(matrix a, matrix b)
{
    assert(a.col == b.row);
    matrix r;
    r.row = a.row;
    r.col = b.col;
    for (llu i = 0; i < r.row; i++)
    {
        for (llu j = 0; j < r.col; j++)
        {
            llu sum = 0;
            for (llu k = 0; k < a.col;  k++)
            {
                sum += (a.v[i][k] * b.v[k][j]);

            }
            r.v[i][j] = sum;
        }
    }
    return r;
}

matrix power(matrix mat, llu p)
{
    assert(p >= 1);
    if (p == 1) return mat;
    if (p % 2 == 1)
        return multiply(mat, power(mat, p - 1));
    matrix ret = power(mat, p / 2);
    ret = multiply(ret, ret);
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);



    llu tt=0,test;
    cin>>test;

    while(tt<test)
    {


        llu p,q,n;
        cin>>p>>q>>n;

        matrix mat;
        mat.row = mat.col = 2;
        memset(mat.v,0,sizeof mat.v);

        mat.v[0][0]=p, mat.v[0][1]=-q;
        mat.v[1][0]=1;

        llu ans=0;
        if(n==0) ans=2;
        else if(n==1) ans=p;
        else
        {
            llu pp= n-1;

            mat= power(mat,pp);

            ans= mat.v[0][0]*p  +  mat.v[0][1]*2;

        }


        cout<<"Case "<<++tt<<": "<<ans<<endl;

    }

}
