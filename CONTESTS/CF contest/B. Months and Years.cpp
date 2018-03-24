#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<int,int>
#define inf 100000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

bool check(int a[], int b[], int l)
{



    for(int i=0;i<=36-l;i++)
    {
        int cnt=0;
        for(int j=0;j<l;j++)
        {
            if(a[j]==b[i+j])
                cnt++;
            else break;
        }

        if(cnt==l)
            return true;

    }


    return false;
}


int main()
{
    int n;
    scanf("%d",&n);

    int ara1[]={ 31, 29, 31,30,31,30,31,31,30,31,30,31,
                31, 28, 31,30,31,30,31,31,30,31,30,31,
                31, 28, 31,30,31,30,31,31,30,31,30,31,
              };
    int ara2[]={ 31, 28, 31,30,31,30,31,31,30,31,30,31,
                31, 29, 31,30,31,30,31,31,30,31,30,31,
                31, 28, 31,30,31,30,31,31,30,31,30,31,
              };

    int ara3[]={ 31, 28, 31,30,31,30,31,31,30,31,30,31,
                31, 28, 31,30,31,30,31,31,30,31,30,31,
                31, 29, 31,30,31,30,31,31,30,31,30,31,
              };

    int ara[30];
    for(int i=0;i<n;i++)
        scanf("%d",&ara[i]);


    bool ret= check(ara,ara1,n) | check(ara,ara2,n) |check(ara,ara3,n) ;

    if(ret==true) printf("YES\n");
    else printf("NO\n");


    return 0;
}

