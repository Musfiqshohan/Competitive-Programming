///https://www.codechef.com/FEB18/problems/PERMPAL
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


vector<int>vec[30],v1,v2;
string s1,s2,str;

void clearr()
{
    for(int i=0; i<=26; i++)
        vec[i].clear();

    v1.clear();
    v2.clear();

}

void add(int id, int st, int l, int flag)
{
    if(flag==1)
    {
        for(int i=st; i<st+l; i++)
        {
            v1.push_back(vec[id][i]);
            s1+=(id+'a');
        }
    }
    else
    {
        for(int i=st; i<st+l; i++)
        {
            v2.push_back(vec[id][i]);
            s2+=(id+'a');
        }
    }
}


void print_vector(vector<int>v)
{
    for(int i=0; i<v.size(); i++)
        printf("%d ",v[i]);
    puts("");
}

void print_res()
{
    reverse(s2.begin(),s2.end());
    reverse(v2.begin(),v2.end());

    string res=s2+s1;

    vector<int>ret;
    ret.reserve(v1.size()+v2.size());
    ret.insert(ret.end(), v2.begin(), v2.end());
    ret.insert(ret.end(), v1.begin(), v1.end());


    for(int i=0; i<ret.size(); i++)
    {
        if(i) printf(" ");
        printf("%d",ret[i]);
    }
    puts("");

//    for(int i=0; i<ret.size(); i++)
//        printf("%c",str[ret[i]-1]);
//    puts("");

    ret.clear();


}

int main()
{
    int tt;
    cin>>tt;

    while(tt--)
    {

        cin>>str;

        for(int  i=0; i<str.size(); i++)
        {
            vec[str[i]-'a'].push_back(i+1);
        }


        int odd=0, markid=-1;
        for(int i=0; i<26; i++)
        {
            if(vec[i].size()%2==1)
            {
                odd++;
                markid=i;
            }
        }

        if(odd>1)
            printf("-1\n");

        else
        {
            if(markid!=-1)
                add(markid,0,vec[markid].size(), 1);


            for(int i=0; i<26; i++)
            {
                if(i==markid || vec[i].size()==0) continue;
                int l=vec[i].size();
                add(i, 0, l/2, 1);
                add(i, l/2, l/2, 2);
            }

            print_res();
        }


        clearr();


    }


    return 0;
}
