#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define i64 long long
#define pii pair<int,int>
#define INF 1000000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
#define rep(i,n) for(i64 i=0;i<n;i++)
using namespace std;

vector<pii>vec;

bool compare(pii a, pii b)
{
    if(a.first==b.first)
        return a.second<b.second;
    return a.first<b.first;
}
int main()
{
    int  n,x;
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        vec.push_back({x,i});
    }


    sort(vec.begin(),vec.end(),compare);

    //printf("%d\n",abs(vec[1].second-vec[0].second));


    int mn=INT_MAX;
    for(int i=1;i<vec.size();i++)
    {
        if(vec[i].first==vec[0].first)
        {
            mn=min(mn,abs(vec[i].second-vec[i-1].second));
        }
    }

    cout<<mn<<endl;
}
