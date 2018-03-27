#include<bits/stdc++.h>
using namespace std;
int main()
{
    string name;

    int t=0,test;
    scanf("%d",&test);
    while(t<test){


    int n;
    scanf("%d",&n);
    cin>>name;
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

