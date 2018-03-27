#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <set>
#include <cstring>
#include <iomanip>
#include <map>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
#include <string>
#include <vector>
#include <new>
#include <bitset>
#include <ctime>
#include <cassert>
#include <stdint.h>
#include <unistd.h>

 using namespace std;

#define ll long long int
#define INF 1000000000
#define PI acos(-1.0)
#define EPS 1e-9

template < typename X > X gcd( X a, X b ) { if( !b ) return a ; else return gcd(b, a%b) ; }

typedef vector<int> vi;
typedef pair<int, int> ii;


const int D = 20 ;

struct Matrix {
	ll t[D][D] ;
} ;

int n, d, MOD, A[D], F[D], i, j, k, ans ;

inline Matrix mul( Matrix a, Matrix b ) {
	Matrix c ;

	for( i = 1; i <= d; ++i )
		for( j = 1; j <= d; ++j )
			for( k = 1, c.t[i][j] = 0 ; k <= d; ++k )
				c.t[i][j] += ( a.t[i][k] * b.t[k][j] ) , c.t[i][j] %= MOD ;

	return c ;
}

inline Matrix solve( Matrix b ) {
	Matrix res ;
	for( i = 1; i <= d; ++i )
		for( j = 1; j <= d; ++j )
			res.t[i][j] = ( ( i == j ) ? 1 : 0 ) ;
	while( n ) {
		if( n & 1 )
			res = mul( res, b ) ;
		n >>= 1;
		b = mul( b, b ) ;
	}
	return res ;
}

int main() {
	while(1) {
		scanf("%d %d %d", &d, &n, &MOD );
		if( !d )
			break;

		--n ;

		for( i = 1; i <= d; ++i )
			scanf("%d", &A[i]) ;

		for( i = 1; i <= d; ++i )
			scanf("%d", &F[i] ) ;

		Matrix T;

		for( i = 1; i <= d; ++i )
			for( j = 1; j <= d; ++j )
				T.t[i][j] = 0 ;

		for( i = 1; i <= d - 1; ++i )
			T.t[i][i + 1] = 1 ;

		for( i = 1; i <= d; ++i )
			T.t[d][i] = A[d - i + 1] ;


        for(i=1;i<=d;i++)
        {
            for(j=1;j<=d;j++) printf("%d ",T.t[i][j]);
            printf("\n");
        }
		T = solve( T );
		ans = 0;

		for( i = 1; i <= d; ++i )
        {   //printf("%d %d\n",T.t[1][i],F[i]);
			ans = ( ans + T.t[1][i] * F[i] ) % MOD ;

        }

		printf("%d\n", ans);
	}
	return 0;
}

