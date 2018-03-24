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


int main()
{
    int n;
    cin>>n;
    int two=0,one=0;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        if(x==1) one++;
        else two++;
    }

    int tot= min(two,one);


    if(one>two)
        one-=two,tot+= one/3;


    cout<<tot<<endl;
}
