#include<stdio.h>
#include<bits/stdc++.h>
int ara[12];
int n,m;
int f(int j, int i, int countx)
{
    printf("j=%d i=%d cnt=%d\n",j,i,countx);
    int total1=0, total2=0;
    if(countx==m)
    {
        if(abs(ara[i]-ara[j])>2)
            return 0;

        printf("geot =%d %d\n",ara[j],ara[i]);
        return 1;
    }

    if(i==n) return 0;

    if(abs(ara[i]-ara[j])<=2)
    {
        printf("here =%d %d\n",ara[i],ara[j]);
        total1= f(i, i+1, countx+1);


    }

     total2= f(j, i+1, countx);

    return total1+total2;

}
int main()
{
    int i,total=0;
    scanf("%d %d",&n,&m);

    for(i=0; i<n; i++)
        scanf("%d",&ara[i]);

    for(i=0; i<n-1; i++)
    {
        total+=  f(i,i+1,2);
        printf("Fuck\n\n");
        if(i<n-2) total+= f(i,i+2,2);
        printf("Fuck2\n\n");
    }

    printf("%d\n",total);

    return 0;
}
