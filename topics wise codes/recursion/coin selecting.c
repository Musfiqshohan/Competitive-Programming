#include<stdio.h>
int p1,p2,fail,count;
void stack(int n,int flag)
{
    if(n==0)
    {
        if(flag==1) p1++;
        if(flag==2) p2++;

        return;
    }

    else if(n<0)
    {
        fail++;
        return;
    }

    if(count%2==0) flag=1;
    if(count%2==1) flag=2;
    count++;

    if(n-1==0) {stack(n-1,flag); return; }
    else if(n-2==0) {stack(n-2,flag);  return; }
    else if(n-4==0) {stack(n-4,flag);  return;  }
    else{

    stack(n-1,flag);
    stack(n-2,flag);
    stack(n-4,flag);
    }

}


int main()
{
        int n;
        scanf("%d",&n);

        stack(n,0);
        printf("%d %d %d\n",p1,p2,fail);
}
