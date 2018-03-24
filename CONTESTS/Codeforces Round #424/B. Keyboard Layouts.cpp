#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<int,int>
#define inf 100000000000
using namespace std;

map<char,char>mp;
int main()
{
    string s1,s2,str;

    cin>>s1>>s2>>str;
   // cout<<s1<<" "<<s2<<" "<<str<<endl;

    for(int i=0;i<s1.length();i++)
    {
        mp[s1[i]]=s2[i];
        mp[s1[i]-32]=s2[i]-32;
    }

    for(int i=0;i<str.length();i++)
    {
        if(mp.find(str[i])!=mp.end()) //not till now
            printf("%c",mp[str[i]]);
        else printf("%c",str[i]);

    }
    puts("");

    return 0;
}
