#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int cost[1009], weight[1009];

int a[1009][1009];


void seta(int ara[1009][1009])
{   int i,j;
    for(i=0;i<1009;i++)
    {
        for(j=0;j<1009;j++) a[i][j]=-1;
    }
}
int f(int i, int w,int cap,int n)
{


    int profit1=0,profit2=0;
    if(i==n)  return 0;

    if(a[i][w]!=-1) return a[i][w];

    if(w+ weight[i] <= cap)
    profit1= cost[i]+ f(i+1, w + weight[i],cap,n);
    else profit1=0;

    profit2= f(i+1,w,cap,n);

    a[i][w]= max(profit1,profit2);
    return a[i][w];

}
int main()
{

    int test;
    scanf("%d",&test);
    while(test--){
    int i,n,j,m,cap,total=0;


    seta(a);

    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d %d",&cost[i],&weight[i]);

    }


    scanf("%d",&m);

    for(j=0;j<m;j++)
    {
    scanf("%d",&cap);


    total+= f(0,0,cap,n);
      seta(a);
    }

    printf("%d\n",total);

    }
    return 0;
}
