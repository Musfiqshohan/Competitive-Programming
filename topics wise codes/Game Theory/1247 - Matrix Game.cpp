#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[60][60];
int main()
{
    int t=0,test;
    scanf("%d",&test);
    while(t<test){
    int n,m,i,j ;
    scanf("%d %d",&m,&n);

    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            scanf("%lld",&a[i][j]);
    }

    printf("Case %d: ",++t);
    ll xsum=0;
    for(i=0;i<m;i++)
    {

        ll t1=0;
        for(j=0;j<n;j++)
        {
            t1+=a[i][j];
        }

        xsum^=t1;
    }

    if(xsum==0) printf("Bob\n");
    else printf("Alice\n");

    }
    return 0;
}
