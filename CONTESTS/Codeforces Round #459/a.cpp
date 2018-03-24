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

int ara[100009], isFib[100009];
int main()
{

    ara[1]=1;
    ara[2]=1;
    isFib[1]=1;
    for(int i=3; ;i++)
    {
        ara[i]=ara[i-1]+ara[i-2];
       // cout<<ara[i]<<endl;

        if(ara[i]>1009)
            break;
        isFib[ara[i]]=1;
    }

    int n;
    scanf("%d",&n);

    for(int i=1;i<=n;i++)
    {
        if(isFib[i]==1)
            printf("O");
        else printf("o");

    }

}

