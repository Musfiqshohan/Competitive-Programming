#include<bits/stdc++.h>
using namespace std;
int a[200],b[200];
int main()
{
    int t,test;
    scanf("%d",&test);
    for(t=0;t<test;t++){

    int n,i,cnt=0,sum=0;

        cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=0;i<n;i++)
        cin>>b[i];

    printf("Case %d: ",t+1);
    for(i=0;i<n;i++)
    {
        sum^=(b[i]-a[i]-1);


    }


    if(sum==0) printf("black wins\n");
    else printf("white wins\n");

    }
    return 0;
}

