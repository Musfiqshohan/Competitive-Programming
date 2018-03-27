#include<stdio.h>
int main()
{
    int n,x;
    scanf("%d %d",&n,&x);

    n=n>>x;
    printf("%d\n",n);
    return 0;
}
