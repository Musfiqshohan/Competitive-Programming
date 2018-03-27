#include<bits/stdc++.h>
using namespace std;


int check(char str[],int i, int j,int flag1,int flag2,int flag3)
{
    if(i==j+1) return 0;

    if(str[i]=='e') flag1=1;
    if(str[i]=='l') flag2=1;
    if(str[i]=='f') flag3=1;

    if(flag1==1 && flag2==1 && flag3==1) return 1;
    check(str,i+1,j,flag1,flag2,flag3);
}


int main()
{
    int flag1=0,flag2=0,flag3=0;
    char str[100];
    scanf("%s",&str);

    if(check(str,0,strlen(str)-1,flag1,flag2,flag3)) printf("Yes\n");
    else printf("No\n");


}
