#include<stdio.h>
void recurse()
{
    static count=1;
    if(count>5) return;

    printf("%d\n",count);
    count=count+1;
    recurse();
    count--;
    printf("%d\n",count);

    return;

}

int main()
{
    recurse();
    return 0;
}
