#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<int,int>
#define inf 100000000000
using namespace std;

vector<int>v;
int main()
{
    int n,x,y;
    scanf("%d",&n);

    for(int i=0; i<n; i++)
    {
        scanf("%d",&x);
        v.push_back(x);
    }

    vector<int>::iterator it1,it2;


    scanf("%d",&x);
    it1= lower_bound(v.begin(), v.end(), x);
    cout<<it1-v.begin()<<endl;  /// use -1 for strictly small

//
//    scanf("%d",&y);
//    it2= upper_bound(v.begin(), v.end(), y);
//    cout<<it2-v.begin()-1<<endl;


    return 0;
}
