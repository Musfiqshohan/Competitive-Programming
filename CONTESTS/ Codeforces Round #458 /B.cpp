#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define i64 long long
#define pii pair<i64,i64>
#define inf 100000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
#define rep(i,n) for(i64 i=0;i<n;i++)
using namespace std;

int ara[100009], mark[100009];
int main()
{
    int n,x;
    scanf("%d",&n);

    int mx=INT_MIN;
    for(int i=0; i<n; i++)
    {


        scanf("%d",&ara[i]);

        mark[ara[i]]++;
    }
    int flag=0;

    for(int i=100005; i>=1; i--)
    {
        if(mark[i]%2)
            flag=1;
    }

    sort(ara,ara+n);


    if(flag==1) printf("Conan\n");
    else
        printf("Agasa\n");



}

