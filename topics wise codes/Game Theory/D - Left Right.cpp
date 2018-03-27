#include<bits/stdc++.h>
using namespace std;
int a[205];
int main()
{
    int t,test;
    scanf("%d",&test);
    for(t=0;t<test;t++){
    int k,sum=0,i;
    cin>>k;

    for(i=0;i<2*k;i++) cin>>a[i];

    for(i=0;i<2*k;i+=2)
    {
        sum^= (a[i+1]-a[i]-1);
    }

    printf("Case %d: ",t+1);
    if(sum==0) printf("Bob\n");
    else printf("Alice\n");

    }
    return 0;
}
