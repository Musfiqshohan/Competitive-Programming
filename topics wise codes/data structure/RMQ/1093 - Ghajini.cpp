#include<bits/stdc++.h>
using namespace std;

deque< pair< int, int> >dq1;
deque<  pair< int, int> >dq2;
int a[100090];
int main()
{
    int t=0,test;

    scanf("%d",&test);

    while(t<test){
    int n,d,mx=0,i;
    scanf("%d %d",&n,&d);

    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    for(i=0;i<n;i++)
    {
        while(dq1.empty()==false && a[i] < dq1.front().first)
            dq1.pop_front();

        dq1.push_front({a[i],i});

        if( dq1.back().second< i-d+1)
            dq1.pop_back();


        while(dq2.empty()==false && a[i] > dq2.front().first)
            dq2.pop_front();

        dq2.push_front({a[i],i});

        if(dq2.back().second < i-d+1)
            dq2.pop_back();


        if(i>=d-1)
            mx= max(mx,  abs(dq2.back().first-dq1.back().first));
    }

    printf("Case %d: %d\n",++t,mx);

    dq1.clear();
    dq2.clear();

    }
    return 0;
}
