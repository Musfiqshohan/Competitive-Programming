#include<bits/stdc++.h>
using namespace std;
double a[1000009];

long long MX= 100000000;
void bitmask()
{
    double sum=0;
    long long i,j=0;
    for(i=1;i<=MX;i++)
    {
        sum+= 1/(i*1.0);
        if(i%1000==0)
        {
            a[j]=sum;
            j++;
        }
    }
}

long long H( int n ) {
    long long res = 0;
    for( int i = 1; i <= n; i++ )
        res = res + n / i;
    return res;
}

int main()
{
    bitmask();

    int t,test;
    scanf("%d",&test);
    for(t=0;t<test;t++){

    long long  n,i,index;
    double  total=0;
    scanf("%lld",&n);

    index= n/1000;

    if(index>0)
    total = a[index-1];



    for(i= index*1000+1;  i<=n; i++)
            total+= 1/(i*1.0);



    printf("Case %d: %f\n",t+1,(total));

    printf("%lld\n", H(n));

    }

    return 0;
}

