#include<stdio.h>
char name[20];
int main()
{
    int t=0,test;
    scanf("%d",&test);
    while(t<test){
    int n;
    scanf("%d %s",&n,&name);
    printf("Case %d: ",++t);
    if(name=="Alice")
    {
        if(n%3==1) printf("Bob\n");
        else printf("Alice\n");
    }
    else
    {
        if(n%3==0)  printf("Alice\n");
        else printf("Bob\n");

    }


    }
    return 0;
}
