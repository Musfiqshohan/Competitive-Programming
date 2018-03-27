#include<bits/stdc++.h>
#define  ms(a,b) memset(a,b,sizeof a);
#define mod  1000000
#define ll long long
using namespace std;

pair<int,int>mat[109];

int f(int i, int j)
{
    if(i==j)
    {
        return 0;
    }


    int mn=INT_MAX,res=0;
    for(int k=i;k<j;k++)
    {
        res= f(i,k) + f(k+1,j)  + mat[i].first*mat[k].second*mat[j].second;

        mn= min(mn,res);
    }

    return mn;
}
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&mat[i].first, &mat[i].second);
    }

    cout<<f(0,n-1)<<endl;

    return 0;
}
