#include<stdio.h>
int main()
{
    unsigned int x;
    scanf("%u",&x);

    if(x & (x+1)) printf("Not\n");
    else printf("Yes\n");
    return 0;
}
