#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<ll,ll>
#define inf 100000000000

using namespace std;

struct matrix {
  int v[12][12];
  int row, col;
};
int mod = 1000000007    ;

matrix multiply(matrix a, matrix b) {
  assert(a.col == b.row);
  matrix r;
  r.row = a.row;
  r.col = b.col;
  for (int i = 0; i < r.row; i++) {
    for (int j = 0; j < r.col; j++) {
      int sum = 0;
      for (int k = 0; k < a.col;  k++) {
        sum += a.v[i][k] * b.v[k][j];
        sum %= mod;
      }
      r.v[i][j] = sum;
    }
  }
  return r;
}

matrix power(matrix mat, int p) {
  assert(p >= 1);
  if (p == 1) return mat;
  if (p % 2 == 1)
    return multiply(mat, power(mat, p - 1));
  matrix ret = power(mat, p / 2);
  ret = multiply(ret, ret);
  return ret;
}

int main() {
  int tcase;
  int a, b, n, m, k;

  cin >> tcase;
  while (tcase--) {


    cin >>k>>n  ;
    n--;


    matrix mat;
    mat.row = mat.col = k;
    ms(mat.v,0);
    mat.v[0][0]= mat.v[0][k-1]=1;

    for(int i=1;i<k;i++)
    {
        mat.v[i][i-1]=1;
    }



    mod = 1000000007 ;

    if (n < k) {

        printf("1\n");

    }
    else if(n==k) printf("2\n");

     else {

      mat = power(mat, n - 1);
      int ans = 2 * mat.v[0][0] + 1 * mat.v[0][k-1];
      ans %= mod;

      printf("res= %d\n",ans);

    }
  }
  return 0;
}
