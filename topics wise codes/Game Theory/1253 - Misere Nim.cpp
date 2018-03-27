#include<bits/stdc++.h>
using namespace std;
int a[200];
int main()
{
    int t=0,test;
    scanf("%d",&test);
    while(t<test){
    int k,i;
    int xsum=0,cnt=0;
    scanf("%d",&k);
    for(i=0;i<k;i++)
        {
            scanf("%d",&a[i]);
            xsum^=a[i];
            if(a[i]==1) cnt++;
        }

    printf("Case %d: ",++t);
    if(cnt==k)
    {
        if(k%2==1) printf("Bob\n");
        else printf("Alice\n");
    }
    else
    {
        if(xsum==0) printf("Bob\n");
        else printf("Alice\n");
    }


    }
    return 0;
}
