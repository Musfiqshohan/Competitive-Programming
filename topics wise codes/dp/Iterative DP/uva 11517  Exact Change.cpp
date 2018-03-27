#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<int,int>
#define inf 100000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
#define rep(i,a,n) for(int i=a;i<n;i++)
#define mod 1000000000;
using namespace std;

int coins[105];
int main()
{
    int n,money;
    scanf("%d",&money);

    cin>>n;
    rep(i,0,n)
        cin>>coins[i];



    int sum1,sum2,cnt1,cnt2;
    sum1=sum2=0;
    cnt1=cnt2=INT_MAX;

    for(int i=0; i<n; i++)
    {

        ///not taken now

        if(sum2<sum1)
        {
            sum1=sum2;
            cnt1=cnt2;
        }
        else if(sum1==sum2)
            cnt1= min(cnt1,cnt2);


        ///taken


        dif1= money- (sum1+coins[i]);  /// taken in previous
        dif2= money- (sum2+coins[i]);

        if(dif1<dif2)
        {
            sum2=sum1+coins[i];
            cnt2=cnt1+1;
        }
        else if(dif1>dif2)
        {
            sum2=sum2+coins[i];
            cnt2++;
        }
        else
        {
            sum2=sum2+coins[i];
            cnt2= min(cnt1,cnt2);
            cnt2++;
        }

    }


    if(sum1<sum2) printf("%d %d\n",sum1,cnt1);
    else if(sum2<sum1) printf("%d %d\n",sum2,cnt2);
    else printf("%d %d\n",sum1,min(cnt1,cnt2));


    return 0;
}
