#include<stdio.h>

int a[1000][1000];
//int a[1000];
int main()
{
    int n,m,i,j,target;

    scanf("%d %d",&n,&m);

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }

    //scanf("%d",&n);

    //for(i=0;i<n;i++) scanf("%d",&a[i]);



    scanf("%d",&target);
    int low=0,high=m,mid;


    int count=0;
    while(count<40)
    {
        count++;
        mid= low+ (high-low)/2;

        if(a[0][mid]<target)
            low=mid;
        else if(a[0][mid]>target)
            high=mid;
        else if(a[0][mid]==target) break;

        printf("%d %d %d %d\n",a[0][low], a[0][mid], a[0][high], target);


    }

    if(low==high) mid=low;

    int x=mid;

    printf("1st fucking %d = %d\n",mid,a[0][mid]);
    //second part from here
    low=0,high=n,mid;

    while(low<=high)
    {
        mid= low+ (high-low)/2;

        if(a[x][mid]<target)
            low=mid+1;
        else if(a[x][mid]>target)
            high=mid-1;
        else if(a[x][mid]==target) break;
    }

    if(low>high) printf("Theres no such thing\n");
    else{
    int y=mid;
    printf("Yes its on %d %d index\n",x,y);
    }

    return 0;
}

/*
3 3
1 3 5
7 9 11
13 15 17
9
*/
