#include<bits/stdc++.h>
#define pb push_back
#define ll long long
#define loop(i,n) for(int i=0;i<n;i++)
#define d 256
#define mod 1000000009
#define N 3
using namespace std;


void gaussianElimination(double mat[N][N+1])
{
    int singular_flag= forwardEliminatio(mat);
    if(singular_flag!=-1)
    {
        if(mat[singular_flag][N])
            printf("INCONSISTENT\n");
        else printf("many solutions\n");

        return;
    }


    backSubstitution(mat);


}

int forwardEliminatio(double mat[N][N+1])
{


}

int backSubstitution(double mat[N][N+1])
{

}




int main()
{
    double mat[N][N+1]=  {{3.0, 2.0,-4.0, 3.0},
                          {2.0, 3.0, 3.0, 15.0},
                          {5.0, -3, 1.0, 14.0}
                         };


    gaussianElimination(mat);
    return 0;
}
