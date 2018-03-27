#include<stdio.h>
int count=0;
int  ara[100];
int fib(int n)
{

    count++;
    if(ara[n]!=0) return ara[n];
    else
        ara[n]=fib(n-1)+fib(n-2);

    return ara[n];

}


int main()
{
    int n;
    char s[3];

    ara[0]=0;
    ara[1]=1;
    ara[2]=1;
    scanf("%d",&n);

    if(n==1) strcpy(s,"st");
    else if(n==2) strcpy(s,"nd");
    else if(n==3) strcpy(s,"rd");
    printf("%d%s term of fibonacci is %d",n,s,fib(n));


    printf("\nthe function is called %d times\n",count);
}
