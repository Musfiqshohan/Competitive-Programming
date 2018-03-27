#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    return b ==0 ? a : gcd(b,a%b);
}

void fact(int n)
{
    int root= sqrt(n);

    int i,cnt;
    for(i=2;i<=root;i++)
    {
        if(n%i==0)
        {   cnt=0;
            while(n%i==0)
            {
                n=n/i;
                cnt++;
            }
            //printf("%d^%d * ",i,cnt);
        }
    }
  //  if(n!=1) printf("%d^1",n);
    printf("     ");
}

int main()
{
    int n,i,j,cnt=0;
    scanf("%d",&n);

    for(i=1;i<=n;i++)
    {
        for(j=i;j<=n;j++)
        {
            int l = (i*j)/gcd(i,j);
            if(l==n){ printf("%d %d \n",i,j);
            cnt++;
            // fact(i);
            //  fact(j);
               // printf("\n");

        }
        }
    }
    printf("%d\n",cnt);

}

