#include<bits/stdc++.h>
#define ms(a,b) memset(a, b , sizeof a);
using namespace std;
struct task
{
    int start, end;
} ara[50009];

int mark[100009];

map<int,int>mp;
vector<int>vec;
int main()
{
    int tt=0,test;
    cin>>test;

    while(tt<test)
    {

        int n,u,v;
        scanf("%d",&n);

        for(int i=0; i<n; i++)
        {
            scanf("%d %d",&u,&v);

            v++;
            ara[i]= {u,v};

            vec.push_back(u);
            vec.push_back(v);
        }

        sort(vec.begin(), vec.end());


        int cnt=0;
        for(int i=0; i<vec.size(); i++)
        {
            int x= vec[i];

            if(mp.find(x)==mp.end())
            {
                mp[x]=++cnt;
            }

        }

        for(int i=0; i<n; i++)
        {
            int start= mp[ara[i].start];
            int end= mp[ara[i].end];

            //printf("%d %d -> %d %d\n",ara[i].start, ara[i].end, start,end);
            mark[start]++;
            mark[end]--;
        }

        int mx=0,tot=0;
        for(int i=0; i<=cnt; i++)
        {
            //printf("%d %d\n",i,mark[i]);
            tot+=mark[i];

            mx= max(mx,tot);
        }

        printf("Case %d: %d\n",++tt, mx);
        vec.clear();
        mp.clear();
        ms(mark,0);
        ms(ara,0);
    }

}
