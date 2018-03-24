#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<ll,ll>
#define inf 100000000000
//#define  mod 1000000007
using namespace std;

struct matrix {
  int v[5][5];
  int row, col; // number of row and column
};
int mod = 10000;

// multiplies two matrices and returns the result
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

// returns mat^p
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
  int a, b, n, m;

  cin >> tcase;
  while (tcase--) {
    // input routine
    //cin >> a >> b >> n >> m;
    a=1;
    b=1;
    // preparing the matrix
    matrix mat;
    mat.row = mat.col = 2;
    mat.v[0][0] = mat.v[0][1] = mat.v[1][0] = 1;
    mat.v[1][1] = 0;

    // preparing mod value
//    mod = 1;
//    for (int i = 0; i < m; i++) mod *= 10;
//    a %= mod, b %= mod;

    mod=10000000;

    if (n < 3) {
      if (n == 0) cout << a << endl;
      if (n == 1) cout << b << endl;
      if (n == 2) cout << (a+b) % mod << endl;


    } else {

      mat = power(mat, n - 1);
      int ans = b * mat.v[0][0] + a * mat.v[0][1];
      ans %= mod;
      cout << ans << endl;
    }
  }
  return 0;
}
