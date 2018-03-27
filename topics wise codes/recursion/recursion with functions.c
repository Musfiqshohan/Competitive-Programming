#include<stdio.h>

void mul(int num)
{
    printf("after subtracting =%d\n",num);
    num*=10;
    add(num);
}


void sub(int num)
{
    printf("after adding =%d\n",num);
    num-=5;
    mul(num);
}

void add(int num)
{
     printf("after multiplication =%d\n",num);

    static int count=0;
    if(count==5) return;

    num+=10;

    count++;
    sub(num);

}


int main()
{
    add(10);
    return 0;
}
