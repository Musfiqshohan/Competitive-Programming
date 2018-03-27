#include<bits/stdc++.h>
using namespace std;

struct data
{
    int w,iq,i;
};
vector<data>v;

bool compare(data a, data b)
{
    if(a.w==b.w && a.iq==b.iq) return a.i<b.i;
    if(a.w==b.w)
        return a.iq>b.iq;
    return a.w<b.w;
}
int dp[2000];
int dir[2000];
int n;
int LIS(int u)
{
    if(dp[u]!=-1) return dp[u];
    int mx=0;
    for(int i=u+1; i<n; i++)
    {

        if(v[u].iq>v[i].iq && v[u].w<v[i].w)
        {


            if(LIS(i)>mx  )
            {

                mx=LIS(i);

                dir[u]=i;
            }
        }
    }

    return dp[u]=mx+1;

}

void printLIS(int i)
{

    if(dir[i]==-1)
    {
        printf("%d\n",v[i].i+1);

        return ;

    }

    printf("%d\n",v[i].i+1);
    printLIS(dir[i]);



}
int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output1.txt","w",stdout);
    data temp;
    int i,x,y;

    while(scanf("%d %d",&x,&y)!=EOF)
    {

        temp.w=x;
        temp.iq=y;
        temp.i=n;
        v.push_back(temp);

        n++;
    }

    sort(v.begin(), v.end(), compare);


    memset(dp,-1,sizeof dp);
    memset(dir,-1,sizeof dir);

    int mx=0,start=0;
    for(i=0; i<n; i++)
    {

        if(LIS(i)>mx)
        {
            mx=LIS(i);
            start=i;
        }
    }

    printf("%d\n",mx);
    printLIS(start);

    return 0;
}
