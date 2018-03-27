#include<stdio.h>

void rev(char str[][100],int i,int j)
{
    if(i>j) return;
    char temp[100];
    strcpy(temp,str[i]);
    strcpy(str[i],str[j]);
    strcpy(str[j],temp);

    rev(str, i+1, j-1);

}


int main()
{
    int i;
    char str [100][100];
    for(i=0;i<3;i++)
    scanf("%s",&str[i]);

    rev(str,0,2);

    for(i=0;i<3;i++) printf("%s ",str[i]);
}
