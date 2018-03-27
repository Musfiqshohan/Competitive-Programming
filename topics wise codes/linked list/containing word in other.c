#include<stdio.h>


int check(char str1[],char str2[],int l1,int l2,int i,int j,int count)
{
    if(l1>l2) return 0;
    if(i==l1 || j==l2) return 0;

    if(str1[i]==str2[j] && str1[i] && str2[j])
        {

            count++;  i++;
          }


    if(count==l1) return 1;

    j++;

    check(str1,str2,l1,l2,i,j,count);


}



int main()
{
    char str1[100],str2[100];

    scanf("%s %s",&str1,&str2);


    if(check(str1,str2, strlen(str1),strlen(str2),0,0,0)) printf("YES\n");
    else printf("NO\n");

}
