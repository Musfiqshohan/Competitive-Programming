#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define pii pair<ll,ll>
#define ll long long
using namespace std;

int ara[1000];
int minim(int l, int r)
{
    int mn=100000;
    for(int i=l;i<=r;i++)
        mn=min(mn,ara[i]);

    return mn;
}

int main()
{
    int n;
    scanf("%d",&n);

    for(int i=0;i<n;i++)
        scanf("%d",&ara[i]);

    int total=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
            total+= minim(i,j);
    }

    printf("%d\n",total);
}
