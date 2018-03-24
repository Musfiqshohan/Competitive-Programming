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
    for(i64 i=0;i<vec.size();i++)
    {
        printf("%lld %lld\n",vec[i].first,vec[i].second);
        if(vec[i].first<=T && T<=vec[i].second)
            tot+=ara[i];
    }
    return tot;
}


int main()
{
    i64 n,ss,ff;
    cin>>n;
    for(i64 i=0;i<n;i++)
        cin>>ara[i];

    cin>>ss>>ff;
    ff--;

    for(i64 i=0;i<n;i++)
        vec.push_back({ss+i,ff+i});


    cout<<f(8)<<endl;

//    for(int i=0;i<=100;i++)
//    {
//        printf("%lld ->%lld\n",i,f(i));
//    }


//
//    i64 low=1,high=1000000000000, mid1,mid2,cnt=0,res=0;
//
//    while(cnt++<100)
//    {
//        mid1=(low+high)/2;
//        mid2=mid1+1;
//
//        i64 t1=f(mid1);
//        i64 t2=f(mid2);
//
//      //  printf("%lld->%lld %lld->%lld\n",mid1,f(mid1),mid2, f(mid2));
//
//        if(t1<t2)
//            low=mid1;
//        else high=mid2;
//    }
//
//    if(f(mid1)>f(mid2))
//        res=mid1;
//    else res=mid2;
//    cout<<res<<endl;




}
