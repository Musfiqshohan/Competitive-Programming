#include <iostream>
#include<bits/stdc++.h>
#include <cassert>
#define ll long long
#define mod 10007
using namespace std;

struct matrix{
    ll v[5][5];
    ll row,col;
};


matrix multiply(matrix a, matrix b)
{
   // printf("Hi\n");
    matrix r;
    r.row=a.row, r.col=b.col;

    for(ll i=0;i<a.row;i++)
    {
        for(ll j=0;j<b.col;j++)
        {
            ll sum=0;

            for(ll k=0;k<a.col;k++)
            {
               sum+= ((a.v[i][k]%mod)* (b.v[k][j]%mod) )%mod;
              // sum+=a.v[i][k]*b.v[k][j];
               // cout<<sum<<endl;
                sum%=mod;
            }

            r.v[i][j]=sum;

        }

    }


    return r;
}


matrix pow1(matrix mat, ll p)
{
    if(p==1) return mat;
    if(p%2==0)
    {
        matrix ret= pow1(mat,p/2);
        ret= multiply(ret,ret);

        return ret;
    }

    return multiply( mat, pow1(mat,p-1));

}



int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    int tt=0,test;
    cin>>test;
    while(tt<test){

    ll n,a,b,c;
    cin>>n>>a>>b>>c;
   // a=1,b=2,c=3;

    matrix mat;
    mat.row=mat.col=4;
    memset(mat.v,0,sizeof mat.v);
    mat.v[0][0]=a, mat.v[0][2]=b, mat.v[0][3]=1;
    mat.v[1][0]= mat.v[2][1]= mat.v[3][3]=1;

    ll ans=0;
    if(n<=2) ans=0;
    else
    {
        ll k=n-2;

        mat=pow1(mat,k);
        ans= (mat.v[0][3]* (c%mod))%mod;
    }

    printf("Case %d: %lld\n",++tt,ans);

    }

    return 0;
}
