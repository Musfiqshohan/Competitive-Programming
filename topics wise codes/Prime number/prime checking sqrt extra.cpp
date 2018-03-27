#include<stdio.h>
#include<bits/stdc++.h>
bool  func(int n)
{
    if(n<2) return false;
    int i;
    for(i=2;i*i<=n;i++)
    {
        if(n%i==0) {return false; printf("Fuck %d\n",i); }
    }

    return true;
}
int main()
{   int n;

    scanf("%d",&n);

    printf("%s\n", func(n)?"true" : "false");

    return 0;
}

