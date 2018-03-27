#include<bits/stdc++.h>
int num_div[1010009];
int a[14][1020009];

void sieve()
{   int i,j;
    for(i=2;i<=1000009;i++)
    {
        if(num_div[i]==0){
        for(j=1; i*j<=1000009;j++)
        {
            num_div[i*j]++;
        }
        }
    }


    for(i=1;i<=10; i++)
    {
        for(j=2;j<=1000009;j++)
        {
            a[i][j]= a[i][j-1] + (bool)(num_div[j]==i);
        }
    }

}
int main()
{
    sieve();
    int t;
    scanf("%d",&t);
    while(t--) {
    int n,a1,b1;
    scanf("%d %d %d",&a1,&b1,&n);


    printf("%d\n", a[n][b1] - a[n][a1-1]  + (bool)(n==0 && a1==1)  );
    }

    return 0;

}
