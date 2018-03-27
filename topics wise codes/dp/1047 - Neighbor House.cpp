#include<bits/stdc++.h>
using namespace std;
int ara[22][3];
int a[22][3];
int n;
int f(int pos,  int color)
{   int total=0,num;
    if(pos==n) return 0;

    if(a[pos][color]!=-1) return a[pos][color];


    total= ara[pos][color] ;
    if(color==0)
        num= min( f( pos+1,1), f( pos+1,2) );
    else if(color==1)
        num= min( f( pos+1 ,0), f(pos+1,2) );
    else if(color==2)
        num= min( f(pos+1,0) , f(pos+1,1) );

    total+= num;

    a[pos][color]=total;
    return a[pos][color];
}
int main()
{
    int t,test;
    scanf("%d",&test);
    for(t=0;t<test;t++) {
    int i,j;
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        for(j=0;j<3;j++)
            scanf("%d",&ara[i][j]);
    }

    memset(a,-1,sizeof(a));
    printf("Case %d: %d\n", t+1,min( min( f(0, 0) , f(0, 1)) , f(0,2) ) );

    }
    return 0;
}
