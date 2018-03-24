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


string status;

struct info
{
    char ch,man,pre;
};

vector<info>vec;

bool cmp(info a, info b)
{
    return a.ch>b.ch;
}


void f(string st, string en)
{
    int flag=0;
    for(int i=0;i<en.size();i++)
    {
        for(int j=0;j<st.size();j++)
        {
            if(st[i]==en[j])
            {
                if(status[i]=='U' && i>=j)
                flag=1;

                if(status[i]=='D' && i<=j)
                    flag=1;
            }

        }
    }

    if(flag==0)
        cout<<st<<endl;

}



int main()
{


    string s;
    cin>>status;
    s="ABCD";
    string t=s;


    int cnt=0;
    while(cnt++<20)
    {
        bool val = next_permutation(s.begin(), s.end());
        if (val == false)
            cout << "No Word Possible" << endl;
        else
        {
          //  cout<<s<<endl;
            f(t,s);

        }

    }
    return 0;
}

