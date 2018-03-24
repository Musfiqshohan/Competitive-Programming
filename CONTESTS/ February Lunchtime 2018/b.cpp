///https://www.codechef.com/LTIME57/problems/GAMENUMB
#include<bits/stdc++.h>
#define pb push_back
#define ms(a,b) memset((a),(b),sizeof(a))
#define i64 long long
#define pii pair<i64,i64>
#define inf 100000000000
using namespace std;

i64 cumF[100009],cumB[100009],b[100009];

struct info
{
    i64 a,d;
} ara[100009];


i64 SrchL(i64 st, i64 en, i64 num)
{

    num+=cumB[en+1];

    i64 high=en, low=st, mid,cnt=32;

    while(cnt--)
    {
        mid=(low+high)/2;

        if(cumB[mid]>num)
            low=mid;
        else high=mid;
    }

    if(cumB[mid]>num && cumB[mid+1]>=num)
        mid++;

    cumF[mid-1]+=cumB[mid]-num;
    ara[mid].d-=cumB[mid]-num;

    cumB[mid]=num;

    return mid;
}

i64 SrchR(i64 st, i64 en, i64 num)
{
    num+=cumF[st-1];
    i64 high=en, low=st, mid,cnt=32;

    while(cnt--)
    {
        mid= (low+high)/2;
        if(cumF[mid]>num)
            high=mid;
        else
            low=mid;
    }

    if(cumF[mid]<num)
        mid++;

   // printf("num=%d mid=%d\n",num,mid);

    cumB[mid+1]+= cumF[mid]-num;
    ara[mid].d-=cumF[mid]-num;
    cumF[mid]=num;

    return mid;
}

bool cmp(info x, info y)
{
    if(x.a==y.a)
        return x.d<y.d;
    return x.a<y.a;
}

int main()
{
    i64 tt;
    cin>>tt;

    while(tt--)
    {

        i64 n,k;
        cin>>n>>k;

        for(i64 i=1; i<=n; i++)
        {
            scanf("%lld",&ara[i].a);
        }

        for(i64 i=1; i<=n; i++)
        {
            scanf("%lld",&ara[i].d);
        }

        sort(ara+1,ara+n+1,cmp);

        for(i64 i=1; i<=n; i++)
        {
            cumF[i]=cumF[i-1]+ara[i].d;
        }


        for(i64 i=n+1; i>=1; i--)
        {
            cumB[i]=cumB[i+1]+ara[i].d;
        }

        for(i64 i=1; i<=k; i++)
            scanf("%lld",&b[i]);

        ///all okay till now

        i64 st=1,en=n;
        for(i64 i=1; i<=k; i++)
        {
            if(i&1)
            {
                st=SrchL(st,en,b[i]);
            }
            else
            {
                en=SrchR(st,en,b[i]);
            }

           // printf("st=%lld en=%lld %lld\n",st,en,b[i]);

        }

        i64 tot=0;
        for(i64 i=st; i<=en; i++){
            tot+=ara[i].a*ara[i].d;
        }

        cout<<tot<<endl;

        ms(cumF,0);
        ms(cumB,0);
        ms(ara,0);

    }
    return 0;

}


