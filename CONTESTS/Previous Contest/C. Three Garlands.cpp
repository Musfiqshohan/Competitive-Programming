#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define i64 long long
#define pii pair<int,int>
#define INF 1000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
#define rep(i,n) for(i64 i=0;i<n;i++)
using namespace std;


int main()
{
    int k1,k2,k3;
    scanf("%d %d %d",&k1,&k2,&k3);


    int two=0,four=0,three=0;
    if(k1==2) two++;
    if(k2==2) two++;
    if(k3==2) two++;


    if(k1==4) four++;
    if(k2==4) four++;
    if(k3==4) four++;


    if(k1==3) three++;
    if(k2==3) three++;
    if(k3==3) three++;

    if(two>=2)
        printf("YES\n");
    else if(two==1 && four>=2)
        printf("YES\n");
    else if(k1==1 || k2==1 || k3==1)
        printf("YES\n");
    else if(three==3)
        printf("YES\n");
    else printf("NO\n");

}
