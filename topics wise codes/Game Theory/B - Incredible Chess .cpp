
#This is a wrong solution. Question defined a new kind of chess.
#include<bits/stdc++.h>
using namespace std;
int a[200],b[200];
int main()
{
    int t,test;
    scanf("%d",&test);
    for(t=0;t<test;t++){
    int n,i,cnt=0;

        cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=0;i<n;i++)
        cin>>b[i];

    printf("Case %d: ",t+1);
    for(i=0;i<n;i++)
    {
        if(b[i]-a[i]>1)
            break;

    }
    if(i==n) {printf("black wins\n"); continue; }

    for(i=0;i<n;i++)
    {
        if(b[i]-a[i]==2)
            cnt++;

    }

    if(cnt%2==0) printf("white wins\n");
    else printf("black wins\n");


    }
    return 0;
}
