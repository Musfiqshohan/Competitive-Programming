#include<stdio.h>
int ara[500];
int can_win(int n)
{

    if(ara[n]!=-1) return ara[n];
    if(n==0 || n==1) {    return 0;  }
    if(can_win(n-2)==0 || can_win(n-3)==0 || can_win(n-5)==0)
       {    ara[n]=1;  return ara[n];    }

        ara[n]=0;
        return ara[n];
}
int main()
{
    int i;
    for(i=0;i<=500;i++) ara[i]=-1;
    ara[0]=0;
    ara[1]=0;

    int n;
    scanf("%d",&n);
    if(can_win(n)==1)
    printf("Yes\n");
    else printf("No\n");

    return 0;
}
