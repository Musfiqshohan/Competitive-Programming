#include<bits/stdc++.h>
#include<string.h>
#define ll long long
using namespace std;
ll cost[200000];


ll dp[200000][2];


vector<string> v;
ll f(ll i,ll state) // i mean string of which index and  state means if the previous indexed string was reversed
{

    ll total1=-2, total2=-2,j=0,k;
    string s,s2;

    if(dp[i][state]!=-1) return dp[i][state];

    s=v[i];
    reverse(s.begin(),s.end());

    s2=v[i+1];
    reverse(s2.begin(), s2.end());


    if(i<0) return 0;

    if(state==0) // if the previous indexed string was not reversed
    {
        if( v[i]<=v[i+1] )
            total1=f(i-1,0);  // I will do nothing, state=0

        if( s<= v[i+1] )
        {
            total2= cost[i] + f(i-1,1); // I will reverse it and state=1

        }
    }
    else if(state==1)   // if the previous indexed string was  reversed  since the state=1 , I will compare with the reversed i+1th string
    {
        if( v[i]<=s2 )
            total1=f(i-1,0); // I keep the original no change, state=0

        if( s<=s2 )
        {
            total2= cost[i] + f(i-1,1); // I reverse it state=1

        }

    }


    if(total1<0 && total2<0) return dp[i][state]=INT_MIN;
    else if(total1<0) return dp[i][state]=total2;
    else if(total2<0) return dp[i][state]=total1;


    return dp[i][state]= min(total1,total2);  // return the minimum



}



int main()
{
    memset(dp,-1,sizeof dp);
    ll n,i,total1=INT_MAX,total2=INT_MAX;
    string str;
    scanf("%lld",&n);

    for(i=0; i<n; i++)
        scanf("%lld",&cost[i]);

    for(i=0; i<n; i++)
    {
        cin>>str;
        v.push_back(str);
    }

    total1=f(n-2,0);  // here I didnt reverse the last string

    total2=cost[n-1]+f(n-2,1); // I reversed the last string


    // printed the minimum
    if(total1<0 && total2<0)  printf("-1\n");
    else  if(total1<0) cout<<total2<<endl;
    else if(total2<0) cout<<total1<<endl;
    else cout<<min(total1,total2)<<endl;


    return 0;

}
