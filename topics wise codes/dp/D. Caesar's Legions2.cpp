#include <iostream>
#include <cstring>
#include<bits/stdc++.h>
using namespace std;

#define N 128
#define K 16
#define M 100000000

int nWays[N][N][K][K];
int N1, N2, K1, K2;

long long getNWays(int n1, int n2, int k1, int k2) {

    printf("%d %d %d %d\n",n1,n2,k1,k2);
    if (n1 < 0 || n2 < 0 || k1 < 0 || k2 < 0)
        return 0;
    if(n1 == 0 && n2 == 0)
       {    printf("Fuck\n");
           return 1;
       }
    if (nWays[n1][n2][k1][k2] != -1)
        return nWays[n1][n2][k1][k2];
    return nWays[n1][n2][k1][k2] =
            (getNWays(n1 - 1, n2, k1 - 1, K2) + getNWays(n1, n2 - 1, K1, k2 - 1)) % M;
}

int main() {
    memset(nWays, -1, sizeof nWays);
    cin >> N1 >> N2 >> K1 >> K2;
    cout << getNWays(N1, N2, K1, K2) << endl;
    return 0;
}
