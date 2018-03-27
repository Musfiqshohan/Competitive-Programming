#include<bits/stdc++.h>
#define ll long long
#define ui unsigned int
using namespace std;
int MX=100009000;

int prime[6761455], a[3280000];
bool check(int N, int pos)
{
    return (bool)(N&(1<<pos));
}
int setx(int N, int pos)
{
    return N= N|(1<<pos);
}
void sieve()
{
    int i,j,root;
    root=sqrt(MX);
    for(i=3; i<=root; i+=2)
    {
        if(check(a[i>>5], i&31 )==false)
        {
            for(j=i*i; j<=MX; j+= 2*i)
                a[j>>5]= setx(a[j>>5], j&31);
        }

    }

    prime[0]=2;
    j=1;
    for(i=3;i<=MX;i+=2)
    {
         if(check(a[i>>5], i&31 )==false)
         {
             prime[j]= i;
             j++;
         }

    }

}

int main()
{
    sieve();
    int t,test;
    scanf("%d",&test);
    for(t=0;t<test;t++){
    ui i;
    ui total=1,n,m,k;

    scanf("%u",&n);
    k=n;
    for(i=0;  k/prime[i]>0; i++)
    {
         m=n;

        while(m)
        {

            m=m/prime[i];
            if(m)
            total*= prime[i];

        }
    }

    printf("Case %d: %u\n",t+1,total);

    }
    return 0;
}
