#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define i64 long long
#define pii pair<int,int>
#define inf 10000000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;


int main()
{
    int tt;
    cin>>tt;
    while(tt--)
    {
        string s,chef;
        chef+="chef";
        sort(chef.begin(),chef.end());
        cin>>s;


        if(s.size()<4)
        {
            printf("normal\n");
            continue;
        }
        int tot=0;


        for(int i=0; i<=s.size()-4; i++)
        {
           // printf("size=%d\n",s.size()-4);
            //cout<<i<<endl;
            string t;
            t+=s[i];
            t+=s[i+1];
            t+=s[i+2];
            t+=s[i+3];
            sort(t.begin(),t.end());

            // cout<<t<<" "<<chef<<endl;
            if(t==chef)
                tot++;
        }

        if(tot)
            cout<<"lovely "<<tot<<endl;
        else cout<<"normal"<<endl;

    }
}
