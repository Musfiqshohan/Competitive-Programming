#include<stdio.h>

bool func(int n)
{
    if(n<2) return false;
    int i;
    for(i=2;i<=sqrt(n+1);i++)
    {
        if(n%i==0) return false;
    }

    return true;
}
int main()
{   int n;
    printf("%B\n",func(scanf("%d",&n)));/// vul
    return 0;
}
