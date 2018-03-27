#include<stdio.h>
//#include<bits/stdc++.h>
int main()
{
    int rem=0,sum=0,num,i,x;
    char A[100];
    gets(A);

    scanf("%d",&num);
    int l=strlen(A);

    strrev(A);

    for(i=0;i<l  ;i++)
    {
        x= A[i]-'0';
        sum=x*num+rem;
        x=sum%10;
        rem=sum/10;
        A[i]=x+'0';
    }
    while(rem!=0)
    {
        x=rem%10;
        A[i]=x+'0';
        i++;
        rem=rem/10;
    }
    strrev(A);

    printf("%s\n",A);

    return 0;
}

