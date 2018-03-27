#include<stdio.h>

int mark[100009];
int ara[100009];
int main()
{
    int n,i,j,a,b;
    scanf("%d %d",&a,&b);


    mark[0]=1;
    mark[1]=1;
    mark[2]=0;
    for(i=4;i<=b;i+=2) mark[i]=1;

    int root=sqrt(b);
    for(i=3;i<=root;i++)
    {
        if(mark[i]==0)
        {
            for(j=2;i*j<=b;j++)
                mark[i*j]=1;
        }
    }


    j=0;
    for(i=0;i<=root;i++)
    {
        if(mark[i]==0) {ara[j]=i; j++; }
    }


   // for(i=0;i<j;i++) printf("%d\n",ara[i]);

   for(i=0;i<j;i++)
    {
        int div=a/ara[i];
        for(i=div;i*ara[i]<=b;i++)
            mark[i*ara[i]]=1;
    }

    for(i=a;i<=b;i++)
    {
        if(mark[i]==0) printf("%d\n",i);
    }

    return 0;
}
