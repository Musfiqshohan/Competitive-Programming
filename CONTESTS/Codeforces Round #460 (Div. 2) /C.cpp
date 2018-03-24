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
using namespace std;

string str[2009];
int main()
{
    int n,m,k;
    i64 tot=0;
    cin>>n>>m>>k;
    getchar();
    for(int i=0; i<n; i++)
        cin>>str[i];

    if(k==1)
    {
        for(int i=0; i<n; i++)
            for(int j=0; j<str[i].size(); j++)
                if(str[i][j]=='.')
                    tot++;

        printf("%lld\n",tot);
        return 0;
    }


    for(int i=0; i<n; i++)
    {
        int cnt=0;
        for(int j=0; j<str[i].size()-1; j++)
        {
            if(str[i][j]=='.' && str[i][j+1]=='.')
                cnt++;
            else
            {
                //printf("cnt=%d\n",cnt);
                if(cnt-k+2>=0)
                {
                    tot+=cnt-k+2;
                }
                cnt=0;
            }
        }

        //cout<<cnt<<endl;
        if(cnt-k+2>=0)
            tot+=cnt-k+2;
    }


    for(int i=0; i<m; i++)
    {
        int cnt=0;
        for(int j=0; j<n-1; j++)
        {
            if(str[j][i]=='.' && str[j+1][i]=='.')
                cnt++;
            else
            {
                if(cnt-k+2>=0)
                {
                    tot+=cnt-k+2;
                }
                cnt=0;
            }
        }

        //  cout<<cnt<<endl;
        if(cnt-k+2>=0)
            tot+=cnt-k+2;
    }


    cout<<tot<<endl;

}
