#include<stdio.h>
int main()
{
    int t,test;
    scanf("%d",&test);

    for(t=0;t<test;t++){

    char str[100];
    memset(str,0,sizeof(str));
    int i,total=0,count=0;
    scanf("%s",&str);


    for(i=0;str[i] ; i++ )
    {
        count=0;
        while(str[i]=='O'  )
            {
                 count++;
                 total+=count;

                i++;
            }

    }

    printf("%d\n",total);
    }

    return 0;
}
