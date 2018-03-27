#include<bits/stdc++.h>
#define ms(a,b) memset(a, b , sizeof a);
using namespace std;

struct task
{
    int start, end;
};
vector<task>vec;

bool compare(task a, task b)
{
    if(a.end==b.end)
        return a.start<b.start;
    return a.end<b.end;
}
int main()
{
    int n;
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&u,&v);
        vec.push_back({u,v});
    }

    sort(vec.begin(),vec.end(), compare);


    int endmark=-1;
    for(int i=0;i<vec.size();i++)
    {
        if(vec[i].start>endmark)
        endmark= vec[i].end;

        if(vec[i].end< vec[i].start)


    }


    return 0;
}
