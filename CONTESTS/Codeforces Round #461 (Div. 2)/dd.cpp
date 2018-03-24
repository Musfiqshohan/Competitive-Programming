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

struct info
{
    int h,s;
    ll self;
    int id;
};

vector<info>vec;


info f(string &str)
{
    int tot=0, ss=0, hh=0;
    ll res=0;
    for(int i=0; i<str.size(); i++)
    {
        if(str[i]=='s')
        {   ss++;
            tot++;
        }
        else
        {   hh++;
            res+=tot;
           // printf("i=%d res=%d tot=%d\n",i,res,tot);
        }
    }

   // printf("%d %d %d\n",hh,ss,tot);
    return {hh,ss,res,0};

}


bool cmp(info a, info b)
{
    int t1= min(a.s,b.h);
    int t2=min(b.s,a.h);

    if(t1==t2)
    {
        if(a.s==b.s)
            return a.h<b.h;
        return a.s>b.s;
    }
    return t1>t2;
}


vector<string>con;
int main()
{

   // string tt="ssshhshhhs";
    //cout<<f(tt).self<<endl;
    int n;
    cin>>n;
    string str;
    for(int i=0; i<n; i++)
    {
        cin>>str;
        con.push_back(str);

        info ret=f(str);
        ret.id=i;
        vec.push_back({ret});
    }


    sort(vec.begin(),vec.end(),cmp);

    str="";

    for(int i=0;i<vec.size();i++)
    {
        str+=con[vec[i].id];
    }

    //cout<<str<<endl;
    cout<<f(str).self<<endl;

    puts("");


    return 0;
}
