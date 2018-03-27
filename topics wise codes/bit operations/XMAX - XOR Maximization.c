#include<stdio.h>
unsigned long long a[100009];
int main()
{
    unsigned long long n,i,max=0,sum=0;
    scanf("%llu",&n);
    for(i=0;i<n;i++) scanf("%llu",&a[i]);

    for(i=0;i<n;i++)
    {
        sum=sum^a[i];
        if(sum>max) max=sum;
    }

    printf("%llu\n",max);
    return 0;
}
