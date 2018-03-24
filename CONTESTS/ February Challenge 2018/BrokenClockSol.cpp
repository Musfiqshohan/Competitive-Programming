#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int ljz = 1000000007;
#define Tm(a, b) (int((1ll * (a) * (b)) % ljz))
inline void MOD(register int &x) {if (x >= ljz) x -= ljz; if (x < 0) x += ljz;}
inline int iMOD(register int x) {if (x >= ljz) return x - ljz; if (x >= 0) return x; return x + ljz;}
int fpm(int x, int y) {int p = 1, s = x; for (; y; y >>= 1) {if (y & 1) p = Tm(p, s); s = Tm(s, s);} return p;}

int cosine, sine_square;
//cosine = cos(x), sine_square = sin(x)^2 = 1 - cosine^2
class p {
public:
  int num, sine;
  //it represents a number num + sine*sin(x)
  p() {num = sine = 0;}
  p(int n, int s) {num = n; sine = s;}
};

p operator + (const p &a, const p &b) {return p(iMOD(a.num + b.num), iMOD(a.sine + b.sine));}
p operator - (const p &a, const p &b) {return p(iMOD(a.num - b.num), iMOD(a.sine - b.sine));}
p operator * (const p &a, const p &b) {
  //(a+b*sin)(c+d*sin)=ac+bd(1-cosine^2)+(ad+bc)sin
  return p(iMOD(Tm(a.num, b.num) + Tm(Tm(a.sine, b.sine), sine_square)),
	   iMOD(Tm(a.num, b.sine) + Tm(a.sine, b.num)));
}

p s1, c1;//s1 = p(0, 1); c1 = p(cosine, 0);
void work(ll n, p &s, p &c) {
  if (n == 1) {s = s1; c = c1; return;}
  if (n & 1) {
    p s2, c2;
    work(n - 1, s2, c2);
    //sin(nx) = sin((n-1)x)cos(x) + cos((n-1)x)sin(x)
    //cos(nx) = cos((n-1)x)cos(x) - sin((n-1)x)sin(x)
    s = s2 * c1 + c2 * s1;
    c = c2 * c1 - s2 * s1;
  } else {
    p s2, c2;
    work(n >> 1, s2, c2);
    s = s2 * c2 + c2 * s2;
    c = c2 * c2 - s2 * s2;
  }
}

void doit() {
  int l, d; ll t; p s, c;
  assert(scanf("%d%d%lld", &l, &d, &t) == 3);
  assert(1 <= d && d < l && l <= 1000000000);
  assert(1 <= t && t <= 1000000000000000000ll);
  cosine = Tm(d, fpm(l, ljz - 2));
  sine_square = iMOD(1 - Tm(cosine, cosine));
  s1 = p(0, 1); c1 = p(cosine, 0);
  work(t, s, c);
  assert(c.sine == 0);

  printf("%d %d %lld =",l,d,t);
  printf("%d\n", Tm(l, c.num));
}

int main() {
//    out("brk2.txt");
  int T;
  assert(scanf("%d", &T) == 1);
  assert(1 <= T && T <= 100000);
  while (T--) doit();
  assert(scanf("%d", &T) == EOF);
  return 0;
}
