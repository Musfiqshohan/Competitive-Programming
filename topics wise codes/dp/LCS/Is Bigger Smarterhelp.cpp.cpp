#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;
struct data
{
    int ind,weight,iq;
};
data ar[1005];
bool cmp(data a,data b)
{
    if(a.weight == b.weight && a.iq==b.iq)return a.ind < b.ind;
    if(a.weight == b.weight)return a.iq > b.iq; //strictly increasing
    return a.weight < b.weight; //strictly decreasing
}

int dp[1005],dir[1005];
int LIS(int u,int n)
{
    if(dp[u]!=-1)return dp[u];
    int mx=0;
    for(int v=u+1;v<n;v++)
    {
        if(ar[v].iq < ar[u].iq && ar[v].weight > ar[u].weight)
        {
            int temp=LIS(v,n);
            if(temp>mx)
            {
                mx=temp;
                dir[u]=v;
            }
        }
    }
    dp[u]=mx+1;
    return dp[u];
}
int main()
{
    int n=0,w,iq;
    freopen("input.txt","r",stdin);
    freopen("output2.txt","w",stdout);

    while(scanf("%d %d",&ar[n].weight,&ar[n].iq)==2)
    {
        ar[n].ind=n+1;
        n++;
    }
    sort(ar,ar+n,cmp);
    //for(int i=0;i<n;i++)printf("%d %d %d\n",ar[i].weight,ar[i].iq,ar[i].ind);
    memset(dp,-1,sizeof(dp));
    memset(dir,-1,sizeof(dir));
    //for(int i=0;i<=n;i++)dp[i]=dir[i]=-1;
    int mx=0,start;
    for(int i=0;i<n;i++)
    {
        int temp=LIS(i,n);
        //printf("long path from %d : %d\n",i,temp);
        if(temp > mx){
        mx=temp;
        start=i;
        }
    }
    printf("%d\n",mx);
    while(1)
    {
        printf("%d\n",ar[start].ind);
        start=dir[start];
        if(start==-1)break;
    }
    return 0;
}
