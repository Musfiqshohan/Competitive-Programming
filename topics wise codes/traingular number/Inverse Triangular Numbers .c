#include<stdio.h>
int main()
{   long long int n;
    while(scanf("%lld",&n)!=EOF)
    {
        double sum=sqrt(1+8*n);
        long long int sum1=sum;
        sum-=1;
        sum/=2;

        sum1-=1;
        sum1/=2;
        if(sum1!=sum) printf("bad");
        else
        {
            printf("%lld",sum1);
        }
        printf("\n");

    }
}
