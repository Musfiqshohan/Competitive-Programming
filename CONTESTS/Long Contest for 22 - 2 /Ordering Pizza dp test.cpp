#include<bits/stdc++.h>
#define i64 long long
#define pii pair<i64,i64>
using namespace std;

pair<i64,i64>ara[1000];

struct info
{
    i64 num,p1,p2;
};
vector<info>v1,v2;

bool cmp1(info a, info b)
{
    if(a.p1==b.p1)
        return a.p2<b.p2;
    return a.p1>b.p1;
}

bool cmp2(info a, info b)
{
    if(a.p2==b.p2)
        return a.p1<b.p1;
    return a.p2>b.p2;
}
int main()
{
    i64 n,s,x,y,z;
    scanf("%lld %lld",&n,&s);

    i64 tot=0;
    for(i64 i=0; i<n; i++)
    {
        scanf("%lld %lld %lld",&x,&y,&z);
        if(y>=z)
            v1.push_back({x,y,z});
        else
            v2.push_back({x,y,z});

        tot+=x;
    }

    i64 pizz=(tot+s-1)/s;

    sort(v1.begin(),v1.end(),cmp1);
    sort(v2.begin(),v2.end(),cmp2);



    i64 i=0;
    i64 cnt=0, tot1=0,sum1=0,rem1=0;
    i64 tot2=0,sum2=0,rem2=0, pizz1=0, pizz2=0;

    i64 totPep=0;
    while(i<v1.size())
    {
        if(cnt+v1[i].num>=s)
        {
            i64 dif=s-cnt;
            cnt=0;
            v1[i].num-=dif;
            totPep+=dif;
            tot1+=sum1+dif*v1[i].p1;
            pizz1++;
            sum1=0;
            rem1=0;
            continue;
        }

        cnt+=v1[i].num;
        totPep+=v1[i].num;
        sum1+=v1[i].num*v1[i].p1;
        rem1+=v1[i].num*v1[i].p2;
        i++;
    }


     i=0,cnt=0, tot2=0,sum2=0;
    while(i<v2.size())
    {
        if(cnt+v2[i].num>=s)
        {
            i64 dif=s-cnt;
            cnt=0;
            v2[i].num-=dif;
            totPep+=dif;


            tot2+=sum2+dif*v2[i].p2;
            pizz2++;
            sum2=0;
            rem2=0;
            continue;
        }

        cnt+=v2[i].num;
        totPep+=v2[i].num;
        sum2+=v2[i].num*v2[i].p2;
        rem2+=v2[i].num*v2[i].p1;


      //  pri64f("->%lld %lld %lld cnt=%lld  sum1=%lld\n",v2[i].num, v2[i].p1, v2[i].p2,cnt,sum2);
        //rem1+=v1[i].num*v1[i].p2;
        i++;
    }


    i64 remPep=tot-totPep;

    i64 remPiz=pizz-(pizz1+pizz2); //(remPep+s-1)/s;
    i64 res=0;
    res=tot1+tot2;

   // cout<<sum1<<" "<<sum2<<endl;

    if(remPiz>1){
        res+=sum1;
        res+=sum2;
    }
    else
    {
        if(sum1+rem2>sum2+rem1)
            res+=sum1+rem2;
        else res+=sum2+rem1;

    }
    cout<<res<<endl;



}


/*
2 9

6 1 7

6 7 1
*/
