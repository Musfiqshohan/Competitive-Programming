#include<stdio.h>

int fact(int n)
{
    static count=0;
    if(n==0)
    {    printf("fact function is called %d times \n",count);
        return 1;

    }

    count++;
    return n*fact(n-1);



}



int main()
{
    int n;
    scanf("%d",&n);
    if(n>=0) printf("%d\n",fact(n));
    else printf("Fuck yourself\n");


}
