#include<stdio.h>

int mx;
int ara[70];
void f(int n)
{
    int cnt=0;
    while(n)
    {
        if(n%2==1) ara[cnt++]++;



        n/=2;
    }

    if(cnt>mx)
        mx=cnt;

}

int main()
{
    int x,n;
    while(scanf("%d",&n) && n!=0){

    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);

        f(x);
    }

    int i;
    for( i=mx;i>=0;i--)
    {
        if(ara[i]%2==1)
            break;
    }


    printf("%d\n",ara[i]);
    memset(ara,0,sizeof ara);

    }



}