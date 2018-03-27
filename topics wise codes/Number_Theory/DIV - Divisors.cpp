#include<stdio.h>
int MX=2000009;

int b[2009099],div[2030009];
void sieve()
{
    int i,j;
    for(i=1;i<=MX;i++)
    {
        for(j=i; j<=MX ; j+=i)
            div[j]++;
    }

    for(i=2; i<= 2009;i++)
    {
        if(div[i]==2)
        {
            for(j=i; j<=MX ; j+=i)
            {
                if(j==175) printf("%d %d\n",i,div[j]);
                if( div[ div[j]/i ]==2 &&  div[j]/i!=i && div[j]%i==0 )
                    div[j]=1;
                 if(j==175) printf("%d \n",div[j]);
            }
        }
    }

    j=1;
    for(i=2;i<=MX;i++)
    if(div[i]==1) { b[j]=i; j++; }

}
int main()
{
    sieve();
    int i;
    for(i=1; b[i]<=250  ;i++) {   printf("%d %d\n",i, b[i]);     }

}
