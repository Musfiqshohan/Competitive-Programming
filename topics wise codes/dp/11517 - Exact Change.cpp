#include<bits/stdc++.h>
using namespace std;

int f(int i,int amount)
{
    int total= 100000000;
    if(amount>= m) return 0;
    if(i==n) return -1;


    x=f(i+1, amount+ cost[i]);

    if(x!=-1)
    {
        total1= cost[i] +x;
        total= min( total, total1);
    }


    y= f(i+1, amount);
    if(total2!=-1)
    {
        total2=y;
        total= min(total, total2);
    }

    return total;
}
int main()
{
    int n,m;
    scanf("%d %d",&m,&n);

    for(i=0; i<n; i++) scanf("%d",&ara[i]);

    printf("%d",f(0,0));

    return 0;
}
