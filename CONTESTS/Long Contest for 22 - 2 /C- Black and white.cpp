///https://vjudge.net/contest/212042#problem/C
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

int main()
{
    int tt;
    cin>>tt;
    while(tt--)
    {
        string str;

        cin>>str;


        int l=str.size();
        if(str[0]=='W' || str[l-1]=='B')
        {
            printf("IMPOSSIBLE\n");
            continue;
        }


        vector<int>v1,v2;

        int mx1=0,mx2=0,mn1=1000000,mn2=1000000;

        for(int i=0; i<l; i++)
        {


            if(str[i]=='B')
            {
                mx1=max(mx1,i);
                mn1=min(mn1,i);
                if(i>0)
                    v1.push_back(i+1);
                else v2.push_back(i+1);
            }

            if(str[i]=='W')
            {
                mx2=max(mx2,i);
                mn2=min(mn2,i);
                if(i<l-1)
                    v2.push_back(i+1);
                else v1.push_back(i+1);
            }
        }


       // cout<<mx1<<" "<<mn1<<" "<<mx2<<" "<<mn2<<endl;


        if(v1.size()==1 || v2.size()==1 || mx1<mn2 || mx2<mn1)
        {
            printf("1\n");
            printf("%d",l);
            for(int i=1; i<=l; i++)
                printf(" %d",i);
            puts("");
        }
        else
        {
            printf("2\n");
            printf("%d",v2.size());
            for(int i=0; i<v2.size(); i++)
                printf(" %d",v2[i]);

            puts("");
            printf("%d",v1.size());
            for(int i=0; i<v1.size(); i++)
                printf(" %d",v1[i]);
            puts("");
        }
        v1.clear();
        v2.clear();

    }

}


