#include<bits/stdc++.h>
#define ms(a,b) memset((a),(b),sizeof(a))
#define OK ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
using namespace std;

ll mod;

struct matrix
{
    ll v[7][7];
    ll row,col;
};


matrix  multiply(matrix a, matrix b)
{
    matrix r;
    r.row = a.row;
    r.col = b.col;
    for (ll i = 0; i < r.row; i++)
    {
        for (ll j = 0; j < r.col; j++)
        {
            ll sum = 0;
            for (ll k = 0; k < a.col;  k++)
            {
                sum += (a.v[i][k] * b.v[k][j])%mod;
                sum %= mod;
            }
            r.v[i][j] = sum;
        }
    }
    return r;
}

matrix pow1(matrix mat, ll p)
{
    if(p==1) return  mat;
    if(p%2==0)
    {
        matrix ret= pow1(mat,p/2);
        ret= multiply(ret,ret);
        return ret;
    }

    return multiply(mat, pow1(mat,p-1));
}

void print_mat(matrix r)
{

    for (ll i = 0; i < r.row; i++)
    {
        for (ll j = 0; j < r.col; j++)
        {
            printf("%lld ",r.v[i][j]);
        }
        puts("");
    }

}

int main()
{

    //OK;

    int tt=0,test;
    cin>>test;
    while(tt<test){

    printf("Case %d:\n",++tt);

    ll a1,b1,c1,a2,b2,c2,f0,f1,f2,g0,g1,g2,n;

    cin>>a1>>b1>>c1;
    cin>>a2>>b2>>c2;
    cin>>f0>>f1>>f2;
    cin>>g0>>g1>>g2;
    cin>>mod;

    matrix mat;
    mat.col=mat.row=6;

    ll query;
    cin>>query;

    for(ll q=0; q<query; q++)
    {
        cin>>n;
        memset(mat.v, 0, sizeof mat.v);
        mat.v[0][0]=a1, mat.v[0][1]=b1, mat.v[0][5]=c1;
        mat.v[3][2]=c2, mat.v[3][3]=a2, mat.v[3][4]=b2;
        mat.v[1][0]= mat.v[2][1]= mat.v[4][3]=mat.v[5][4]=1;


        ll ans1=0,ans2=0;
        if(n==0) ans1=f0, ans2=g0;
        else if(n==1) ans1=f1, ans2=g1;
        else if(n==2) ans1=f2, ans2=g2;
        else
        {
            ll k= n-2;
            mat= pow1(mat, k);

            ans1= ((mat.v[0][0]*f2)%mod + (mat.v[0][1]*f1)%mod + (mat.v[0][2]*f0)%mod
                   +(mat.v[0][3]* g2)+ (mat.v[0][4]* g1) + (mat.v[0][5]* g0)%mod)%mod;
            ans2= ((mat.v[3][0]*f2)%mod +(mat.v[3][1]*f1)%mod + (mat.v[3][2]*f0)%mod
                   +(mat.v[3][3]*g2)%mod +(mat.v[3][4]*g1)%mod+ (mat.v[3][5]* g0)%mod)%mod;

        }

        cout<<ans1%mod<<" "<<ans2%mod<<endl;
    }


    }


    return 0;
}
