#include<bits/stdc++.h>
using namespace std;



int main()
{
    int n,divisors=1,cnt=0,i;
    scanf("%d",&n);

    int root= sqrt(n);

    for(i=2;i<=root;i++)
    {
        if(n%i==0)
        {
            cnt=1;
            while(n%i==0)
                {n=n/i;
                cnt++;
                }

        }
        divisors*=cnt;
        root= sqrt(n);
    }

    if(n!=1) divisors*=2;

    printf("%d\n",divisors);
    return 0;
}
