///https://vjudge.net/contest/212042#problem/F
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

map<int,int>mp;
int a[100009];

vector<pii>vec;
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    for(int i=0;i<n;i++)
    {
        int tot=0;
        while(a[i]==a[i])
        {
            i++;
            tot++;
        }
        vec.push_back({i,tot});
    }

    for(int i=vec.size()-1;i>=0;i--)
    {
        cum[i]=++mp[vec[i].first];
    }


    int cont=0, totF=0;
    for(int i=0;i<vec.size();i++)
    {
        if(isThere[vec[i]]==1)
            continue;

        if(cont<k)
        {
            isThere[vec[i]]=1;
            cont++;
            totF++;
        }
        else
        {

        }

    }














    return 0;
}
