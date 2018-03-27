#include<stdio.h>

void rev(char str[],int i,int j)
{
    if(i>j) return;

    char temp= str[i];
    str[i]=str[j];
    str[j]=temp;
    rev(str, i+1, j-1);
}

int main()
{
    char str[100];
    scanf("%s",&str);
    rev(str,0,strlen(str)-1);
    printf("%s\n",str);
}
