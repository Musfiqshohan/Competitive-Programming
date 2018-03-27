#include<bits/stdc++.h>
using namespace std;

bool check(int n, int pos)
{
    return n & (1<<pos);
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
    for(i=3; i<=root; i+=2)
    {
        if(check (a[i>>5], i & 31)==false)
        {
            for(j= 2 ; i*j <=N ; j++)
            {
                int num= i*j;
                a[num>>5]=  setx( a[num>>5] , num &31 );
            }

        }
    }

    a[0]= setx( a[0], 0);
    a[0]= setx( a[0], 1);

    printf("2\n");
    j=1;
    for(i=3;i<=N;i+=2)
    {
        if( check( a[i>>32] , i &31 )== false && i%2!=0)
        {
            j++;
            if(j%100==1) printf("%d\n",i);
        }
    }



    return 0;
}
