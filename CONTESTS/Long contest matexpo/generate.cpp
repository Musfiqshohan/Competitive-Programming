/* rand example: guess the number */
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

int main ()
{
    freopen("testcase.txt","w",stdout);
    int k, iGuess;
    long long n;
    int cnt=0;
    srand (time(NULL));
    while(cnt++<1000)
    {

        n = rand() % 1000 + 1;
        k = rand() % 10 + 1;
        printf("%lld %d\n",n,k);

    }


    return 0;
}


