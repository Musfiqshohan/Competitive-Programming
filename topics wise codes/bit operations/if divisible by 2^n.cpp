#include<stdio.h>
int main ()
{
    unsigned int x,d=8;

    scanf("%d",&x);

    if( x& (d-1)) printf("Not divisible\n");
    else printf("Divisible\n");

    printf("%d\n",x&(d-1));
    return 0;
}
