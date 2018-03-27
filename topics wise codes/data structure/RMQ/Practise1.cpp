#include<bits/stdc++.h>
using namespace std;
pair<int, int> p;
deque<pair<int, int>> dq;

deque<int> ::iterator it;
int a[1000];
int main()
{

    int n,i,m;

    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++) scanf("%d",&a[i]);



    for(i=0;i<n;i++)
    {
        while(dq.empty()==false &&  a[i]<dq.front().first)
        dq.pop_front();

        dq.push_front({a[i],i});

        if(dq.back().second < i-m+1)
            dq.pop_back();



        if(i>1)
        printf("%d %d\n",dq.back().first, dq.back().second);

    }



    return 0;
}
