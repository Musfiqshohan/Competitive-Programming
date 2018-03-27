#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int a[1000009];
int f(int n,int i,int mx)
{
    int total=0;
    while(n%i==0)
    {
        n=n/i;
        total++;
    }
     mx=max(mx,total);

    return mx;

}
int main()
{
    int i,j,num;

    for(i=2;i<=1009;i++)
    {
        if(a[i]==0)
        {
            for(j=2; i*j <=1000009;j++)
            {
                num= i*j;
                a[num]= f(num,i, a[num]);

            }
        }
    }

    int t,test,n;
    scanf("%d",&test);
    for(t=0;t<test;t++)
    {
        scanf("%d",&n);
        if(a[n]==0) a[n]=1;

        printf("%d\n",a[n]);
    }


    return 0;
}
