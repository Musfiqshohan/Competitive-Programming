#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<ll,ll>
#define inf 100000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
using namespace std;

string str;
int ara[1000];
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    getchar();


    cin>>str;

    for(int i=0;i<str.length();i++)
    {
        ara[str[i]-'a']++;

        if(ara[str[i]-'a']>k)
        {
            printf("NO\n");
            return 0;
        }
    }

    printf("YES\n");
    return 0;
}
