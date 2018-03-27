#include<bits/stdc++.h>
using namespace std;
int t,w,n;

struct data
{
    int depth,gold,pos;
};

vector<data>v;
vector<data>res;
int dir[60];
int dp[60][500];
int f(int index, int air)
{
    int mx=0,total=0;
    if(dp[index][air]!=-1) return dp[index][air];

    for(int i=index+1; i<v.size(); i++)
    {
        int rem= air- 3*w*v[i].depth;
        if(rem>=0)
        {
            total=f(i,rem);

            if(total>mx)
            {
                mx=total;

                dir[index]=i;           /// here saved the pos
            }
        }

    }

    return dp[index][air]=mx+v[index].gold;
}

bool compare1(data a, data b)           /// for sorting according to depth
{
    if(a.depth==b.depth)
    {
        if(a.gold==b.gold)
            return a.pos<b.pos;
        else   return a.gold>b.gold;
    }
    return a.depth<b.depth;
}
bool compare2(data a, data b)       ///for sorting according to index
{
    return a.pos<b.pos;
}

int main()
{

    scanf("%d %d %d",&t,&w,&n);

    memset(dir,-1,sizeof dir);
    memset(dp,-1,sizeof dp);
    int i,total=0;

    for(i=0; i<n; i++)
    {
        data p;
        scanf("%d %d",&p.depth,&p.gold);
        p.pos=i;

        v.push_back(p);
    }

    sort(v.begin(), v.end(), compare1);


    int mx=0,start=0;
    for(i=0; i<v.size(); i++)
    {
        int rem= t- 3*w*v[i].depth;

        if(rem>=0)
        {
            total=f(i,rem);

            if(total>mx)
            {
                mx=total;
                start=i;
            }
        }
    }


    while(dir[start]!=-1)   ///for printing dp solution
    {
        //printf("%d->%d\n",start,v[start].gold);
        res.push_back(v[start]);
        start=dir[start];
    }

    // printf("%d->%d\n",start,v[start].gold);

    res.push_back(v[start]);

    sort(res.begin(), res.end(), compare2);

    printf("%d\n",mx);
    printf("%d\n",res.size());
    for(i=0; i<res.size(); i++)
    {
        printf("%d %d\n",res[i].depth, res[i].gold);
    }

    v.clear();
    res.clear();


    return 0;
}

/*
input:
604 3
6
15 83
10 45
14 99
7 73
19 88
16 57

Correct output:
388
5
15 83
10 45
14 99
7 73
19 88

My output:
388
5
15 83
10 45
14 99
7 73
19 88
16 57
*/







