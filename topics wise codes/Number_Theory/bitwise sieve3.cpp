#include<bits/stdc++.h>
using namespace std;

bool check(int n, int pos)
{
    return (bool)(n & (1<<pos));
}
int setx(int n,int pos)
{
    return n= n|(1<<pos);
}

int a[13200000];

int N=100000000;
int main()
{
    int i,j;

    int root= sqrt(N);

  /*  for (i = 4; i <= N; i += 2) {
         a[i>>5] |= (1 << (i &31 ));
     }
*/

 for( i = 3; i <= root; i += 2 )
     {
		 if( check(a[i>>5],i &31)==false)
		 {
	 		 for( j = i*i; j <= N; j += 2*i )
			 {
				 a[j>>5]=setx(a[j>>5],j & 31);
	 		 }
		 }
	 }


    puts("2");
    int  n = 1;

    for(i=3;i<=N;i+=2)
    {
        if( check( a[i>>5] , i &31 )== false)
        {
            n++;
            //printf("j=%d i=%d\n",j,i);
            if(n%100==1) printf("%d\n",i);
        }
    }





    return 0;
}

