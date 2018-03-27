#include <bits/stdc++.h>
using namespace std ;

int  lcs[25][25]={0} ;

int main ()
{
     int n , j ,  i , a[50] , b[50] , x  ;

        cin>>n  ;
        for (i=1 ; i<=n ; i++)
        {
            cin>>x ;
            a[x]=i ;
        }

        while (cin>>x && x!= EOF)
        {
            b[x]=1 ;
            for (i=2 ; i<=n ;i++)
            {
                cin>>x ;
                b[x]=i ;
            }

            for (i=1 ; i<=n ; i++)
            {
                for (j=1 ; j<=n ; j++)
                {
                    if (a[i]==b[j]) lcs[i][j]=1+lcs[i-1][j-1] ;
                    else lcs[i][j]=max(lcs[i][j-1] , lcs[i-1][j]) ;
                }
            }
            cout<<lcs[n][n]<<endl ;
            memset(lcs,0,sizeof(lcs)) ;
            memset(b,0,sizeof(b)) ;

        }

    return 0 ;
}
