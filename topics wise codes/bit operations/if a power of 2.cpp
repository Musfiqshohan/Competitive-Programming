#include<stdio.h>
int main()
{
    unsigned int x;
    scanf("%u",&x);
    if(x&(x-1)) printf("Not a power of 2\n");
    else printf("Powe of 2\n");
    return 0;
}
