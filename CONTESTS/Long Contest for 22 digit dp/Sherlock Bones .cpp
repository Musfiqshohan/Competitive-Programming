///https://vjudge.net/contest/212862#problem/J
#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define i64 long long
#define pii pair<i64,i64>
#define inf 100000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
#define rep(i,n) for(i64 i=0;i<n;i++)
#define mod 1000000007
using namespace std;
vector<i64>rbuc,lbuc;

string str;
i64 cum[200009];
void make_rbuc()
{
    for(i64 i=0; i<str.size(); i++)
    {
        if(str[i]=='1')
        {
            i64 cnt=1;
            i++;
            while(i<str.size() && str[i]=='0')
            {
                cnt++;
                i++;
            }
            rbuc.push_back(cnt);
            i--;
        }
    }

    i64 l=rbuc.size();
    for(i64 i=l-1; i>=0; i--)
    {
        cum[i]=rbuc[i];
        if(i<=l-3)
            cum[i]+=cum[i+2];
    }
}


void make_lbuc()
{
    for(i64 i=0; i<str.size(); i++)
    {
        i64 cnt=1;
        while(i<str.size() && str[i]=='0')
        {
            cnt++;
            i++;
        }
        if(str[i]=='1')
            lbuc.push_back(cnt);
    }
}

//void pri64V(vector<i64>vec)
//{
//    for(i64 i=0; i<vec.size(); i++)
//        pri64f("%d ",vec[i]);
//    puts("");
//
//}
int main()
{

    i64 tt;
    cin>>tt;

    while(tt--)
    {
        i64 n;

        cin>>n;
        cin>>str;

        make_lbuc();
        make_rbuc();

//        pri64V(lbuc);
//        pri64V(rbuc);

//        for(i64 i=0; i<rbuc.size(); i++)
//            pri64f("%d ",cum[i]);
//        puts("");

        i64 tot=0;
        for(i64 i=0; i<lbuc.size(); i++)
        {
            tot+= lbuc[i]*cum[i+2];
            //  pri64f("%d = %d %d\n",i, lbuc[i]-1,rbuc[i]-1);
            tot+= (lbuc[i]-1)*(rbuc[i]-1);
        }

        cout<<tot<<endl;

        lbuc.clear();
        rbuc.clear();
        memset(cum,0,sizeof cum);

    }


    return 0;
}

