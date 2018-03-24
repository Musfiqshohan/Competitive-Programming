#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
//#define clear(v,n) for(_typeof (n) i=0;i< (n) ; i++)  { v.clear(); }
#define ll long long
#define pii pair<ll,ll>
#define inf 100000000
#define in(a) freopen(a,"r", stdin)
#define out(a) freopen(a,"w",stdout)
using namespace std;

vector<pii>vec,vec2;
vector<int>ara;

bool compare(pii a, pii b)
{
    return a.first<b.first;
}

bool compare2(pii a, pii b)
{
    return a.second<b.second;
}
int main()
{
    int m,x;
    scanf("%d",&m);

    for(int i=0; i<m; i++)
    {
        scanf("%d",&x);
        ara.push_back(x);
    }
    for(int i=0; i<m; i++)
    {
        scanf("%d",&x);
        vec.push_back({x,i});
    }

    sort(ara.begin(), ara.end(),greater<int>());

    sort(vec.begin(), vec.end(), compare);


    for(int i=0; i<m; i++)
    {
        //printf("%d %d\n",ara[i], vec[i].first);
        vec2.push_back({ara[i],vec[i].second});

    }

    sort(vec2.begin(), vec2.end(), compare2);

    for(int i=0; i<vec2.size(); i++)
        printf("%d ",vec2[i]);

    puts("");
    return 0;
}
