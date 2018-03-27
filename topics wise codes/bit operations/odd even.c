#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    if(n & 1) printf("Odd\n");
    else puts("Even.");
    return 0;
}
