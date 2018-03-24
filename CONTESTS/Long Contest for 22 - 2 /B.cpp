#include<bits/stdc++.h>
#define ll long long
using namespace std;


int main()
{
    int k;
    cin>>k;

    if(k>36)
        printf("-1\n");
    else
    {
        int div=k/2;
        for(int i=0;i<div;i++)
            printf("8");
        if(k%2==1)
            printf("4");
    }

    puts("");
    return 0;
}
