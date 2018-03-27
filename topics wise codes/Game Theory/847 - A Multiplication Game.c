#include<stdio.h>
int ara[400000000];
int win(int n)
{
    if(ara[n]!=-1) return ara[n];
    int i;
    if(n>=1 && n<=9) return 1;

    for(i=2;i<=9;i++)
    {
        if(win (n/i)==0) { ara[n]=1; return 1;  }
    }

    ara[n]=0;
    return 0;
}
int main()
{
    int n,i;
    memset(ara,-1,sizeof(ara));


    for(i=1;i<=9;i++) ara[i]=1;

    scanf("%d",&n);
    if(win(n)==1) printf("Stan wins.\n");
    else printf("Ollie wins.\n");

    return 0;
}
