#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<int,int>
#define inf 100000000000
using namespace std;

int ara[200];
int main()
{
    int n;
    scanf("%d",&n);

    for(int i=0; i<n; i++)
    {
        scanf("%d",&ara[i]);
    }

    if(n==2 || n==1) { printf("YES\n"); return 0; }

    int left=-1,right=-1;
    for(int i=0; i<n-1; i++)
    {
        if(ara[i]==ara[i+1])
            left=i;
    }
    for(int i=n-1; i>=1; i--)
    {
        if(ara[i]==ara[i-1])
            right=i;
    }

    if(left==-1 ||  right==-1)
    {
        for(int i=1; i<n-1; i++)
        {
            if(ara[i-1]<ara[i] && ara[i]>ara[i+1])
            {
                left=right=i;
            }
        }
    }

    for(int i=left; i>=1; i--)
    {
        if(ara[i]<ara[i-1])
        {
            printf("NO\n");
            return 0;
        }
    }

    for(int i=right; i<=n-1; i++)
    {
        if(ara[i]<ara[i+1])
        {
            printf("NO\n");
            return 0;
        }
    }

    if(left==-1) printf("NO\n");
    else printf("YES\n");


    return 0;
}
