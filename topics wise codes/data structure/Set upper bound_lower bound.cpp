#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<int,int>
#define inf 100000000000
using namespace std;

int main()
{
    set<int>myset;
    set<int>::iterator itlow,itup;

    for(int i=1;i<=10;i++) myset.insert(i*10);

  //  itlow= myset.lower_bound(35);
    itup= myset.upper_bound(30);

    itup--;
   // cout<<"low=" <<(*itlow)<<endl;
    cout<<"up=" <<(*itup)<<endl;

    return 0;
}
