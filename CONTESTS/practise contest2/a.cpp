#include<bits/stdc++.h>
#define i64 long long
#define inf 1000000000000000000
using namespace std;
i64 ara[1500], cum[1600];
string str,str2;

const i64 mod1=1001001009;
const i64 mod2=1002001009;
map<pair<i64,i64>,i64>mp;



int main()
{

    i64 k;
    cin>>str;
    cin>>str2;
    cin>>k;

   // cout<<str<<" "<<str2<<" "<<k;

    for(i64 i=0; i<str2.size(); i++)
    {
        ara[i]=(str2[i]-'0')^1;
    }


    i64 tot=0, p1=0,p2=0,d1=256, d2=265, bad=0;

    for(i64 i=0; i<str.size(); i++)
    {
        p1=0;
        p2=0;
        bad=0;
        for(i64 j=i; j<str.size(); j++)
        {

            if(ara[str[j]-'a'] ==1)
                bad++;

            if(bad<=k)
            {

               // printf("->%lld\n",cum[j]-cum[i]+ara[str[i]-'a']);
                p1=((d1*p1)+ str[j])%mod1;
                p2=((d2*p2)+ str[j])%mod2;

                if(mp.find({p1,p2})==mp.end())
                {
                    tot++;
                    mp[{p1,p2}]=1;
                }
            }
        }
    }

    cout<<tot<<endl;


}
