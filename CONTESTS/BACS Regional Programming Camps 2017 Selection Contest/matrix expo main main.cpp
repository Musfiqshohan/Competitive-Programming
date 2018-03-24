#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<ll,ll>
#define inf 100000000000

using namespace std;

struct matrix {
  ll v[15][15];
  ll row, col;
};
ll mod = 1000000007    ;

matrix multiply(matrix a, matrix b) {
  assert(a.col == b.row);
  matrix r;
  r.row = a.row;
  r.col = b.col;
  for (ll i = 0; i < r.row; i++) {
    for (ll j = 0; j < r.col; j++) {
      ll sum = 0;
      for (ll k = 0; k < a.col;  k++) {
        sum += a.v[i][k] * b.v[k][j];
        sum %= mod;
      }
      r.v[i][j] = sum;
    }
  }
  return r;
}

matrix power(matrix mat, ll p) {
  assert(p >= 1);
  if (p == 1) return mat;
  if (p % 2 == 1)
    return multiply(mat, power(mat, p - 1));
  matrix ret = power(mat, p / 2);
  ret = multiply(ret, ret);
  return ret;
}

void print(matrix mat,int k)
{
    printf("Start\n");
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<k;j++)
            printf("%lld ",mat.v[i][j]);
        puts("");
    }
    printf("End\n");
}

int main() {
  ll tcase,tt=0;
  //ll a, b, n, m, k;

  scanf("%lld",&tcase);
  while (tt<tcase) {


    ll n,k;
   scanf("%lld %lld",&k,&n);
//   cin>>n;
//   k=2;
   // n--;


    matrix mat;
    mat.row = mat.col = k;
    ms(mat.v,0);

    mat.v[0][0]= mat.v[0][k-1]=1;

    for(ll i=1;i<k;i++)
    {
        mat.v[i][i-1]=1;
    }

    print(mat,k);

    printf("Case %lld: ",++tt);
    mod = 1000000007 ;

    if (n < k) {

        printf("1\n");

    }
    else if(n==k) printf("2\n");

     else {

      mat = power(mat, n);
      print(mat,k);

      ll ans = 1 * mat.v[0][0] + 1 * mat.v[0][k-1];
      ans %= mod;
      printf("%lld\n",ans);

    }
  }
  return 0;
}
