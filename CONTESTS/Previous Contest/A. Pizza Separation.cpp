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

int ara[400];

int calculate(int i, int j, int n)
{
    int s1=0,s2=0;
    for(int k=i;k<=j;k++)
        s1+=ara[k];
    for(int k=1;k<i;k++)
        s2+=ara[k];

    for(int k=j+1;k<=n;k++)
        s2+=ara[k];

    return abs(s2-s1);
}
int main()
{
    int n;
    scanf("%d",&n);

    for(int i=1; i<=n; i++)
    {
        scanf("%d",&ara[i]);
    }


    int mn= INT_MAX;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int dif= calculate(i,j,n);
             mn= min(mn,dif);

        }

    }

    cout<<mn<<endl;



}
