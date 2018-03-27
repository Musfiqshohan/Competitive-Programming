#include<bits/stdc++.h>
using namespace std;

int f(int n, int i)
{
    int total=0;

    while(n/i>0)
    {
        total+= n/i;
        i*=i;
    }

    return total;
}
int main()
{
    int n,target,low,high,mid,i=0,num;
    scanf("%d %d",&n,&target);

    high=n;
    low=2;

    while(i<64)
    {
        mid= low+ (high-low)/2;

        num= f(n,mid);

        if(num<target)
        {
            high=mid;
        }
        else if( num >target)
        {
            low=mid;
        }
        else if(num==target)
        {
            low=mid;
        }

        i++;

    }

    printf("%d\n",mid);

    return 0;
}
