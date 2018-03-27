
#include <bits/stdc++.h>
#define MOD 10007
using namespace std;
struct matrix {
    int r  , c ;
    int grid[4][4];
    matrix operator * (matrix b)
    {
        matrix res; res.r = r ; res.c = b.c;
        for(int i=0;i<r;i++){
            for(int j=0;j<b.c;j++){
                int part = 0;
                for(int k=0;k<c;k++) part+= grid[i][k]*b.grid[k][j];
                res.grid[i][j] = (part%MOD);
            }
        }
        return res;
    }
};

matrix expo(matrix a , int n )
{
    if(n==1) return a;
    matrix xxx = expo(a,n/2);
    xxx =xxx*xxx;
    if(n&1) xxx =xxx*a;
    return xxx;
}


int solve(int n)
{
    if(n==0 || n==1) return 1;
    if(n==2) return 2;
    matrix m , A;
    A.c=1 , A.r=3;
    m.c=m.r=3;
    A.grid[0][0] = 2;
    A.grid[1][0] = 1;
    A.grid[2][0] = 1;

    m.grid[0][0] = 2; m.grid[0][1] = 0; m.grid[0][2]=1;
    m.grid[1][0] = 1; m.grid[1][1] = 0; m.grid[1][2]=0;
    m.grid[2][0] = 0; m.grid[2][1] = 1; m.grid[2][2]=0;
    m = expo(m,n-2);
    m = m*A;
    return m.grid[0][0]%MOD;
}
int main()
{
    int test_case , case_number=0;
    scanf("%d",&test_case);
    while(test_case--){
            int n;
            scanf("%d",&n);
            printf("Case %d: %d\n",++case_number,solve(n));
    }
    return 0;
}
