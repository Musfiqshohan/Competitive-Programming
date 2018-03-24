#include<bits/stdc++.h>
#define ms(a,b) memset((a),(b),sizeof(a))
#define i64 long long
#define pii pair<i64,i64>
#define inf 1000000000000000000

using namespace std;

vector<pii>vec;
i64 ara[100009];

i64 f(i64 T)
{
    i64 tot=0;
    for(i64 i=0; i<vec.size(); i++)
    {
        if(vec[i].first<=T && T<=vec[i].second)
            tot+=ara[i];
    }
    return tot;
}


int main()
{
    i64 n,ss,ff;
    cin>>n;
    for(i64 i=0; i<n; i++)
        cin>>ara[i];

    cin>>ss>>ff;
    ff--;

    for(i64 i=0; i<n; i++)
        vec.push_back({ss+i,ff+i});



    i64 low=1,high=n, mid=0,cnt=0,res=0,t1,t2;

    while(cnt++<100)
    {
        mid = (high + low)>>1;
        t1=f(mid);
        t2=f(mid+1);
        if(t1<t2)
            low=mid;
        else high=mid+1;

    }

    while(f(mid+1)>f(mid) && mid+1<=n)
        mid++;

    while(f(mid-1)==f(mid) && mid-1>0)
        mid--;

    res=mid;
    //else res=mid;
    cout<<res<<endl;


}
