#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll b[100000];
int main()
{
    int t,test;
    scanf("%d",&test);
    for(t=0;t<test;t++){
    ll n,i,cnt,root,j=0,m,mn=INT_MAX,flag;
    memset(b,0,sizeof(b));
    scanf("%lld",&n);

    m=n;
    n=abs(n);
    root=sqrt(n);
    for(i=2;i<=root;i++)
    {
        if(n%i==0)
        {
            cnt=0;
            while(n%i==0)
            {
                n/=i;
                cnt++;
            }

           b[j]=cnt;
           j++;
           if(cnt<mn) mn=cnt;
        }
        root=sqrt(n);
    }

    if(n!=1) { b[j]=1; j++; cnt=1; if(cnt<mn) mn=cnt; }

    flag=0;
    for(i=0;i<j  && flag==0;i++)
    {
        if(b[i]%mn!=0) flag=1;
    }

    printf("Case %d: ",t+1);

   if(flag==1) printf("1\n");
    else {

    if(m<0)
    {
        if(mn%2==0)
        {
            while(mn%2!=1) mn/=2;
            printf("%lld\n",mn);
        }
        else printf("%lld\n",mn);

    }
    else
    printf("%lld\n",mn);

    }
    }

    return 0;
}
