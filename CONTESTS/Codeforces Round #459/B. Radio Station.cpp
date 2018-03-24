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

map<string,string>mp;
int main()
{

    string str1,str2;
    int n,m;
    cin>>n>>m;
    getchar();

    for(int i=0;i<n;i++)
    {
        cin>>str1>>str2;
       // cout<<str2<<endl;
        mp[str2]=str1;
    }

    for(int i=0;i<m;i++)
    {
        cin>>str1>>str2;
        string temp;
        for(int i=0;i<str2.size()-1;i++) temp+=str2[i];
      //  cout<<temp<<endl;
        cout<<str1<<" "<<str2<<" #"<<mp[temp]<<endl;
    }


}
