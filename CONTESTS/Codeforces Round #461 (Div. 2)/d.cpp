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


vector<string>s;


int main()
{
    s.push_back("ssh");
    s.push_back("hs");
    s.push_back("s");
    s.push_back("hhhs");

    int cnt=0;
    while(cnt++<100) {
    bool val = next_permutation(s.begin(), s.end());
    if (val == false)
        cout << "No Word Possible" << endl;
    else
       {
           for(int i=0;i<s.size();i++)
            cout<<s[i];

            puts("");

       }

    }
    return 0;
}
