#include<stdio.h>
#include<bits/stdc++.h>
int main()
{
    int n;
    char A[100];
    scanf("%d",&n);
    itoa(n,A,10);
    printf("%s\n",A);
    itoa(n,A,2);
    printf("%s\n",A);
    itoa(n,A,16);
    printf("%s\n",A);
    return 0;
}
