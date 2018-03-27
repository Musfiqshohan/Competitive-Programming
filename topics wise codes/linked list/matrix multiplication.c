#include<stdio.h>


void multiply(int A[][10], int B[][10], int C[][10],int n,int r1,int c1,int r2,int c2, int sum)
{

    if(r2==n)
    {
        C[r1][c2]=sum;
        c1=0;
        r2=0;
        c2++;
        sum=0;
    }

    if(c2==n)
    {
        r1++;
        c2=0;
    }

    if(r1==n)
        return;

    sum+=A[r1][c1]*B[r2][c2];
    c1++;
    r2++;

    multiply(A,B,C,n,r1,c1,r2,c2,sum);


}


int main()
{
    int A[10][10],B[10][10],C[10][10];
    int i,n,j;

    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        scanf("%d",&A[i][j]);

    }

     for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        scanf("%d",&B[i][j]);

    }

    multiply(A,B,C,n,0,0,0,0,0);

     for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        printf("%d ",C[i][j]);

        puts(" ");

    }

    return 0;
}
