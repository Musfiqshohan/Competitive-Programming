#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define inf 1000099
using namespace std;

int findd(int )

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);

    for(int i=0;i<n;i++)
        scanf("%d",&bulls[i]);

    sort(bulls+0,bulls+n, greater<int>());

    for(int i=0;i<m;i++)
        scanf("%d",&cows[i]);
    sort(cows+0,cows+m, greater<int>());

    int last=findd(bulls[0]);

    int dif=0;
    for(int i=0;i<n;i++)
    {
        dif+=abs(bulls[i]-cows[last]);
        last++;
    }


    cout<<dif<<endl;


}
