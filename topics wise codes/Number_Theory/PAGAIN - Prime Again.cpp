#include<bits/stdc++.h>

bool isPrime(int n)
{
    if(n==2) return true;
    if(n%2==0) return false;

    int i,root;
    root=sqrt(n);

    for(i=2;i<=root;i++)
        if(n%i==0) return false;

    return true;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {   int n;
        scanf("%d",&n);
        if(n & 1== 1)
            n-=2;
        else
            n--;


        while(isPrime(n)!=true)
            n-=2;



        printf("%d\n",n);
    }

    return 0;
}
