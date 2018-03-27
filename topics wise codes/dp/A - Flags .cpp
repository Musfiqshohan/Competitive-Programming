#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
long long  a[4][50];
long long n;
long long f(long long i, long long j, long long k)
{
    static int countx=0;
    long long total=0;

    if(k==n)
    {
        if(j==2) return 0;
        else {     return 1;   }
    }

    if(a[j][k]!=-1) return a[j][k];


    if(j==1)
    {
        total= f(1,2,k+1) + f(1,3,k+1);
    }
    else if(j==3)
    {
        total= f(3,2,k+1) + f(3,1,k+1);
    }
    else if(j==2)
    {

        if(i==1) total=f(2,3,k+1);
        else if(i==3) total= f(2,1,k+1);
    }


    a[j][k]=total;
    return  a[j][k];


}

int main()
{

    long long total=0;
    scanf("%lld",&n);
    memset(a,-1,sizeof(a));
    if(n==1) {printf("2\n"); }
    else{

    total= f(1,2,2) + f(1,3,2) + f(3,1,2) + f(3,2,2);
    printf("%lld \n",total);
    }


    return 0;
}
