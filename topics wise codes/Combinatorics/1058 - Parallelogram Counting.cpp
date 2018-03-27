#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[1009][1009];

ll nCr(ll n,ll r)
{
    if(n<r) return 0;
    if(n==r) return 1;
    if(r==0) return 1;

    if(dp[n][r]!=-1) return dp[n][r];
    return dp[n][r]= nCr(n-1,r) + nCr(n-1,r-1);

}

bool compare(pair< double , double >a, pair< double , double > b)
{
    if(a.first==b.first) return a.second<b.second;
    return a.first<b.first;
}
int main()
{
    memset(dp,-1,sizeof(dp));

    pair< double , double > p[1009];
    pair< double , double > point;

    vector< pair< double , double > > v;

    int t,test;
    scanf("%d",&test);
    for(t=0;t<test;t++){
    ll n,i,total=0,j;
    scanf("%lld",&n);
    for(i=0;i<n;i++)
        cin>>p[i].first>>p[i].second;

     int k=0;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
           point.first=(p[i].first+ p[j].first)/2;
           point.second=(p[i].second+ p[j].second)/2;

           v.push_back(point);
           k++;
        }
    }

    sort(v.begin(), v.end(), compare );


    int cnt;
    for(i=0;i<v.size();i++){

        cnt=1;
        while(v[i].first==v[i+1].first && v[i].second==v[i+1].second) { i++;  cnt++; }
        total+=nCr(cnt,2);

    }


    printf("Case %d: ",t+1);
    cout<<total<<endl;
    v.clear();


    }
    return 0;
}
