#include<stdio.h>
#include<stdbool.h>

bool mark[1000000];

void sieve()
{
    int i,j;
    mark[1]=true;

    for(i=4;i<=1000000;i+=2)
        mark[i]=true;

    for(i=3;i<=10;i=i+2)
    {
        if(mark[i]==false)
        {
        for(j=i*i;j<=100;j=j+i)
        {
            mark[j]=true;
        }

        }
    }

}

bool isPrime(int n)
{
    //if(mark[n]==false) printf("Prime\n");
    if(n<2) return false;
    if(n==2) return true;
    if(n%2==0) return false;
    return mark[n]== false;
}



int main()
{
    int n;
    sieve();
    while(1){
    scanf("%d",&n);
    printf("%s\n", isPrime(n)? "true" : "false");
    }
    return 0;
}
