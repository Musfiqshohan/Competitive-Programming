#include<stdio.h>



int mul(int a, int b)
{
    if(b==1) return a;

    b--;
    return a+ mul(a,b);
}

int main()
{

int a,b;
scanf("%d %d",&a,&b);
    printf("%d\n",mul(a,b));
    return 0;
}
