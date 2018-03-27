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

int a[10000009];

int main()
{
    int i,j;


    for (i = 4; i <= 100000009; i += 2) {
         a[i/32] |= (1 << (i %32));
     }
    for(i=3; i<=10009; i+=2)
    {
        if(check (a[i>>5], i & 31)==false)
        {
            for(j=2; i*j <=100000009; j++)
            {
                int num= i*j;
                a[num>>5]=  setx( a[num>>5] , num &31 );
            }

        }
    }

    printf("2\n");
    j=1;
    for(i=3;i<=100000009;i++)
    {
        if( check( a[i>>5] , i &31 )== false)
        {
            j++;
            if(j%100==1) printf("%d\n",i);
        }
    }



    return 0;
}
