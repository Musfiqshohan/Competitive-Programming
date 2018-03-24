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


map<char, string>mp;
void process()
{
    mp['A']="2";
    mp['B']="2";
    mp['C']="2";

    mp['D']="3";
    mp['E']="3";
    mp['F']="3";

    mp['G']="4";
    mp['H']="4";
    mp['I']="4";

    mp['J']="5";
    mp['K']="5";
    mp['L']="5";

    mp['M']="6";
    mp['N']="6";
    mp['O']="6";

    mp['P']="7";
    mp['Q']="7";
    mp['R']="7";
    mp['S']="7";

    mp['T']="8";
    mp['U']="8";
    mp['V']="8";

    mp['W']="9";
    mp['X']="9";
    mp['Y']="9";
    mp['Z']="9";

}


bool f(string temp)
{
    for(int i=0,j=temp.size()-1;i<j;i++,j--)
    {
        if(temp[i]!=temp[j])
            return false;
    }

    return true;
}


int main()
{

  //  cout<<f("abba")<<endl;
    process();

    int tt;
    cin>>tt;
    //getchar();
    while(tt--)
    {
        string str;
        cin>>str;

        string temp;
        for(int i=0;i<str.size();i++)
        {
            char ch=str[i];
            if(ch>90) ch-=32;
        //    cout<<ch<<endl;
            temp+=mp[ch];
        }

        //cout<<temp<<endl;

        if(f(temp)==false)printf("NO\n");
        else printf("YES\n");
    }
}
