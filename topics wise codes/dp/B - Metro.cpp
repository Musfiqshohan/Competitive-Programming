#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int n,m;
int ara[1011][1011];
double a[1011][1011];
bool b[1011][1011];
double corner;
double f(int i,int j)
{
    double total1=-1,total2=-1,total3= -1,x,y;
    double total=100000000000000000;

    if(i==n && j==m) return 0;
    else if(i==n+1 || j==m+1) return -1;

    if(b[i][j]==true) return a[i][j];

    x=  f(i,j+1);
    if(x!=-1)
    {
        total1=100+ x;
        total= min( total, total1);
    }

    y=f(i+1,j);

    if(y!=-1)
    {
        total2= 100 + y;
        total= min( total, total2);
    }




    if(ara[i+1][j+1]==1)
    {
        total3= corner + f(i+1, j+1);
        total= min( total, total3);
    }



    a[i][j]= total;
    b[i][j]= true;

    return a[i][j];

}
int main()
{

    scanf("%d %d",&n,&m);

    int k,i,x,y;
    scanf("%d",&k);

    for(i=0; i<k; i++)
    {
        scanf("%d %d",&x,&y);
        ara[x][y]=1;
    }


    corner= sqrt( 100*100*2);
    printf("%.0f\n", f(0,0));

    return 0;
}
