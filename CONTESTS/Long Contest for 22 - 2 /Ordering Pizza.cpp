#include<bits/stdc++.h>
#define i64 long long
#define pii pair<i64,i64>
using namespace std;

pair<i64,i64>ara[1000];

struct info
{
    int num,p1,p2;
};
vector<info>v1,v2,vec;

bool cmp(info a, info b)
{
    if(a.p1-a.p2==b.p1-b.p2)
        return a.p2<b.p2;
    return a.p1-a.p2>b.p1-b.p2;
}


int f(int slc, int rem)
{

    int i=0,tot=0;
    while(slc)
    {
        if(slc-vec[i].num>=0)
        {
            tot+=vec[i].p1*vec[i].num;
            slc-=vec[i].num;
            printf("%d %d\n",slc,vec[i].num);
        }
        else
        {
           // puts("hh");
            int temp=vec[i].num;
            tot+=vec[i].p1* min(slc,vec[i].num);
            tot+=vec[i].p2* vec[i].num-slc;
            rem-=(vec[i].num-slc);
            i++;
            break;
        }
        i++;
        if(i==vec.size()) break;
        cout<<i<<endl;
    }

    while(rem)
    {
        tot+=vec[i].p2*vec[i].num;
        rem-=vec[i].num;
        i++;
        if(i==vec.size()) break;
    }

    return tot;
}


int main()
{


    int n,s,x,y,z;
    cin>>n>>s;

    int tot=0;

    for(int i=0;i<n;i++)
    {
        scanf("%d %d %d",&x,&y,&z);
        vec.push_back({x,y,x});
        tot+=x;
    }

    sort(vec.begin(),vec.end(),cmp);

    int pizz=(tot+s-1)/s;
    int low=0 ,high=pizz*s, mid1,mid2;

    int cnt=0;
    while(cnt++<32)
    {
        int mid1=(low+high)/2;
        int mid2=mid1+1;

        if(f(mid1,pizz*s- mid1)>f(mid2,pizz*s-mid2))
            high=mid2;
        else low=mid1;
    }

    cout<<f(mid1,pizz*s-mid1)<<" "<<f(mid2,pizz*s-mid2)<<endl;










}


/*
2 9

6 1 7

6 7 1
*/

